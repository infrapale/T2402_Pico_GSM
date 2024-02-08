#include "main.h"
#include "gsm.h"
#include "task.h"


extern task_st task[TASK_NBR_OF]; 

typedef struct
{
    bool xoff;
} gsm_comm_st;

gsm_comm_st gsm_comm;

void gsm_comm_initialize(void)
{
  gsm_comm.xoff = false;   
}

void gsm_comm_xon_xoff_task(void)
{
  uint8_t  in_char;
  if ( SerialGsm.available())
  {
      in_char = SerialGsm.read();
      Serial.print((char)in_char);
      //Serial.print('-');
  }
  //Serial.print('.');
}

void gsm_comm_task(void)
{
  switch(task[TASK_GSM_COMM].state)
  {
      case 0:
        SerialGsm.print("AT\r");
        task_delay(TASK_GSM_COMM, 2000);
        task[TASK_GSM_COMM].state++;
        break;
      case 1:
        SerialGsm.print("AT+CPIN=1234\r");
        task_delay(TASK_GSM_COMM, 2000);
        task[TASK_GSM_COMM].state++;
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
 

  }

}