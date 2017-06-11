/*=====================================================================================*/
/**
 * ipc_decorator.c
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
#include "ipc_decorator.h"
/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Local X-Macros
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Define Macros
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Type Definitions
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Function Prototypes
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Object Definitions
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Function Prototypes
 *=====================================================================================*/
static void IPC_Decorator_Ctor(IPC_Decorator_T * const this, IPC_Process_Id_T const pid, uint32_t const max_tasks,
      IPC_T * const ipc);
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
void IPC_Decorator_init(void)
{
   printf("%s \n", __FUNCTION__);
   IPC_Decorator_Obj.IPC = IPC();
   IPC_Decorator_Obj.ipc = NULL;

   memcpy(&IPC_Decorator_Vtbl.IPC, IPC_Decorator_Obj.IPC.vtbl, sizeof(IPC_Decorator_Vtbl.IPC));
   IPC_Decorator_Vtbl.IPC.Object.rtti = &IPC_Decorator_Rtti;
   IPC_Decorator_Vtbl.IPC.Object.destroy = IPC_Decorator_Dtor;
   IPC_Decorator_Vtbl.IPC.get_tid = NULL;
   IPC_Decorator_Vtbl.IPC.get_pid = NULL;
   IPC_Decorator_Vtbl.IPC.set_mailbox = NULL;
   IPC_Decorator_Vtbl.IPC.notify_ready = NULL;
   IPC_Decorator_Vtbl.IPC.get_date_length = NULL;
   IPC_Decorator_Vtbl.IPC.get_date = NULL;
   IPC_Decorator_Vtbl.ctor = IPC_Decorator_Ctor;

}
void IPC_Decorator_shut(void) {}

void IPC_Decorator_Dtor(Object_T * const obj)
{
}
/*=====================================================================================*
 * Exported Function Definitions
 *=====================================================================================*/
void IPC_Decorator_Ctor(IPC_Decorator_T * const this, IPC_Process_Id_T const pid, uint32_t const max_tasks, IPC_T * const ipc)
{
   this->IPC.vtbl->ctor(&this->IPC, pid, max_tasks);
   this->ipc = ipc;
}
/*=====================================================================================* 
 * ipc_decorator.c
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
