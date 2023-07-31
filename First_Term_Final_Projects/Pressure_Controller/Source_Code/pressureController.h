/**
 *****************************************************************************
 * @project        : Pressure_Controller
 * @file           : pressureController.c
 * @author         : Mohamed Magdi
 * @Created on     : Jul 27, 2023
 ******************************************************************************
 */

#ifndef PRESSURECONTROLLER_H_
#define PRESSURECONTROLLER_H_

#include "state.h"

enum
{
    HighPressureDetected
} PControllerID;

void stateDefine(HighPressureDetected);

extern void (*pCState)();

#endif