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
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:314


#include "RTPortableServerC.h"

#if defined (TAO_HAS_CORBA_MESSAGING) && TAO_HAS_CORBA_MESSAGING != 0

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "RTPortableServerC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:61

int RTPortableServer::POA::_tao_class_id = 0;

RTPortableServer::POA_ptr
RTPortableServer::tao_POA_life::tao_duplicate (
    RTPortableServer::POA_ptr p
  )
{
  return RTPortableServer::POA::_duplicate (p);
}

void
RTPortableServer::tao_POA_life::tao_release (
    RTPortableServer::POA_ptr p
  )
{
  CORBA::release (p);
}

RTPortableServer::POA_ptr
RTPortableServer::tao_POA_life::tao_nil (
    void
  )
{
  return RTPortableServer::POA::_nil ();
}

CORBA::Boolean
RTPortableServer::tao_POA_life::tao_marshal (
    RTPortableServer::POA_ptr p,
    TAO_OutputCDR &cdr
  )
{
  return p->marshal (cdr);
}

RTPortableServer::POA_ptr
RTPortableServer::tao_POA_cast::tao_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return RTPortableServer::POA::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
RTPortableServer::tao_POA_cast::tao_upcast (
    void *src
  )
{
  RTPortableServer::POA **tmp =
    ACE_static_cast (RTPortableServer::POA **, src);
  return *tmp;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class
    TAO_Objref_Var_T<
        RTPortableServer::POA,
        RTPortableServer::tao_POA_life
      >;
  template class
    TAO_Objref_Out_T<
        RTPortableServer::POA,
        RTPortableServer::tao_POA_life
      >;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate \
    TAO_Objref_Var_T< \
        RTPortableServer::POA, \
        RTPortableServer::tao_POA_life \
      >
# pragma instantiate \
    TAO_Objref_Out_T< \
        RTPortableServer::POA, \
        RTPortableServer::tao_POA_life \
      >
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:232

RTPortableServer::POA::POA (void)
{}

RTPortableServer::POA::~POA (void)
{}

void
RTPortableServer::POA::_tao_any_destructor (void *_tao_void_pointer)
{
  POA *tmp = ACE_static_cast (POA *, _tao_void_pointer);
  CORBA::release (tmp);
}

RTPortableServer::POA_ptr
RTPortableServer::POA::_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
{
  return POA::_unchecked_narrow (obj ACE_ENV_ARG_PARAMETER);
}

RTPortableServer::POA_ptr
RTPortableServer::POA::_unchecked_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (obj))
    {
      return POA::_nil ();
    }

  return
      ACE_reinterpret_cast (
          POA_ptr,
          obj->_tao_QueryInterface (
              ACE_reinterpret_cast (
                  ptrdiff_t,
                  &POA::_tao_class_id
                )
            )
        );
}

RTPortableServer::POA_ptr
RTPortableServer::POA::_duplicate (POA_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

void *RTPortableServer::POA::_tao_QueryInterface (ptrdiff_t type)
{
  void *retv = 0;

  if (type == ACE_reinterpret_cast (
              ptrdiff_t,
              &ACE_NESTED_CLASS (::RTPortableServer, POA)::_tao_class_id)
            )
    {
      retv = ACE_reinterpret_cast (void*, this);
    }
  else if (type == ACE_reinterpret_cast (
              ptrdiff_t,
              &::PortableServer::POA::_tao_class_id)
            )
    {
      retv =
        ACE_reinterpret_cast (
            void *,
            ACE_static_cast (
                PortableServer::POA_ptr,
                this
              )
          );
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

const char* RTPortableServer::POA::_interface_repository_id (void) const
{
  return "IDL:omg.org/RTPortableServer/POA:1.0";
}

CORBA::Boolean
RTPortableServer::POA::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_RTPortableServer_POA[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  37,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x5254506f),
  ACE_NTOHL (0x72746162),
  ACE_NTOHL (0x6c655365),
  ACE_NTOHL (0x72766572),
  ACE_NTOHL (0x2f504f41),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/RTPortableServer/POA:1.0
    4,
  ACE_NTOHL (0x504f4100),  // name = POA
  };

static CORBA::TypeCode _tc_TAO_tc_RTPortableServer_POA (
    CORBA::tk_objref,
    sizeof (_oc_RTPortableServer_POA),
    (char *) &_oc_RTPortableServer_POA,
    0,
    sizeof (RTPortableServer::POA)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (RTPortableServer)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_POA,
    &_tc_TAO_tc_RTPortableServer_POA
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_cs.cpp:52

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    RTPortableServer::POA_ptr _tao_elem
  )
{
  RTPortableServer::POA_ptr _tao_objptr =
    RTPortableServer::POA::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    RTPortableServer::POA_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<RTPortableServer::POA>::insert (
      _tao_any,
      RTPortableServer::POA::_tao_any_destructor,
      RTPortableServer::_tc_POA,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    RTPortableServer::POA_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<RTPortableServer::POA>::extract (
        _tao_any,
        RTPortableServer::POA::_tao_any_destructor,
        RTPortableServer::_tc_POA,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
//  template class TAO_Object_Manager<RTPortableServer::POA,RTPortableServer::POA_var>;
  template class TAO::Any_Impl_T<RTPortableServer::POA>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
// # pragma instantiate TAO_Object_Manager<RTPortableServer::POA, RTPortableServer::POA_var>
# pragma instantiate TAO::Any_Impl_T<RTPortableServer::POA>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#endif /* TAO_HAS_CORBA_MESSAGING) && TAO_HAS_CORBA_MESSAGING != 0 */
