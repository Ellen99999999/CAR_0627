#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Types.h"
#include "Car.h"
#define CLEAR_SCREEN "\033[H\033[2J"


void Delay(int ms)
{
    volatile int sum = 0;
    ms *= MS;
    for (int t = 0; t < ms; t++)
        sum++;
}
void ShowPrint()
{
    if (nStep == CarType_Q)
    {
        printf(CLEAR_SCREEN);

        printf("        ______________\n");
        printf("       /|            | \n");
        printf("  ____/_|_____________|____\n");
        printf(" |                      O  |\n");
        printf(" '-(@)----------------(@)--'\n");
        printf("===============================\n");
        printf("어떤 차량 타입을 선택할까요?\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Truck\n");
    }
    else if (nStep == Engine_Q)
    {
        printf(CLEAR_SCREEN);
        printf("어떤 엔진을 탑재할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. 고장난 엔진\n");
    }
    else if (nStep == brakeSystem_Q)
    {
        printf(CLEAR_SCREEN);
        printf("어떤 제동장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }
    else if (nStep == SteeringSystem_Q)
    {
        printf(CLEAR_SCREEN);
        printf("어떤 조향장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }
    else if (nStep == Run_Test)
    {
        printf(CLEAR_SCREEN);
        printf("멋진 차량이 완성되었습니다.\n");
        printf("어떤 동작을 할까요?\n");
        printf("0. 처음 화면으로 돌아가기\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }
    printf("===============================\n");

    printf("INPUT > ");
}

bool CheckInput() {
    fgets(buf, sizeof(buf), stdin);
    // 엔터 개행문자 제거
    char* context = nullptr;
    strtok_s(buf, "\r", &context);
    strtok_s(buf, "\n", &context);

    if (!strcmp(buf, "exit"))
    {
        printf("바이바이\n");
        return false;
    }
    return true;

}
bool CheckValidity() {
    // 숫자로 된 대답인지 확인
    char* checkNumber;
    nUserInput = strtol(buf, &checkNumber, 10); // 문자열을 10진수로 변환
    if (*checkNumber != '\0')
    {
        printf("ERROR :: 숫자만 입력 가능\n");
        Delay(800);
        return false;
    }

    if (nStep == CarType_Q && !(nUserInput >= 1 && nUserInput <= 3))
    {
        printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
        Delay(800);
        return false;
    }

    if (nStep == Engine_Q && !(nUserInput >= 0 && nUserInput <= 4))
    {
        printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
        Delay(800);
        return false;
    }

    if (nStep == brakeSystem_Q && !(nUserInput >= 0 && nUserInput <= 3))
    {
        printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
        Delay(800);
        return false;
    }

    if (nStep == SteeringSystem_Q && !(nUserInput >= 0 && nUserInput <= 2))
    {
        printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
        Delay(800);
        return false;
    }

    if (nStep == Run_Test && !(nUserInput >= 0 && nUserInput <= 2))
    {
        printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
        Delay(800);
        return false;
    }

    // 처음으로 돌아가기
    if (nUserInput == 0 && nStep == Run_Test)
    {
        nStep = CarType_Q;
        return false;
    }

    // 이전으로 돌아가기
    if (nUserInput == 0 && nStep >= 1)
    {
        nStep -= 1;
        return false;
    }
    return true;
}
void Process() {
    if (nStep == CarType_Q)
    {
        SelectCarType(nUserInput);
        Delay(800);
        nStep = Engine_Q;
    }
    else if (nStep == Engine_Q)
    {
        SelectEngine(nUserInput);
        Delay(800);
        nStep = brakeSystem_Q;
    }
    else if (nStep == brakeSystem_Q)
    {
        SelectbrakeSystem(nUserInput);
        Delay(800);
        nStep = SteeringSystem_Q;
    }
    else if (nStep == SteeringSystem_Q)
    {
        SelectSteeringSystem(nUserInput);
        Delay(800);
        nStep = Run_Test;
    }
    else if (nStep == Run_Test && nUserInput == 1)
    {
        RunProducedCar();
        Delay(2000);
    }
    else if (nStep == Run_Test && nUserInput == 2)
    {
        printf("Test...\n");
        Delay(1500);
        TestProducedCar();
        Delay(2000);
    }
}


void SelectCarType(int answer)
{
    anCarInfo[CarType_Q] = answer;
    if (answer == 1)
        printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
    if (answer == 2)
        printf("차량 타입으로 SUV을 선택하셨습니다.\n");
    if (answer == 3)
        printf("차량 타입으로 Truck을 선택하셨습니다.\n");
}

void SelectEngine(int answer)
{
    anCarInfo[Engine_Q] = answer;
    if (answer == 1)
        printf("GM 엔진을 선택하셨습니다.\n");
    if (answer == 2)
        printf("TOYOTA 엔진을 선택하셨습니다.\n");
    if (answer == 3)
        printf("WIA 엔진을 선택하셨습니다.\n");
}

void SelectbrakeSystem(int answer)
{
    anCarInfo[brakeSystem_Q] = answer;
    if (answer == 1)
        printf("MANDO 제동장치를 선택하셨습니다.\n");
    if (answer == 2)
        printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
    if (answer == 3)
        printf("BOSCH 제동장치를 선택하셨습니다.\n");
}

void SelectSteeringSystem(int answer)
{
    anCarInfo[SteeringSystem_Q] = answer;
    if (answer == 1)
        printf("BOSCH 조향장치를 선택하셨습니다.\n");
    if (answer == 2)
        printf("MOBIS 조향장치를 선택하셨습니다.\n");
}

bool isValidCar()
{
    if (anCarInfo[CarType_Q] == SEDAN && anCarInfo[brakeSystem_Q] == CONTINENTAL)
    {
        return false;
    }
    else if (anCarInfo[CarType_Q] == SUV && anCarInfo[Engine_Q] == TOYOTA)
    {
        return false;
    }
    else if (anCarInfo[CarType_Q] == TRUCK && anCarInfo[Engine_Q] == WIA)
    {
        return false;
    }
    else if (anCarInfo[CarType_Q] == TRUCK && anCarInfo[brakeSystem_Q] == MANDO)
    {
        return false;
    }
    else if (anCarInfo[brakeSystem_Q] == BOSCH_B && anCarInfo[SteeringSystem_Q] != BOSCH_S)
    {
        return false;
    }
    return true;
}

void RunProducedCar()
{
    if (isValidCar() == false)
    {
        printf("자동차가 동작되지 않습니다\n");
    }
    else
    {
        if (anCarInfo[Engine_Q] == 4)
        {
            printf("엔진이 고장나있습니다.\n");
            printf("자동차가 움직이지 않습니다.\n");
        }
        else
        {
            if (anCarInfo[CarType_Q] == 1)
                printf("Car Type : Sedan\n");
            if (anCarInfo[CarType_Q] == 2)
                printf("Car Type : SUV\n");
            if (anCarInfo[CarType_Q] == 3)
                printf("Car Type : Truck\n");
            if (anCarInfo[Engine_Q] == 1)
                printf("Engine : GM\n");
            if (anCarInfo[Engine_Q] == 2)
                printf("Engine : TOYOTA\n");
            if (anCarInfo[Engine_Q] == 3)
                printf("Engine : WIA\n");
            if (anCarInfo[brakeSystem_Q] == 1)
                printf("Brake System : Mando");
            if (anCarInfo[brakeSystem_Q] == 2)
                printf("Brake System : Continental\n");
            if (anCarInfo[brakeSystem_Q] == 3)
                printf("Brake System : Bosch\n");
            if (anCarInfo[SteeringSystem_Q] == 1)
                printf("SteeringSystem : Bosch\n");
            if (anCarInfo[SteeringSystem_Q] == 2)
                printf("SteeringSystem : Mobis\n");

            printf("자동차가 동작됩니다.\n");
        }
    }
}

void TestProducedCar()
{
    if (anCarInfo[CarType_Q] == SEDAN && anCarInfo[brakeSystem_Q] == CONTINENTAL)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Sedan에는 Continental제동장치 사용 불가\n");
    }
    else if (anCarInfo[CarType_Q] == SUV && anCarInfo[Engine_Q] == TOYOTA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("SUV에는 TOYOTA엔진 사용 불가\n");
    }
    else if (anCarInfo[CarType_Q] == TRUCK && anCarInfo[Engine_Q] == WIA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 WIA엔진 사용 불가\n");
    }
    else if (anCarInfo[CarType_Q] == TRUCK && anCarInfo[brakeSystem_Q] == MANDO)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 Mando제동장치 사용 불가\n");
    }
    else if (anCarInfo[brakeSystem_Q] == BOSCH_B && anCarInfo[SteeringSystem_Q] != BOSCH_S)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
    }
    else
    {
        printf("자동차 부품 조합 테스트 결과 : PASS\n");
    }
}


int main()
{
    nStep = CarType_Q;
    while (1)
    {
        ShowPrint();

        bool bContinue = CheckInput();
        if (bContinue == false) return 0; // exit

        bool bValid = CheckValidity();
        if (bValid == false) continue;

        Process();
    }
}
