/*=====================================================================================*/
/**
 * mailbox_ringbuffer.h
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#ifndef MAILBOX_RINGBUFFER_H_
#define MAILBOX_RINGBUFFER_H_
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "mailbox.h"
/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Define Macros
 *=====================================================================================*/
#define OBJECT_TEMPLATE
#define _template_t1 Mailbox

#include "template_vector.h"

#undef _template_t1
#undef _template_t2

#ifdef __cplusplus
extern "C" {
#endif
/*=====================================================================================* 
 * Exported Type Declarations
 *=====================================================================================*/

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
 * mailbox_ringbuffer.h
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
#endif /*MAILBOX_RINGBUFFER_H_*/