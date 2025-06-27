#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "Types.h"
#define CLEAR_SCREEN "\033[H\033[2J"

class ICar;
class CarSedan;
class CarTruck;
class CarSUV;
class CarFactory;

class ICar {
public:
	virtual bool isValidCar() = 0;
	virtual void SetEngine(int v) = 0;
	virtual void SetBreakSystem(int v) = 0;
	virtual void SetSteeringSystem(int v) = 0;
};

class CarTruck : public ICar {
public:
    CarTruck() {
        myCar.nCarType = 3;
    }
    ~CarTruck() = default;
    bool isValidCar() override {
        if (myCar.nCarType != 3) return false;
        if (myCar.nEngine == WIA) return false;
        if (myCar.nBreakSystem == MANDO) return false;
        if (myCar.nBreakSystem == BOSCH_B && myCar.nStreeringSystem != BOSCH_S) return false;
        return true;
    }
    void SetEngine(int v) override {
        myCar.nEngine = v;
    }
    void SetBreakSystem(int v) override {
        myCar.nBreakSystem = v;
    }
    void SetSteeringSystem(int v) override {
        myCar.nStreeringSystem = v;
    }
private:
    CarInfo myCar = {};
};

class CarSUV : public ICar {
public:
	CarSUV() {
		myCar.nCarType = 2;
	}
	~CarSUV() = default;
	bool isValidCar() override {
        if (myCar.nCarType != 2) return false;
		if (myCar.nEngine == TOYOTA) return false;
		if (myCar.nBreakSystem == BOSCH_B && myCar.nStreeringSystem != BOSCH_S) return false;
        
		return true;
	}
	void SetEngine(int v) override {
		myCar.nEngine = v;
	}
	void SetBreakSystem(int v) override {
		myCar.nBreakSystem = v;
	}
	void SetSteeringSystem(int v) override {
		myCar.nStreeringSystem = v;
	}
private:
	CarInfo myCar = {};
};

class CarSedan : public ICar {
public:
	CarSedan() {
		myCar.nCarType = 1;
	}
	~CarSedan() = default;
	bool isValidCar() override {
		if (myCar.nCarType != 1) return false;
        if (myCar.nBreakSystem == CONTINENTAL) return false;
        if (myCar.nBreakSystem == BOSCH_B && myCar.nStreeringSystem != BOSCH_S) return false;
		return true;
	}
	void SetEngine(int v) override {
		myCar.nEngine = v;
	}
	void SetBreakSystem(int v) override {
		myCar.nBreakSystem = v;
	}
	void SetSteeringSystem(int v) override {
		myCar.nStreeringSystem = v;
	}
private:
	CarInfo myCar = {};
};


class CarFactory {
public:
    CarFactory() = default;
	const int MS = 1000 * 1000;
    CarInfo stInfo = {};
	char buf[100] = {};
	int nStep;
	int nUserInput;
	ICar* pCar = nullptr;
    
	void RunProducedCar()
    {
        if (pCar->isValidCar() == false)
        {
            if (stInfo.nEngine == 4)
            {
                printf("������ ���峪�ֽ��ϴ�.\n");
                printf("�ڵ����� �������� �ʽ��ϴ�.\n");
            }
            else
                printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
        }
        else
        {
            if (stInfo.nCarType == 1)
                printf("Car Type : Sedan\n");
            if (stInfo.nCarType == 2)
                printf("Car Type : SUV\n");
            if (stInfo.nCarType == 3)
                printf("Car Type : Truck\n");
            if (stInfo.nEngine == 1)
                printf("Engine : GM\n");
            if (stInfo.nEngine == 2)
                printf("Engine : TOYOTA\n");
            if (stInfo.nEngine == 3)
                printf("Engine : WIA\n");
            if (stInfo.nBreakSystem == 1)
                printf("Brake System : Mando");
            if (stInfo.nBreakSystem == 2)
                printf("Brake System : Continental\n");
            if (stInfo.nBreakSystem == 3)
                printf("Brake System : Bosch\n");
            if (stInfo.nStreeringSystem == 1)
                printf("SteeringSystem : Bosch\n");
            if (stInfo.nStreeringSystem == 2)
                printf("SteeringSystem : Mobis\n");

            printf("�ڵ����� ���۵˴ϴ�.\n");           
        }
    }
	void TestProducedCar()
    {
        if (stInfo.nCarType == SEDAN && stInfo.nBreakSystem == CONTINENTAL)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Sedan���� Continental������ġ ��� �Ұ�\n");
        }
        else if (stInfo.nCarType == SUV && stInfo.nEngine == TOYOTA)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("SUV���� TOYOTA���� ��� �Ұ�\n");
        }
        else if (stInfo.nCarType == TRUCK && stInfo.nEngine == WIA)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� WIA���� ��� �Ұ�\n");
        }
        else if (stInfo.nCarType == TRUCK && stInfo.nBreakSystem == MANDO)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� Mando������ġ ��� �Ұ�\n");
        }
        else if (stInfo.nBreakSystem == BOSCH_B && stInfo.nStreeringSystem != BOSCH_S)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
        }
        else
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
        }
    }
	void Delay(int ms) {
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
            printf("� ���� Ÿ���� �����ұ��?\n");
            printf("1. Sedan\n");
            printf("2. SUV\n");
            printf("3. Truck\n");
        }
        else if (nStep == Engine_Q)
        {
            printf(CLEAR_SCREEN);
            printf("� ������ ž���ұ��?\n");
            printf("0. �ڷΰ���\n");
            printf("1. GM\n");
            printf("2. TOYOTA\n");
            printf("3. WIA\n");
            printf("4. ���峭 ����\n");
        }
        else if (nStep == brakeSystem_Q)
        {
            printf(CLEAR_SCREEN);
            printf("� ������ġ�� �����ұ��?\n");
            printf("0. �ڷΰ���\n");
            printf("1. MANDO\n");
            printf("2. CONTINENTAL\n");
            printf("3. BOSCH\n");
        }
        else if (nStep == SteeringSystem_Q)
        {
            printf(CLEAR_SCREEN);
            printf("� ������ġ�� �����ұ��?\n");
            printf("0. �ڷΰ���\n");
            printf("1. BOSCH\n");
            printf("2. MOBIS\n");
        }
        else if (nStep == Run_Test)
        {
            printf(CLEAR_SCREEN);
            printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
            printf("� ������ �ұ��?\n");
            printf("0. ó�� ȭ������ ���ư���\n");
            printf("1. RUN\n");
            printf("2. Test\n");
        }
        printf("===============================\n");

        printf("INPUT > ");
    }
	bool CheckInput() {
        fgets(buf, sizeof(buf), stdin);
        // ���� ���๮�� ����
        char* context = nullptr;
        strtok_s(buf, "\r", &context);
        strtok_s(buf, "\n", &context);

        if (!strcmp(buf, "exit"))
        {
            printf("���̹���\n");
            return false;
        }
        return true;
    }
	bool CheckValidity() {
        // ���ڷ� �� ������� Ȯ��
        char* checkNumber;
        nUserInput = strtol(buf, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ
        if (*checkNumber != '\0')
        {
            printf("ERROR :: ���ڸ� �Է� ����\n");
            Delay(800);
            return false;
        }

        if (nStep == CarType_Q && !(nUserInput >= 1 && nUserInput <= 3))
        {
            printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
            Delay(800);
            return false;
        }

        if (nStep == Engine_Q && !(nUserInput >= 0 && nUserInput <= 4))
        {
            printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
            Delay(800);
            return false;
        }

        if (nStep == brakeSystem_Q && !(nUserInput >= 0 && nUserInput <= 3))
        {
            printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
            Delay(800);
            return false;
        }

        if (nStep == SteeringSystem_Q && !(nUserInput >= 0 && nUserInput <= 2))
        {
            printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
            Delay(800);
            return false;
        }

        if (nStep == Run_Test && !(nUserInput >= 0 && nUserInput <= 2))
        {
            printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
            Delay(800);
            return false;
        }

        // ó������ ���ư���
        if (nUserInput == 0 && nStep == Run_Test)
        {
            nStep = CarType_Q;
            return false;
        }

        // �������� ���ư���
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
        stInfo.nCarType = answer;
        if (answer == 1) {
            printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
            pCar = new CarSedan();
        }
        if (answer == 2) {
            printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
            pCar = new CarSUV();
        }
        if (answer == 3) {
            printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
            pCar = new CarTruck();
        }
    }

	void SelectEngine(int answer)
    {
        stInfo.nEngine = answer;
        if (answer == 1)
            printf("GM ������ �����ϼ̽��ϴ�.\n");
        if (answer == 2)
            printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
        if (answer == 3)
            printf("WIA ������ �����ϼ̽��ϴ�.\n");

        pCar->SetEngine(answer);
    }
	void SelectbrakeSystem(int answer)
    {
        stInfo.nBreakSystem = answer;
        if (answer == 1)
            printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
        if (answer == 2)
            printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
        if (answer == 3)
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
        pCar->SetBreakSystem(answer);
    }
	void SelectSteeringSystem(int answer)
    {
        stInfo.nStreeringSystem = answer;
        if (answer == 1)
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
        if (answer == 2)
            printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
        pCar->SetSteeringSystem(answer);
    }
};

