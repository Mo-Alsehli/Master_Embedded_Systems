#include "CA.h"

// Main Variables:
int speed = 0;
int distance = 0;
int threshold = 50;

#define randnum(min, max) \
    ((rand() % (int)(((max) + 1) - (min))) + (min))

void (*CA_State)();
int GenRandNum(int min, int max, int count);

void StateDefine(CA_Waiting)
{
    CA_STATE_ID = CA_Waiting;
    speed = 0;

    distance = randnum(45, 55);

    if (distance <= threshold)
    {
        CA_State = State(CA_Waiting);
    }
    else
    {
        CA_State = State(CA_Driving);
    }

    printf("CA Waiting State: distance = %d, speed = %d \n", distance, speed);
}

void StateDefine(CA_Driving)
{
    CA_STATE_ID = CA_Driving;
    speed = 30;

    distance = randnum(45, 55);

    if (distance <= threshold)
    {
        CA_State = State(CA_Waiting);
    }
    else
    {
        CA_State = State(CA_Driving);
    }

    printf("CA Driving State: distance = %d, speed = %d \n", distance, speed);
}
