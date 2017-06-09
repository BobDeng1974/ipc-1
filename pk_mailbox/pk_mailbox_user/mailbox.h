/*=====================================================================================*/
/**
 * mailbox.h
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#ifndef MAILBOX_H_
#define MAILBOX_H_
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "ipc_types.h"
#include "task.h"
#include "mail.h"
/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Define Macros
 *=====================================================================================*/
#undef CLASS_NAME
#undef CLASS_INHERITS
#undef CLASS_MEMBERS
#undef CLASS_METHODS

#define CLASS_NAME Mailbox
#define CLASS_INHERITS Object

#define CLASS_MEMBERS(_member) \
_member(Task_T * _private, owner) \
_member(Ring_Buffer_T * _private, mailbox) \
_member(size_t _private, data_size) \

#define CLASS_METHODS(_method, _void_method) \
      bool_t _method(subscribe, union Publisher *, IPC_Mail_Id_T const) \
      bool_t _method(unsubscribe, union Publisher *,  IPC_Mail_Id_T const) \
      void _method(push_mail, Mail_T * const) \
      Mail_T const * _void_method(pop_mail) \
      void _void_method(dump) \

#ifdef __cplusplus
extern "C" {
#endif
/*=====================================================================================* 
 * Exported Type Declarations
 *=====================================================================================*/
CLASS_DECLARATION
/*=====================================================================================* 
 * Exported Object Declarations
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Function Prototypes
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Function Like Macros
 *=====================================================================================*/
#ifdef __cplusplus
}
#endif
/*=====================================================================================* 
 * mailbox.h
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
#endif /*MAILBOX_H_*/
