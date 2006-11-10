// $Id$

#include "ace/Service_Config.h"

#if !defined (__ACE_INLINE__)
#include "ace/Service_Config.inl"
#endif /* __ACE_INLINE__ */

#include "ace/ACE.h"
#include "ace/Guard_T.h"
#include "ace/Log_Msg.h"
#include "ace/Service_Types.h"
#include "ace/Reactor.h"

#ifndef ACE_LACKS_UNIX_SIGNALS
# include "ace/Sig_Adapter.h"
#endif  /* !ACE_LACKS_UNIX_SIGNALS */

#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_time.h"
#include "ace/OS_NS_unistd.h"
#include "ace/Get_Opt.h"
#include "ace/ARGV.h"

ACE_RCSID (ace,
           Service_Config,
           "$Id$")

  ACE_BEGIN_VERSIONED_NAMESPACE_DECL

///
ACE_Service_Config_Guard::ACE_Service_Config_Guard (ACE_Service_Gestalt * psg)
  : saved_ (ACE_Service_Config::current ())
{
  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_LIB_TEXT ("(%P|%t) SCG::ctor, repo=%@ - guard with %@\n"),
                this->saved_->repo_,
                psg->repo_));

  // Modify the TSS - no locking needed
  if (saved_ != psg)
      (void)ACE_Service_Config::current (psg);
}

///
ACE_Service_Config_Guard::~ACE_Service_Config_Guard (void)
{
  ACE_Service_Config::current (this->saved_);

  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_LIB_TEXT ("(%P|%t) SCG::dtor, repo=%@ - un-guard\n"),
                this->saved_->repo_));
}


ACE_ALLOC_HOOK_DEFINE (ACE_Service_Config)

// Set the signal handler to point to the handle_signal() function.
ACE_Sig_Adapter *ACE_Service_Config::signal_handler_ = 0;

// Trigger a reconfiguration.
sig_atomic_t ACE_Service_Config::reconfig_occurred_ = 0;

// = Set by command-line options.

/// Pathname of file to write process id.
ACE_TCHAR *ACE_Service_Config::pid_file_name_ = 0;

/// Shall we become a daemon process?
int ACE_Service_Config::be_a_daemon_ = 0;

// Number of the signal used to trigger reconfiguration.
int ACE_Service_Config::signum_ = SIGHUP;


void
ACE_Service_Config::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Service_Config::dump");
#endif /* ACE_HAS_DUMP */
}

int
ACE_Service_Config::parse_args_i (int argc, ACE_TCHAR *argv[])
{
  ACE_TRACE ("ACE_Service_Config::parse_args_i");

  // Using PERMUTE_ARGS (default) in order to have all
  // unrecognized options and their value arguments moved
  // to the end of the argument vector. We'll pick them up
  // after processing our options and pass them on to the
  // base class for further parsing.
  ACE_Get_Opt getopt (argc,
                      argv,
                      ACE_LIB_TEXT ("bs:p:"),
                      1  ,                       // Start at argv[1].
                      0,                       // Do not report errors
                      ACE_Get_Opt::RETURN_IN_ORDER);

  // Keep a list of all unknown arguments, begin with the
  // executable's name
  ACE_ARGV superargv;
  superargv.add (argv[0]);

  for (int c; (c = getopt ()) != -1; )
    switch (c)
      {
      case 'p':
        ACE_Service_Config::pid_file_name_ = getopt.opt_arg ();
        break;
      case 'b':
        ACE_Service_Config::be_a_daemon_ = 1;
        break;
      case 's':
        {
          // There's no point in dealing with this on NT since it
          // doesn't really support signals very well...
#if !defined (ACE_LACKS_UNIX_SIGNALS)
          ACE_Service_Config::signum_ =
            ACE_OS::atoi (getopt.opt_arg ());

          if (ACE_Reactor::instance ()->register_handler
              (ACE_Service_Config::signum_,
               ACE_Service_Config::signal_handler_) == -1)
            ACE_ERROR_RETURN ((LM_ERROR,
                               ACE_LIB_TEXT ("cannot obtain signal handler\n")),
                              -1);
#endif /* ACE_LACKS_UNIX_SIGNALS */
          break;
      default:
          superargv.add ( argv[getopt.opt_ind () - 1]);
        }
      }

  // Collect any argumets that were left
  for (int c = getopt.opt_ind (); c < argc; c++)
      superargv.add (argv[c-1]);

  return ACE_Service_Gestalt::parse_args_i (superargv.argc (),
                                            superargv.argv ());

} /* parse_args_i () */


int
ACE_Service_Config::open_i (const ACE_TCHAR program_name[],
                            const ACE_TCHAR *logger_key,
                            bool ignore_static_svcs,
                            bool ignore_default_svc_conf_file,
                            bool ignore_debug_flag)
{
  int result = 0;
  ACE_TRACE ("ACE_Service_Config::open_i");
  ACE_Log_Msg *log_msg = ACE_LOG_MSG;

  if (ACE::debug ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) SC::open_i - this=%@, opened=%d, ")
                ACE_TEXT ("loadstatics=%d\n"),
                this, this->is_opened_, this->no_static_svcs_));

  // Guard against reentrant processing. For example,
  // if the singleton gestalt (ubergestalt) was already open,
  // do not open it again...
  // The base class open_i increments this and we are
  // forwarding to it, so we don't have to increment here.
  if (this->is_opened_ != 0)
    return 0;

  // Check for things we need to do on a per-process basis and which
  // may not be safe, or wise to do an a per instance basis

  // Override any defaults, if required
  this->no_static_svcs_ = ignore_static_svcs;

  // Become a daemon before doing anything else.
  if (this->be_a_daemon_)
    ACE::daemonize ();

  // Write process id to file.
  if (this->pid_file_name_ != 0)
    {
      FILE* pidf = ACE_OS::fopen (this->pid_file_name_,
                                  ACE_LIB_TEXT("w"));

      if (pidf != 0)
        {
          ACE_OS::fprintf (pidf,
                           "%ld\n",
                           static_cast<long> (ACE_OS::getpid()));
          ACE_OS::fclose (pidf);
        }
    }

  u_long flags = log_msg->flags ();

  // Only use STDERR if the caller hasn't already set the flags.
  if (flags == 0)
    flags = (u_long) ACE_Log_Msg::STDERR;

  const ACE_TCHAR *key = logger_key;

  if (key == 0 || ACE_OS::strcmp (key, ACE_DEFAULT_LOGGER_KEY) == 0)
    // Only use the static <logger_key_> if the caller doesn't
    // override it in the parameter list or if the key supplied is
    // equal to the default static logger key.
    key = this->logger_key_;
  else
    ACE_SET_BITS (flags, ACE_Log_Msg::LOGGER);

  if (log_msg->open (program_name,
                     flags,
                     key) == -1)
    result = -1;
  else
    {
      if (ACE::debug ())
        ACE_DEBUG ((LM_STARTUP,
                    ACE_LIB_TEXT ("starting up daemon %n\n")));

      // Initialize the Service Repository (this will still work if
      // user forgets to define an object of type ACE_Service_Config).
      ACE_Service_Repository::instance (ACE_Service_Config::MAX_SERVICES);

      // Initialize the ACE_Reactor (the ACE_Reactor should be the
      // same size as the ACE_Service_Repository).
      ACE_Reactor::instance ();

      // There's no point in dealing with this on NT since it doesn't
      // really support signals very well...
#if !defined (ACE_LACKS_UNIX_SIGNALS)
      // Only attempt to register a signal handler for positive
      // signal numbers.
      if (ACE_Service_Config::signum_ > 0)
        {
          ACE_Sig_Set ss;
          ss.sig_add (ACE_Service_Config::signum_);
          if (ACE_Reactor::instance ()->register_handler
              (ss, ACE_Service_Config::signal_handler_) == -1)
            ACE_ERROR ((LM_ERROR,
                        ACE_LIB_TEXT ("can't register signal handler\n")));
        }
#endif /* ACE_LACKS_UNIX_SIGNALS */
    }

  if (result == -1)
    return -1;

  if (this->init_svc_conf_file_queue () == -1)
    return -1;

  // Check if the default file exists before attempting to queue it
  // for processing
  if (!ignore_default_svc_conf_file)
    {
      FILE *fp = ACE_OS::fopen (ACE_DEFAULT_SVC_CONF,
                                ACE_LIB_TEXT ("r"));
      ignore_default_svc_conf_file = (fp == 0);
      if (fp != 0)
        ACE_OS::fclose (fp);
    }

  if (!ignore_default_svc_conf_file
      && this->svc_conf_file_queue_->is_empty ())
    {
      // Load the default "svc.conf" entry here if there weren't
      // overriding -f arguments in <parse_args>.
      if (this->svc_conf_file_queue_->enqueue_tail
          (ACE_TString (ACE_DEFAULT_SVC_CONF)) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_LIB_TEXT ("%p\n"),
                             ACE_LIB_TEXT ("enqueuing ")
                             ACE_DEFAULT_SVC_CONF
                             ACE_LIB_TEXT(" file")),
                            -1);
        }
    }

  return ACE_Service_Gestalt::open_i (program_name,
                                      logger_key,
                                      ignore_static_svcs,
                                      ignore_default_svc_conf_file,
                                      ignore_debug_flag);
}

/// Return the global configuration instance. Allways returns the same
/// instance
ACE_Service_Gestalt *
ACE_Service_Config::global (void)
{
  return ACE_Singleton<ACE_Service_Config, ACE_SYNCH_MUTEX>::instance ();
}


///
ACE_Service_Gestalt *
ACE_Service_Config::instance (void)
{
  return  ACE_Service_Config::current ();
}


// A thread-specific storage to keep a pointer to the (current) global
// configuration. Using a pointer to avoid the order of initialization
// debacle possible when using static class instances. The memory is
// dynamicaly allocated and leaked from current()

/// Provides access to the static ptr, containing the TSS
/// accessor. Ensures the desired order of initialization, even when
/// other static initializers need the value.
ACE_Service_Config::TSS_Service_Gestalt_Ptr *
ACE_Service_Config::impl_ (void)
{
  /// A "straight" static ptr does not work in static builds, because
  /// some static initializer may call current() method and assign
  /// value to instance_ *before* the startup code has had a chance to
  /// initialize it . This results in instance_ being "zeroed" out
  /// after it was assigned the correct value. Having a method scoped
  /// static guarantees that the first time the method is invoked, the
  /// instance_ will be initialized before returning.

  static TSS_Service_Gestalt_Ptr * instance_ = 0;

  // We can't possibly rely on ACE_STATIC_OBJECT_LOCK or any other
  // object that may be managed by the Object Manager. It is very
  // likely we are called in a static initializer context, before the
  // ACE_Object_Manager has been instantiated. This of course only
  // matters for threaded environments.
  ACE_MT (static ACE_SYNCH_RECURSIVE_MUTEX guardian_);

  if (instance_ == 0)
    {
      // TSS not initialized yet - first thread to hit this, so doing
      // the double-checked locking thing
      ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                                guardian_, 0));

      if (instance_ == 0)
        ACE_NEW_RETURN (instance_,
                        TSS_Service_Gestalt_Ptr,
                        0);
    }

  return instance_;
}

/// Return the configuration instance, considered "global" in the
/// current thread. This may be the same as instance(), but on some
/// occasions, it may be a different one. For example,
/// ACE_Service_Config_Guard provides a way of temporarily replacing
/// the "current" configuration instance in the context of a thread.
ACE_Service_Gestalt *
ACE_Service_Config::current (void)
{
  TSS_Service_Gestalt_Ptr * const impl = ACE_Service_Config::impl_ ();
  if (impl == 0)
    return 0;

  ACE_Service_Gestalt* & gestalt =
    ACE_TSS_GET (impl, TSS_Resources)->ptr_;

  if (gestalt == 0)
    gestalt = ACE_Service_Config::global ();

  return gestalt;
}

/// A mutator to set the "current" (TSS) gestalt instance.
ACE_Service_Gestalt*
ACE_Service_Config::current (ACE_Service_Gestalt *newcurrent)
{
  TSS_Service_Gestalt_Ptr * const impl = ACE_Service_Config::impl_ ();
  if (impl == 0)
    return 0;

  ACE_Service_Gestalt* & gestalt =
    ACE_TSS_GET (impl, TSS_Resources)->ptr_;

  gestalt = newcurrent;

  return gestalt;
}

// This method has changed to return the gestalt instead of the
// container, underlying the service repository and defined
// ACE_Service_Gestalt::insert (ACE_Static_Svc_Descriptor*). This way
// the existing source code can keep using
// ACE_Service_Config::static_svcs(), however now it is not necessary
// to expose the repository storage *and* it is much easier to debug
// service registration problems.

ACE_Service_Gestalt *
ACE_Service_Config::static_svcs (void)
{
  return ACE_Service_Config::current ();
}

///
int
ACE_Service_Config::insert (ACE_Static_Svc_Descriptor* stsd)
{
  return ACE_Service_Config::current ()->insert (stsd);
}


// Totally remove <svc_name> from the daemon by removing it from the
// ACE_Reactor, and unlinking it if necessary.

int
ACE_Service_Config::remove (const ACE_TCHAR svc_name[])
{
  ACE_TRACE ("ACE_Service_Config::remove");
  return ACE_Service_Repository::instance ()->remove (svc_name);
}

// Suspend <svc_name>.  Note that this will not unlink the service
// from the daemon if it was dynamically linked, it will mark it as
// being suspended in the Service Repository and call the <suspend>
// member function on the appropriate <ACE_Service_Object>.  A service
// can be resumed later on by calling the <resume> method...

int
ACE_Service_Config::suspend (const ACE_TCHAR svc_name[])
{
  ACE_TRACE ("ACE_Service_Config::suspend");
  return ACE_Service_Repository::instance ()->suspend (svc_name);
}

// Resume a SVC_NAME that was previously suspended or has not yet
// been resumed (e.g., a static service).

int
ACE_Service_Config::resume (const ACE_TCHAR svc_name[])
{
  ACE_TRACE ("ACE_Service_Config::resume");
  return ACE_Service_Repository::instance ()->resume (svc_name);
}

// Initialize the Service Repository.  Note that this *must* be
// performed in the constructor (rather than <open>) since otherwise
// the repository will not be properly initialized to allow static
// configuration of services...

ACE_Service_Config::ACE_Service_Config (int ignore_static_svcs,
                                        size_t size,
                                        int signum)
  : ACE_Service_Gestalt (size, false, ignore_static_svcs)
{
  ACE_TRACE ("ACE_Service_Config::ACE_Service_Config");

  ACE_Service_Config::signum_ = signum;
}


#if (ACE_USES_CLASSIC_SVC_CONF == 0)
ACE_Service_Type *
ACE_Service_Config::create_service_type  (const ACE_TCHAR *n,
                                          ACE_Service_Type_Impl *o,
                                          ACE_DLL &dll,
                                          int active)
{
  ACE_Service_Type *sp = 0;
  ACE_NEW_RETURN (sp,
                  ACE_Service_Type (n, o, dll, active),
                  0);
  return sp;
}
#endif /* ACE_USES_CLASSIC_SVC_CONF == 0 */

ACE_Service_Type_Impl *
ACE_Service_Config::create_service_type_impl (const ACE_TCHAR *name,
                                              int type,
                                              void *symbol,
                                              u_int flags,
                                              ACE_Service_Object_Exterminator gobbler)
{
  ACE_Service_Type_Impl *stp = 0;

  // Note, the only place we need to put a case statement.  This is
  // also the place where we'd put the RTTI tests, if the compiler
  // actually supported them!

  switch (type)
    {
    case ACE_Service_Type::SERVICE_OBJECT:
      ACE_NEW_RETURN (stp,
                      ACE_Service_Object_Type ((ACE_Service_Object *) symbol,
                                               name, flags,
                                               gobbler),
                      0);
      break;
    case ACE_Service_Type::MODULE:
      ACE_NEW_RETURN (stp,
                      ACE_Module_Type (symbol, name, flags),
                      0);
      break;
    case ACE_Service_Type::STREAM:
      ACE_NEW_RETURN (stp,
                      ACE_Stream_Type (symbol, name, flags),
                      0);
      break;
    default:
      ACE_ERROR ((LM_ERROR,
                  ACE_LIB_TEXT ("unknown case\n")));
      break;
    }
  return stp;

}


ACE_Service_Config::ACE_Service_Config (const ACE_TCHAR program_name[],
                                        const ACE_TCHAR *logger_key)
  : ACE_Service_Gestalt (ACE_Service_Repository::DEFAULT_SIZE, false)
{
  ACE_TRACE ("ACE_Service_Config::ACE_Service_Config");

  if (this->open (program_name,
                  logger_key) == -1 && errno != ENOENT)
    {

      // Only print out an error if it wasn't the svc.conf file that was
      // missing.
      ACE_ERROR ((LM_ERROR,
                  ACE_LIB_TEXT ("(%P|%t) SC failed to open: %p\n"),
                  program_name));
    }
}

// Signal handling API to trigger dynamic reconfiguration.

void
ACE_Service_Config::handle_signal (int sig,
                                   siginfo_t *,
                                   ucontext_t *)
{
#if defined (ACE_NDEBUG)
  ACE_UNUSED_ARG (sig);
#else  /* ! ACE_NDEBUG */
  ACE_ASSERT (ACE_Service_Config::signum_ == sig);
#endif /* ! ACE_NDEBUG */

  ACE_Service_Config::reconfig_occurred_ = 1;
}

// Trigger the reconfiguration process.

void
ACE_Service_Config::reconfigure (void)
{
  ACE_TRACE ("ACE_Service_Config::reconfigure");

  ACE_Service_Config::reconfig_occurred_ = 0;

  if (ACE::debug ())
    {
#if !defined (ACE_NLOGGING)
      time_t t = ACE_OS::time (0);
#endif /* ! ACE_NLOGGING */
      if (ACE::debug ())
        ACE_DEBUG ((LM_DEBUG,
                    ACE_LIB_TEXT ("beginning reconfiguration at %s"),
                    ACE_OS::ctime (&t)));
    }
  if (ACE_Service_Config::process_directives () == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_LIB_TEXT ("%p\n"),
                ACE_LIB_TEXT ("process_directives")));
}

// Tidy up and perform last rites on a terminating ACE_Service_Config.
int
ACE_Service_Config::close (void)
{
  int result1 = ACE_Service_Config::current ()->close ();

  // Delete the service repository.  All the objects inside the
  // service repository should already have been finalized.
  int result2 = ACE_Service_Config::close_svcs ();

  return (result1 | result2);
}

int
ACE_Service_Config::close_svcs (void)
{
  ACE_TRACE ("ACE_Service_Config::close_svcs");

  ACE_Service_Repository::close_singleton ();
  ACE_Service_Config::current (0);
  return 0;
}

int
ACE_Service_Config::fini_svcs (void)
{
  ACE_TRACE ("ACE_Service_Config::fini_svcs");

  // Clear the LM_DEBUG bit from log messages if appropriate
  if (ACE::debug ())
    ACE_Log_Msg::disable_debug_messages ();

  int result = 0;
  if (ACE_Service_Repository::instance () != 0)
    result = ACE_Service_Repository::instance ()->fini ();

  if (ACE::debug ())
    ACE_Log_Msg::enable_debug_messages ();

  return result;
}

// Perform user-specified close activities and remove dynamic memory.

ACE_Service_Config::~ACE_Service_Config (void)
{
  ACE_TRACE ("ACE_Service_Config::~ACE_Service_Config");
}

// ************************************************************

/* static */
int
ACE_Service_Config::reconfig_occurred (void)
{
  ACE_TRACE ("ACE_Service_Config::reconfig_occurred");
  return ACE_Service_Config::reconfig_occurred_ != 0;
}

void
ACE_Service_Config::reconfig_occurred (int config_occurred)
{
  ACE_TRACE ("ACE_Service_Config::reconfig_occurred");
  ACE_Service_Config::reconfig_occurred_ = config_occurred;
}

// ************************************************************

ACE_END_VERSIONED_NAMESPACE_DECL
