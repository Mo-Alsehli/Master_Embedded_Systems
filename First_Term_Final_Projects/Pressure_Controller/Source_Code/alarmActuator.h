/**
 *****************************************************************************
 * @project        : Pressure_Controller
 * @file           : alarmActuator.h
 * @author         : Mohamed Magdi
 * @Created on     : Jul 29, 2023
 ******************************************************************************
 */
#ifndef ALARMACTUATOR_H_
#define ALARMACTUATOR_H_

#include "state.h"

enum
{
    initAlarmAct,
    alarmActWaiting,
    alarmActOff,
    alarmActOn
} ALARM_ACT_ID;

void stateDefine(initAlarmAct);
void stateDefine(alarmActWaiting);
void stateDefine(alarmActOff);
void stateDefine(alarmActOn);

extern void (*pAlarmAct)();

#endif