/**
 *****************************************************************************
 * @project        : Pressure_Controller
 * @file           : alarmMonitor.c
 * @author         : Mohamed Magdi
 * @Created on     : Jul 29, 2023
 ******************************************************************************
 */

#include "driver.h"
#include "alarmMonitor.h"

void (*pAlarmMon)();

int timer = 0;

void highPressureDetected()
{
    pAlarmMon = state(alarmMonOn);
}

void stateDefine(alarmMonOff)
{
    ALARM_MON_ID = alarmMonOff;

    pAlarmMon = state(alarmMonOff);
}

void stateDefine(alarmMonOn)
{
    ALARM_MON_ID = alarmMonOn;
    StartAlarm();
    timer = 600000;
    Delay(timer);
    pAlarmMon = state(alarmMonWaiting);
}

void stateDefine(alarmMonWaiting)
{
    ALARM_MON_ID = alarmMonWaiting;
    timer = 0;
    StopAlarm();

    pAlarmMon = state(alarmMonOff);
}
