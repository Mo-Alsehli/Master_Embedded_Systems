/*
state.h
Mohamed Magdi
16 JUL 2023
*/

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

#define StateDefine(stateFun) ST_##stateFun()
#define State(state) ST_##state

extern void (*CA_State)();

#endif