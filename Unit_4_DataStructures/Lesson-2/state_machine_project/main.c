#include "CA.h"
#include "time.h"

void delay(int numOfSec)
{
    int numOfMilliSec = 1000 * numOfSec;
    time_t startTime = clock();
    while (clock() < startTime + numOfMilliSec)
        ;
}

void setup()
{
    CA_State = State(CA_Waiting);
}

int main()
{
    setup();

    while (1)
    {
        srand(time(NULL));
        CA_State();
        delay(3);
    }

    return 0;
}