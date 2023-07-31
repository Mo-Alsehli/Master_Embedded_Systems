/**
 *****************************************************************************
 * @project        : Pressure_Controller
 * @file           : alarmActuator.c
 * @author         : Mohamed Magdi
 * @Created on     : Jul 29, 2023
 ******************************************************************************
 */

#include "alarmActuator.h"
#include "driver.h"

void (*pAlarmAct)();

void StartAlarm()
{
    pAlarmAct = state(alarmActOn);
}

void StopAlarm()
{
    pAlarmAct = state(alarmActOff);
}

void stateDefine(initAlarmAct)
{
}

void stateDefine(alarmActWaiting)
{
    ALARM_ACT_ID = alarmActWaiting;
    pAlarmAct = state(alarmActWaiting);
}

void stateDefine(alarmActOff)
{
    ALARM_ACT_ID = alarmActOff;
    Set_Alarm_actuator(0);
    pAlarmAct = state(alarmActWaiting);
}

void stateDefine(alarmActOn)
{
    ALARM_ACT_ID = alarmActOn;
    Set_Alarm_actuator(1);
    pAlarmAct = state(alarmActWaiting);
}