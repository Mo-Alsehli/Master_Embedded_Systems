/**
 *****************************************************************************
 * @project        : Pressure_Controller
 * @file           : pressureSensor.c
 * @author         : Mohamed Magdi
 * @Created on     : Jul 27, 2023
 ******************************************************************************
 */

#ifndef PRESSURESENSOR_H_
#define PRESSURESENSOR_H_

#include "state.h"

enum
{
    init,
    reading,
    sending,
    idle
} PSENSORID;

void stateDefine(init);
void stateDefine(reading);
void stateDefine(sending);
void stateDefine(idle);

extern void (*pPSensor)();

#endif