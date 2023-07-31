/**
 *****************************************************************************
 * @project        : Pressure_Controller
 * @file           : alarmMonitor.h
 * @author         : Mohamed Magdi
 * @Created on     : Jul 29, 2023
 ******************************************************************************
 */

#ifndef ALARM_H_
#define ALARM_H_

#include "state.h"

enum
{

    alarmMonOn,
    alarmMonOff,
    alarmMonWaiting
} ALARM_MON_ID;

void stateDefine(alarmMonOn);
void stateDefine(alarmMonOff);
void stateDefine(alarmMonWaiting);

extern void (*pAlarmMon)();

#endif