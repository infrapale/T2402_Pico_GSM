#include "Arduino.h"
#include "main.h"
#include "task.h"
#include "gsm.h"

#define PIN_SERIAL1_TX (0u)
#define PIN_SERIAL1_RX (1u)

#undef  PIN_SERIAL2_TX 
#undef  PIN_SERIAL2_RX

#define PIN_SERIAL_2_TX (4u)
#define PIN_SERIAL_2_RX (5u)

#define PIN_GSM_RESET    (16u)

#define SERIAL_BAUD   9600

extern task_st task[TASK_NBR_OF]; 

task_st gsm_comm_task_def =     {"GSM Comm       ", 5000,0, 0, 255, gsm_comm_task };
task_st gsm_xon_xoff_task_def = {"GSM XON/XOFF   ", 10,0, 0, 255,  gsm_comm_xon_xoff_task };

void setup() 
{
  SerialGsm.setTX(PIN_SERIAL1_TX);
  SerialGsm.setRX(PIN_SERIAL1_RX);
  Serial2.setTX(PIN_SERIAL_2_TX);
  Serial2.setRX(PIN_SERIAL_2_RX);
  
  pinMode(PIN_GSM_RESET, OUTPUT);
  digitalWrite(PIN_GSM_RESET, HIGH); 

  //while (!Serial); // wait until serial console is open, remove if not tethered to computer
  delay(2000);
  digitalWrite(PIN_GSM_RESET, LOW); 
  Serial.begin(9600);
  SerialGsm.begin(9600);
  Serial.println("T240_Pico_GSM");
  Serial.println(__DATE__); Serial.println(__TIME__);

  task_initialize(TASK_NBR_OF);
  task_set_task(TASK_GSM_COMM, &gsm_comm_task_def); 
  task_set_task(TASK_GSM_XON, &gsm_xon_xoff_task_def); 

}

void loop() 
{
  // put your main code here, to run repeatedly:
  task_run(); 
  
}


