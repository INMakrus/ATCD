// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:351


#include "MIF_SchedulingC.h"
#include "tao/Stub.h"
#include "tao/ORB_Core.h"
#include "tao/Invocation.h"
#include "tao/PortableInterceptor.h"

#if TAO_HAS_INTERCEPTORS == 1
#include "tao/RequestInfo_Util.h"
#include "tao/ClientRequestInfo_i.h"
#include "tao/ClientInterceptorAdapter.h"
#endif  /* TAO_HAS_INTERCEPTORS == 1 */


#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "MIF_SchedulingC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_MIF_Scheduling_SchedulingParameter[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  43,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x4d49465f), 
  ACE_NTOHL (0x53636865), 
  ACE_NTOHL (0x64756c69), 
  ACE_NTOHL (0x6e672f53), 
  ACE_NTOHL (0x63686564), 
  ACE_NTOHL (0x756c696e), 
  ACE_NTOHL (0x67506172), 
  ACE_NTOHL (0x616d6574), 
  ACE_NTOHL (0x65723a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:MIF_Scheduling/SchedulingParameter:1.0
    20,
  ACE_NTOHL (0x53636865), 
  ACE_NTOHL (0x64756c69), 
  ACE_NTOHL (0x6e675061), 
  ACE_NTOHL (0x72616d65), 
  ACE_NTOHL (0x74657200),  // name = SchedulingParameter
  1, // member count
    11,
  ACE_NTOHL (0x696d706f), 
  ACE_NTOHL (0x7274616e), 
  ACE_NTOHL (0x63650000),  // name = importance
    CORBA::tk_long,

};

static CORBA::TypeCode _tc_TAO_tc_MIF_Scheduling_SchedulingParameter (
    CORBA::tk_struct,
    sizeof (_oc_MIF_Scheduling_SchedulingParameter),
    (char *) &_oc_MIF_Scheduling_SchedulingParameter,
    0,
    sizeof (MIF_Scheduling::SchedulingParameter)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (MIF_Scheduling)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_SchedulingParameter,
    &_tc_TAO_tc_MIF_Scheduling_SchedulingParameter
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from 
// be/be_visitor_structure/structure_cs.cpp:66

void MIF_Scheduling::SchedulingParameter::_tao_any_destructor (void *_tao_void_pointer)
{
  SchedulingParameter *tmp = ACE_static_cast (SchedulingParameter*, _tao_void_pointer);
  delete tmp;
}

// TAO_IDL - Generated from
// be/be_type.cpp:297

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class
  TAO_Fixed_Var_T<
      MIF_Scheduling::SchedulingParameter
    >;

template class TAO_Var_Base_T<
    MIF_Scheduling::SchedulingParameter
  >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
  TAO_Fixed_Var_T< \
      MIF_Scheduling::SchedulingParameter \
    >

#pragma instantiate TAO_Var_Base_T<
    MIF_Scheduling::SchedulingParameter
  >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:63

int MIF_Scheduling::SchedulingParameterPolicy::_tao_class_id = 0;

MIF_Scheduling::SchedulingParameterPolicy_ptr
MIF_Scheduling::tao_SchedulingParameterPolicy_life::tao_duplicate (
    SchedulingParameterPolicy_ptr p
  )
{
  return SchedulingParameterPolicy::_duplicate (p);
}

void
MIF_Scheduling::tao_SchedulingParameterPolicy_life::tao_release (
    SchedulingParameterPolicy_ptr p
  )
{
  CORBA::release (p);
}

MIF_Scheduling::SchedulingParameterPolicy_ptr
MIF_Scheduling::tao_SchedulingParameterPolicy_life::tao_nil (
    void
  )
{
  return SchedulingParameterPolicy::_nil ();
}

CORBA::Boolean
MIF_Scheduling::tao_SchedulingParameterPolicy_life::tao_marshal (
    SchedulingParameterPolicy_ptr p,
    TAO_OutputCDR &cdr
  )
{
  return p->marshal (cdr);
}

MIF_Scheduling::SchedulingParameterPolicy_ptr
MIF_Scheduling::tao_SchedulingParameterPolicy_cast::tao_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return SchedulingParameterPolicy::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
MIF_Scheduling::tao_SchedulingParameterPolicy_cast::tao_upcast (
    void *src
  )
{
  SchedulingParameterPolicy **tmp =
    ACE_static_cast (SchedulingParameterPolicy **, src);
  return *tmp;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class
    TAO_Objref_Var_T<
        MIF_Scheduling::SchedulingParameterPolicy,
        MIF_Scheduling::tao_SchedulingParameterPolicy_life
      >;
  template class
    TAO_Objref_Out_T<
        MIF_Scheduling::SchedulingParameterPolicy,
        MIF_Scheduling::tao_SchedulingParameterPolicy_life
      >;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate \
    TAO_Objref_Var_T< \
        MIF_Scheduling::SchedulingParameterPolicy, \
        MIF_Scheduling::tao_SchedulingParameterPolicy_life \
      >
# pragma instantiate \
    TAO_Objref_Out_T< \
        MIF_Scheduling::SchedulingParameterPolicy, \
        MIF_Scheduling::tao_SchedulingParameterPolicy_life \
      >
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from 
// be/be_visitor_interface/interface_cs.cpp:245

MIF_Scheduling::SchedulingParameterPolicy::SchedulingParameterPolicy (void)
{}

MIF_Scheduling::SchedulingParameterPolicy::~SchedulingParameterPolicy (void)
{}

void 
MIF_Scheduling::SchedulingParameterPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  SchedulingParameterPolicy *tmp = ACE_static_cast (SchedulingParameterPolicy *, _tao_void_pointer);
  CORBA::release (tmp);
}

MIF_Scheduling::SchedulingParameterPolicy_ptr
MIF_Scheduling::SchedulingParameterPolicy::_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
{
  return SchedulingParameterPolicy::_unchecked_narrow (obj ACE_ENV_ARG_PARAMETER);
}

MIF_Scheduling::SchedulingParameterPolicy_ptr 
MIF_Scheduling::SchedulingParameterPolicy::_unchecked_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (obj))
    {
      return SchedulingParameterPolicy::_nil ();
    }
  
  return
      ACE_reinterpret_cast (
          SchedulingParameterPolicy_ptr,
          obj->_tao_QueryInterface (
              ACE_reinterpret_cast (
                  ptrdiff_t,
                  &SchedulingParameterPolicy::_tao_class_id
                )
            )
        );
}

MIF_Scheduling::SchedulingParameterPolicy_ptr
MIF_Scheduling::SchedulingParameterPolicy::_duplicate (SchedulingParameterPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void *MIF_Scheduling::SchedulingParameterPolicy::_tao_QueryInterface (ptrdiff_t type)
{
  void *retv = 0;
  
  if (type == ACE_reinterpret_cast (
              ptrdiff_t,
              &::CORBA::Policy::_tao_class_id)
            )
    {
      retv =
        ACE_reinterpret_cast (
            void *,
            ACE_static_cast (
                CORBA::Policy_ptr,
                this
              )
          );
    }
  else if (type == ACE_reinterpret_cast (
              ptrdiff_t,
              &ACE_NESTED_CLASS (::MIF_Scheduling, SchedulingParameterPolicy)::_tao_class_id)
            )
    {
      retv = ACE_reinterpret_cast (void*, this);
    }
  else if (type == ACE_reinterpret_cast (
               ptrdiff_t,
               &CORBA::Object::_tao_class_id)
             )
    {
      retv =
        ACE_reinterpret_cast (
            void *,
            ACE_static_cast (CORBA::Object_ptr, this)
          );
    }
  
  if (retv != 0)
    {
      this->_add_ref ();
    }
  
  return retv;
}

const char* MIF_Scheduling::SchedulingParameterPolicy::_interface_repository_id (void) const
{
  return "IDL:MIF_Scheduling/SchedulingParameterPolicy:1.0";
}

CORBA::Boolean
MIF_Scheduling::SchedulingParameterPolicy::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_MIF_Scheduling_SchedulingParameterPolicy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  49,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x4d49465f), 
  ACE_NTOHL (0x53636865), 
  ACE_NTOHL (0x64756c69), 
  ACE_NTOHL (0x6e672f53), 
  ACE_NTOHL (0x63686564), 
  ACE_NTOHL (0x756c696e), 
  ACE_NTOHL (0x67506172), 
  ACE_NTOHL (0x616d6574), 
  ACE_NTOHL (0x6572506f), 
  ACE_NTOHL (0x6c696379), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0x0),  // repository ID = IDL:MIF_Scheduling/SchedulingParameterPolicy:1.0
    26,
  ACE_NTOHL (0x53636865), 
  ACE_NTOHL (0x64756c69), 
  ACE_NTOHL (0x6e675061), 
  ACE_NTOHL (0x72616d65), 
  ACE_NTOHL (0x74657250), 
  ACE_NTOHL (0x6f6c6963), 
  ACE_NTOHL (0x79000000),  // name = SchedulingParameterPolicy
  };

static CORBA::TypeCode _tc_TAO_tc_MIF_Scheduling_SchedulingParameterPolicy (
    CORBA::tk_objref,
    sizeof (_oc_MIF_Scheduling_SchedulingParameterPolicy),
    (char *) &_oc_MIF_Scheduling_SchedulingParameterPolicy,
    0,
    sizeof (MIF_Scheduling::SchedulingParameterPolicy)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (MIF_Scheduling)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_SchedulingParameterPolicy,
    &_tc_TAO_tc_MIF_Scheduling_SchedulingParameterPolicy
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:63

int MIF_Scheduling::Scheduler::_tao_class_id = 0;

MIF_Scheduling::Scheduler_ptr
MIF_Scheduling::tao_Scheduler_life::tao_duplicate (
    Scheduler_ptr p
  )
{
  return Scheduler::_duplicate (p);
}

void
MIF_Scheduling::tao_Scheduler_life::tao_release (
    Scheduler_ptr p
  )
{
  CORBA::release (p);
}

MIF_Scheduling::Scheduler_ptr
MIF_Scheduling::tao_Scheduler_life::tao_nil (
    void
  )
{
  return Scheduler::_nil ();
}

CORBA::Boolean
MIF_Scheduling::tao_Scheduler_life::tao_marshal (
    Scheduler_ptr p,
    TAO_OutputCDR &cdr
  )
{
  return p->marshal (cdr);
}

MIF_Scheduling::Scheduler_ptr
MIF_Scheduling::tao_Scheduler_cast::tao_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return Scheduler::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
MIF_Scheduling::tao_Scheduler_cast::tao_upcast (
    void *src
  )
{
  Scheduler **tmp =
    ACE_static_cast (Scheduler **, src);
  return *tmp;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class
    TAO_Objref_Var_T<
        MIF_Scheduling::Scheduler,
        MIF_Scheduling::tao_Scheduler_life
      >;
  template class
    TAO_Objref_Out_T<
        MIF_Scheduling::Scheduler,
        MIF_Scheduling::tao_Scheduler_life
      >;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate \
    TAO_Objref_Var_T< \
        MIF_Scheduling::Scheduler, \
        MIF_Scheduling::tao_Scheduler_life \
      >
# pragma instantiate \
    TAO_Objref_Out_T< \
        MIF_Scheduling::Scheduler, \
        MIF_Scheduling::tao_Scheduler_life \
      >
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from 
// be/be_visitor_interface/interface_cs.cpp:245

MIF_Scheduling::Scheduler::Scheduler (void)
{}

MIF_Scheduling::Scheduler::~Scheduler (void)
{}

void 
MIF_Scheduling::Scheduler::_tao_any_destructor (void *_tao_void_pointer)
{
  Scheduler *tmp = ACE_static_cast (Scheduler *, _tao_void_pointer);
  CORBA::release (tmp);
}

MIF_Scheduling::Scheduler_ptr
MIF_Scheduling::Scheduler::_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
{
  return Scheduler::_unchecked_narrow (obj ACE_ENV_ARG_PARAMETER);
}

MIF_Scheduling::Scheduler_ptr 
MIF_Scheduling::Scheduler::_unchecked_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (obj))
    {
      return Scheduler::_nil ();
    }
  
  return
      ACE_reinterpret_cast (
          Scheduler_ptr,
          obj->_tao_QueryInterface (
              ACE_reinterpret_cast (
                  ptrdiff_t,
                  &Scheduler::_tao_class_id
                )
            )
        );
}

MIF_Scheduling::Scheduler_ptr
MIF_Scheduling::Scheduler::_duplicate (Scheduler_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void *MIF_Scheduling::Scheduler::_tao_QueryInterface (ptrdiff_t type)
{
  void *retv = 0;
  
  if (type == ACE_reinterpret_cast (
              ptrdiff_t,
              &::RTScheduling::Scheduler::_tao_class_id)
            )
    {
      retv =
        ACE_reinterpret_cast (
            void *,
            ACE_static_cast (
                RTScheduling::Scheduler_ptr,
                this
              )
          );
    }
  else if (type == ACE_reinterpret_cast (
              ptrdiff_t,
              &ACE_NESTED_CLASS (::MIF_Scheduling, Scheduler)::_tao_class_id)
            )
    {
      retv = ACE_reinterpret_cast (void*, this);
    }
  else if (type == ACE_reinterpret_cast (
               ptrdiff_t,
               &CORBA::Object::_tao_class_id)
             )
    {
      retv =
        ACE_reinterpret_cast (
            void *,
            ACE_static_cast (CORBA::Object_ptr, this)
          );
    }
  
  if (retv != 0)
    {
      this->_add_ref ();
    }
  
  return retv;
}

const char* MIF_Scheduling::Scheduler::_interface_repository_id (void) const
{
  return "IDL:MIF_Scheduling/Scheduler:1.0";
}

CORBA::Boolean
MIF_Scheduling::Scheduler::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_MIF_Scheduling_Scheduler[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  33,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x4d49465f), 
  ACE_NTOHL (0x53636865), 
  ACE_NTOHL (0x64756c69), 
  ACE_NTOHL (0x6e672f53), 
  ACE_NTOHL (0x63686564), 
  ACE_NTOHL (0x756c6572), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0x0),  // repository ID = IDL:MIF_Scheduling/Scheduler:1.0
    10,
  ACE_NTOHL (0x53636865), 
  ACE_NTOHL (0x64756c65), 
  ACE_NTOHL (0x72000000),  // name = Scheduler
  };

static CORBA::TypeCode _tc_TAO_tc_MIF_Scheduling_Scheduler (
    CORBA::tk_objref,
    sizeof (_oc_MIF_Scheduling_Scheduler),
    (char *) &_oc_MIF_Scheduling_Scheduler,
    0,
    sizeof (MIF_Scheduling::Scheduler)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (MIF_Scheduling)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_Scheduler,
    &_tc_TAO_tc_MIF_Scheduling_Scheduler
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from 
// be/be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const MIF_Scheduling::SchedulingParameter &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<MIF_Scheduling::SchedulingParameter>::insert_copy (
      _tao_any,
      MIF_Scheduling::SchedulingParameter::_tao_any_destructor,
      MIF_Scheduling::_tc_SchedulingParameter,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    MIF_Scheduling::SchedulingParameter *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<MIF_Scheduling::SchedulingParameter>::insert (
      _tao_any,
      MIF_Scheduling::SchedulingParameter::_tao_any_destructor,
      MIF_Scheduling::_tc_SchedulingParameter,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    MIF_Scheduling::SchedulingParameter *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const MIF_Scheduling::SchedulingParameter *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const MIF_Scheduling::SchedulingParameter *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<MIF_Scheduling::SchedulingParameter>::extract (
        _tao_any,
        MIF_Scheduling::SchedulingParameter::_tao_any_destructor,
        MIF_Scheduling::_tc_SchedulingParameter,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Dual_Impl_T<MIF_Scheduling::SchedulingParameter>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Dual_Impl_T<MIF_Scheduling::SchedulingParameter>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    MIF_Scheduling::SchedulingParameterPolicy_ptr _tao_elem
  )
{
  MIF_Scheduling::SchedulingParameterPolicy_ptr _tao_objptr =
    MIF_Scheduling::SchedulingParameterPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    MIF_Scheduling::SchedulingParameterPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<MIF_Scheduling::SchedulingParameterPolicy>::insert (
      _tao_any,
      MIF_Scheduling::SchedulingParameterPolicy::_tao_any_destructor,
      MIF_Scheduling::_tc_SchedulingParameterPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    MIF_Scheduling::SchedulingParameterPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<MIF_Scheduling::SchedulingParameterPolicy>::extract (
        _tao_any,
        MIF_Scheduling::SchedulingParameterPolicy::_tao_any_destructor,
        MIF_Scheduling::_tc_SchedulingParameterPolicy,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Impl_T<MIF_Scheduling::SchedulingParameterPolicy>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Impl_T<MIF_Scheduling::SchedulingParameterPolicy>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    MIF_Scheduling::Scheduler_ptr _tao_elem
  )
{
  MIF_Scheduling::Scheduler_ptr _tao_objptr =
    MIF_Scheduling::Scheduler::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    MIF_Scheduling::Scheduler_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<MIF_Scheduling::Scheduler>::insert (
      _tao_any,
      MIF_Scheduling::Scheduler::_tao_any_destructor,
      MIF_Scheduling::_tc_Scheduler,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    MIF_Scheduling::Scheduler_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<MIF_Scheduling::Scheduler>::extract (
        _tao_any,
        MIF_Scheduling::Scheduler::_tao_any_destructor,
        MIF_Scheduling::_tc_Scheduler,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Impl_T<MIF_Scheduling::Scheduler>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Impl_T<MIF_Scheduling::Scheduler>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

