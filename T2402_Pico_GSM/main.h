#ifndef __MAIN_H__
#define __MAIN_H__
#include "Arduino.h"

#define SerialGsm   Serial1
#define APP_NAME    "T240_Pico_GSM"

#include "WString.h"

typedef enum
{
    TASK_GSM_COMM = 0,
    TASK_GSM_XON,
    TASK_xxx,
    TASK_NBR_OF
} tasks_et;




#endif