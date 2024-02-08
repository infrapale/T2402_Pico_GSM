#ifndef __GSM_H__
#define __GSM_H__
 
typedef enum
{
    ASCII_NUL =   0x00,
    ASCII_XON =   0x11,
    ASCII_XOFF =  0x13,
    ASCII_CR =    0x0D,
    ASCII_LF =    0x0A,
    ASCII_SUB =   0x1A,
    ASCII_ESC =   0x11,
    ASCII_ =      0x00
} ascii_et;


void gsm_comm_xon_xoff_task(void);

void gsm_comm_task(void);


#endif