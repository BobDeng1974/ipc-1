/*=====================================================================================*/
/**
 * ipc_light.c
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#define CLASS_IMPLEMENTATION
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "ipc_light.h"
/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Local X-Macros
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Define Macros
 *=====================================================================================*/
#undef CLASS_VIRTUAL_METHODS
#define CLASS_VIRTUAL_METHODS(_ovr) \
   _ovr(IPC,get_tid) \
   _ovr(IPC,set_mailbox) \
   _ovr(IPC,notify_ready) \
   _ovr(IPC,get_date_length) \
   _ovr(IPC,get_date) \
/*=====================================================================================* 
 * Local Type Definitions
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Function Prototypes
 *=====================================================================================*/
 static void IPC_Light_Ctor(IPC_Light_T * const this, uint32_t const max_tasks);
 static IPC_Task_Id_T IPC_Light_get_tid(IPC_T * const super);
 static void IPC_Light_set_mailbox(IPC_T * const super, uint32_t const, uint32_t const);
 static void IPC_Light_notify_ready(IPC_T * const super, IPC_Task_Id_T const);
 static size_t IPC_Light_get_date_length(IPC_T * const super);
 static char const * IPC_Light_get_date(IPC_T * const super);
 /*=====================================================================================*
  * Local Object Definitions
  *=====================================================================================*/
 CLASS_DEFINITION

 /*=====================================================================================*
  * Exported Object Definitions
  *=====================================================================================*/

 /*=====================================================================================*
  * Local Inline-Function Like Macros
  *=====================================================================================*/

 /*=====================================================================================*
  * Local Function Definitions
  *=====================================================================================*/
 void IPC_Light_init(void)
 {
    printf("%s \n", __FUNCTION__);
    CHILD_CLASS_INITIALIZATION
    IPC_Light_Vtbl.ctor = IPC_Light_Ctor;

 }
 void IPC_Light_shut(void) {}

 void IPC_Light_Dtor(Object_T * const obj)
 {
 }
 /*=====================================================================================*
  * Exported Function Definitions
  *=====================================================================================*/
 void IPC_Light_Ctor(IPC_Light_T * const this, uint32_t const max_tasks)
 {

 }

 IPC_Task_Id_T IPC_Light_get_tid(IPC_T * const super)
 {
    return 0; /* TODO */
 }

 void IPC_Light_set_mailbox(IPC_T * const super, IPC_Task_Id_T const tid, uint32_t const mail_elements)
 {

 }

 void IPC_Light_notify_ready(IPC_T * const super, IPC_Task_Id_T const task_id)
 {

 }

 size_t IPC_Light_get_date_length(IPC_T * const super)
 {
    return 0; /* TODO */
 }

 char const * IPC_Light_get_date(IPC_T * const super)
 {
    return NULL; /* TODO */
 }
/*=====================================================================================* 
 * ipc_light.c
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/