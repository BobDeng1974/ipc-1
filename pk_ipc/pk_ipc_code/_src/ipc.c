/*=====================================================================================*/
/**
 * ipc.cpp
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
#include "ipc_ext.h"
#include "ipc_set.h"
#include "ipc.h"
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
void IPC_init(void)
{
   printf("%s \n", __FUNCTION__);
   IPC_Obj.pid = 0;

   IPC_Vtbl.Object.rtti = &IPC_Rtti;
   IPC_Vtbl.Object.destroy = IPC_Dtor;
   IPC_Vtbl.ctor = IPC_Ctor;
   IPC_Vtbl.search_pid = NULL;
   IPC_Vtbl.search_task = NULL;
   IPC_Vtbl.set_mailbox = NULL;
   IPC_Vtbl.search_mailbox= NULL;
   IPC_Vtbl.notify_ready = NULL;
   IPC_Vtbl.get_date_length = NULL;
   IPC_Vtbl.get_date = NULL;

}
void IPC_shut(void) {}

void IPC_Dtor(Object_T * const obj)
{
}
/*=====================================================================================* 
 * Exported Function Definitions
 *=====================================================================================*/
void IPC_Ctor(IPC_T * const this, IPC_Process_Id_T const pid, uint32_t const max_tasks)
{
   this->pid = pid;
}

 IPC_Task_Id_T IPC_self_task_id(void)
 {
    Singleton_IPC(&IPC_Obj);
    Isnt_Nullptr(IPC_Obj.vtbl->search_task, 0);
    return IPC_Obj.vtbl->search_task(&IPC_Obj);
 }


 IPC_Process_Id_T IPC_self_pid(void)
 {
    Singleton_IPC(&IPC_Obj);
    Isnt_Nullptr(IPC_Obj.vtbl->search_pid, 0);
    return IPC_Obj.vtbl->search_pid(&IPC_Obj);
 }

 void IPC_task_ready(void)
 {
    Singleton_IPC(&IPC_Obj);
    Isnt_Nullptr(IPC_Obj.vtbl->notify_ready, );
    IPC_Obj.vtbl->notify_ready(&IPC_Obj, IPC_self_task_id());
 }

 void IPC_create_mailbox(uint32_t const max_mails, size_t const mail_size)
 {
    Singleton_IPC(&IPC_Obj);
    Isnt_Nullptr(IPC_Obj.vtbl->set_mailbox, );
    IPC_Obj.vtbl->set_mailbox(&IPC_Obj, max_mails, mail_size);
 }

/**
 * TB Mail Comm
 */
 bool_t IPC_subscribe_mail_list(IPC_Mail_Id_T const * mail_list, uint32_t const mail_elems)
 {
    return Publisher_subscribe(IPC_self_task_id(),  mail_list, mail_elems);
 }

 bool_t IPC_unsubscribe_mail_list(IPC_Mail_Id_T const * mail_list, uint32_t const mail_elems)
 {
    return Publisher_unsubscribe(IPC_self_task_id(),  mail_list, mail_elems);
 }

 void IPC_send(IPC_Task_Id_T const receiver_task, IPC_Process_Id_T const receiver_pid,
      IPC_Mail_Id_T mail_id, void const * data, size_t const data_size)
 {
    Singleton_IPC(&IPC_Obj);
    Mailbox mailbox = IPC_Obj.vtbl->search_mailbox(&IPC_Obj, receiver_task, receiver_pid);
    Isnt_Nullptr(IPC_Obj.vtbl->search_task,);
    Mail_T * mail = Mail_new(mail_id, IPC_Obj.vtbl->search_task(&IPC_Obj), receiver_task, receiver_pid, data, data_size);
    Mailbox_push_mail(mailbox, mail);
 }

 void IPC_publish(IPC_Mail_Id_T const mail_id, void const * data, size_t const data_size)
 {

    Mail mail = Mail_new(mail_id, IPC_self_task_id(), 0, 0, data, data_size);
    Publisher_publish(mail);
 }

 void IPC_broadcast(IPC_Mail_Id_T const mail_id, void const * data, size_t const data_size)
 {
    Singleton_IPC(&IPC_Obj);
    Isnt_Nullptr(IPC_Obj.vtbl->search_mailbox, );
    Isnt_Nullptr(IPC_Obj.vtbl->search_task, );
    IPC_Task_Id_T task = 0;
    IPC_Process_Id_T process = 0;
    Mailbox_T * mailbox = NULL;
    Mail_T * mail = NULL;

    for(process = 0 ; process < IPC_MAX_PROCESSES; ++process)
    {
       for(task = 0 ; task < IPC_MAX_TASKS; ++task)
       {
          mailbox = IPC_Obj.vtbl->search_mailbox(&IPC_Obj, task, process);
          if(NULL != mailbox)
          {
             mail = Mail_New(mail_id, IPC_Obj.vtbl->search_task(&IPC_Obj), task, process, data, data_size);
             mailbox->vtbl->push_mail(mailbox, mail);
             _delete(mail);
          }
       }
    }
 }

Mail_T * const IPC_retreive_from_mail_list(IPC_Mail_Id_T const * mail_list, uint32_t const mail_elems,
      uint32_t const timeout_ms)
 {
    uint32_t i;
    Singleton_IPC(&IPC_Obj);
    Isnt_Nullptr(IPC_Obj.vtbl->search_mailbox, NULL);
    Mail_T * mail = NULL;
    Mailbox_T * mailbox = IPC_Obj.vtbl->search_mailbox(&IPC_Obj, IPC_self_task_id(), IPC_self_pid());

    Isnt_Nullptr(mail_list, NULL);

    for(i = 0; i < mail_elems; ++i)
    {
       mail = mailbox->vtbl->get_mail_by_mail_id(mailbox, mail_list[i]);
       if(NULL != mail)
       {
          mail->vtbl->dump(mail);
          break;
       }
    }
    return mail;
 }

Mail_T * const IPC_retreive_mail(uint32_t const timeout_ms)
 {
    Singleton_IPC(&IPC_Obj);
    Mail_T * mail = NULL;
    Mailbox_T * mailbox = NULL;
    mailbox = IPC_Obj.vtbl->search_mailbox(&IPC_Obj, IPC_self_task_id(), IPC_self_pid());

    mail = Mailbox_get_first_mail(mailbox);
    mail->vtbl->dump(mail);

    return mail;
 }

 void IPC_put_date_string(char * date_str)
 {
    Singleton_IPC(&IPC_Obj);

    Isnt_Nullptr(IPC_Obj.vtbl->get_date_length, );
    Isnt_Nullptr(IPC_Obj.vtbl->get_date, );
    Isnt_Nullptr(date_str, );

    if(strlen(date_str) >= IPC_Obj.vtbl->get_date_length(&IPC_Obj) )
    {
       memcpy(date_str, IPC_Obj.vtbl->get_date(&IPC_Obj), IPC_Obj.vtbl->get_date_length(&IPC_Obj));
    }
 }
/*=====================================================================================* 
 * ipc.cpp
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
