#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Types.h"
#include "Car.h"
#include "CarFactory.cpp"
//#define CLEAR_SCREEN "\033[H\033[2J"

#ifdef _DEBUG
#include "gmock/gmock.h"
using namespace testing;

int main()
{
    InitGoogleMock();
    return RUN_ALL_TESTS();
}
#else

int main()
{
    CarFactory carFac;
    carFac.nStep = CarType_Q;
    while (1)
    {
        carFac.ShowPrint();

        bool bContinue = carFac.CheckInput();
        if (bContinue == false) return 0; // exit

        bool bValid = carFac.CheckValidity();
        if (bValid == false) continue;

        carFac.Process();
    }
}

#endif