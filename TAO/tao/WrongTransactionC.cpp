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
// be\be_codegen.cpp:291


#include "WrongTransactionC.h"
#include "tao/CDR.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/Struct_TypeCode.h"
#include "tao/SystemException.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "WrongTransactionC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

CORBA::WrongTransaction::WrongTransaction (void)
  : CORBA::UserException (
        "IDL:omg.org/CORBA/WrongTransaction:1.0",
        "WrongTransaction"
      )
{
}

CORBA::WrongTransaction::~WrongTransaction (void)
{
}

CORBA::WrongTransaction::WrongTransaction (const ::CORBA::WrongTransaction &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

CORBA::WrongTransaction&
CORBA::WrongTransaction::operator= (const ::CORBA::WrongTransaction &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void CORBA::WrongTransaction::_tao_any_destructor (void *_tao_void_pointer)
{
  WrongTransaction *_tao_tmp_pointer =
    static_cast<WrongTransaction *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

CORBA::WrongTransaction *
CORBA::WrongTransaction::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<WrongTransaction *> (_tao_excp);
}

const CORBA::WrongTransaction *
CORBA::WrongTransaction::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const WrongTransaction *> (_tao_excp);
}

CORBA::Exception *CORBA::WrongTransaction::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::CORBA::WrongTransaction, 0);
  return retval;
}

CORBA::Exception *
CORBA::WrongTransaction::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::CORBA::WrongTransaction (*this),
      0
    );
  return result;
}

void CORBA::WrongTransaction::_raise (void) const
{
  TAO_RAISE (*this);
}

void CORBA::WrongTransaction::_tao_encode (
    TAO_OutputCDR &cdr
    ACE_ENV_ARG_DECL
  ) const
{
  if (cdr << *this)
    {
      return;
    }
  
  ACE_THROW (CORBA::MARSHAL ());
}

void CORBA::WrongTransaction::_tao_decode (
    TAO_InputCDR &cdr
    ACE_ENV_ARG_DECL
  )
{
  if (cdr >> *this)
    {
      return;
    }
  
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr CORBA::WrongTransaction::_tao_type (void) const
{
  return ::CORBA::_tc_WrongTransaction;
}

// TAO_IDL - Generated from
// be\be_visitor_exception/cdr_op_cs.cpp:60

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::WrongTransaction &_tao_aggregate
  )
{
  // Marshal the repository ID.
  return (strm << _tao_aggregate._rep_id ());
}

CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::WrongTransaction&
  )
{
  return true;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1528

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
