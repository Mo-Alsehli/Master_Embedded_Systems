/**
 *****************************************************************************
 * @project        : Pressure_Controller
 * @file           : main.c
 * @author         : Mohamed Magdi
 * @Created on     : Jul 27, 2023
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "time.h"

#include "driver.h"
#include "alarmMonitor.h"
#include "pressureController.h"
#include "pressureSensor.h"
#include "alarmActuator.h"

void setup()
{
	pPSensor = state(reading);
	pCState = GetPressureVal;
	pAlarmMon = state(alarmMonOff);
	pAlarmAct = state(alarmActWaiting);
}

int main()
{
	GPIO_INITIALIZATION();
	setup();
	while (1)
	{
		// Implement your Design
		pPSensor();
		pCState();
		pAlarmMon();
		pAlarmAct();
	}
}
