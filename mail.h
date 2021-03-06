#ifndef MAIL_H_
#define MAIL_H_
 
#include "ipc_types.h"
#include "cobject.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef union Mail
{
   struct Mail_Class _private * _private vtbl;
   struct
   {
      struct Object Object;
      IPC_TID_T _private sender;
      IPC_TID_T _private receiver;
      IPC_MID_T _private mid;
      void _private * _private payload;
      size_t _private pay_size;
   };
}Mail_T;

typedef struct Mail_Class
{
      struct Class Class;
      void (* _private set_payload)(union Mail * const ,void const * const, size_t const);
      void (* _private dump)(union Mail * const );
      void (* _private set_mid)(union Mail * const ,IPC_MID_T const);
      void (* _private set_sender)(union Mail * const ,IPC_TID_T const);
      void (* _private set_receiver)(union Mail * const ,IPC_TID_T const);
}Mail_Class_T;

extern struct Mail_Class _private Mail_Class;

extern void Populate_Mail(union Mail * const mail, IPC_MID_T const mid, IPC_TID_T const sender, IPC_TID_T const receiver,
      void const * const payload, size_t const pay_size);

#ifdef __cplusplus
}
#endif
#endif /*MAIL_H_*/
