/*
CA.h
Mohamed Magdi
16 JUL 2023
*/

#ifndef CA_H_
#define CA_H_

#include "state.h"

enum
{
    CA_Waiting,
    CA_Driving
} CA_STATE_ID;

void StateDefine(CA_Driving);
void StateDefine(CA_Waiting);

#endif