/**
 *****************************************************************************
 * @project        : Pressure_Controller
 * @file           : pressureController.c
 * @author         : Mohamed Magdi
 * @Created on     : Jul 27, 2023
 ******************************************************************************
 */

#include "driver.h"
#include "pressureController.h"

static int pressureVal = 0;
static int threshold = 20;

void (*pCState)() = NULL;

void GetPressureVal(int pVal)
{
    pressureVal = pVal;
    pCState = state(HighPressureDetected);
}

void stateDefine(HighPressureDetected)
{
    PControllerID = HighPressureDetected;
    if (pressureVal >= threshold)
        highPressureDetected();
    pCState = state(HighPressureDetected);
}
