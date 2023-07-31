/**
 *****************************************************************************
 * @project        : Pressure_Controller
 * @file           : state.h
 * @author         : Mohamed Magdi
 * @Created on     : Jul 27, 2023
 ******************************************************************************
 */

#ifndef STATE_H_
#define STATE_H_

#define stateDefine(stateFun) ST_##stateFun()
#define state(state) ST_##state

void GetPressureVal(int pVal);
void highPressureDetected();
void StartAlarm();
void StopAlarm();

#endif