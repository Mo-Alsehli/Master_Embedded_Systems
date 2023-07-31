/**
 *****************************************************************************
 * @project        : Pressure_Controller
 * @file           : pressureSensor.c
 * @author         : Mohamed Magdi
 * @Created on     : Jul 27, 2023
 ******************************************************************************
 */

#include "pressureSensor.h"
#include "driver.h"

static int pressureVal = 0;
int sensorPullTime = 0;
void (*pPSensor)();

void stateDefine(init)
{
    // init sensor
}

void stateDefine(reading)
{
    PSENSORID = reading;
    pressureVal = getPressureVal();
    GetPressureVal(pressureVal);
    pPSensor = state(idle);
}

void stateDefine(sending)
{
    PSENSORID = sending;
}

void stateDefine(idle)
{
    PSENSORID = idle;

    sensorPullTime = 100;
    Delay(sensorPullTime);

    pPSensor = state(reading);
}