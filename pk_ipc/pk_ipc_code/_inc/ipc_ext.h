/*=====================================================================================*/
/**
 * ipc_light.h
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#ifndef IPC_LIGHT_H_
#define IPC_LIGHT_H_
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "ipc_types.h"
#include "mailbox.h"
#include "publisher.h"
#include "mailbox_ringbuffer.h"
#include "task.h"
#include "task_stack.h"
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

#define CLASS_NAME IPC
#define CLASS_INHERITS Object
#define CLASS_MEMBERS(_member) \
_member(IPC_Process_Id_T, pid) \
_member(Vector_Task_T, task_stack) \
_member(Vector_Mailbox_T, mbx_stack) \
_member(uint32_t, max_tasks)\


#define CLASS_METHODS(_method, _void_method) \
void _method(ctor, IPC_Process_Id_T const, uint32_t const) \
IPC_Task_Id_T _void_method(get_tid) \
IPC_Process_Id_T _void_method(get_pid) \
Task_T * const _method(search_task, IPC_Task_Id_T const) \
void _method(set_mailbox, uint32_t const, uint32_t const) \
Mailbox_T * const _method(search_mailbox, uint32_t const, uint32_t const) \
void _method(notify_ready, IPC_Task_Id_T const) \
int _void_method(wait) \
uint32_t _void_method(timestamp) \
size_t _void_method(get_date_length) \
char const * _void_method(get_date) \

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
extern void IPC_get_instance(IPC_T ** singleton);
/*=====================================================================================* 
 * Exported Function Like Macros
 *=====================================================================================*/
#ifdef __cplusplus
}
#endif
/*=====================================================================================* 
 * ipc_light.h
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
#endif /*IPC_LIGHT_H_*/
