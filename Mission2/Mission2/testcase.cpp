#include "gmock/gmock.h"
#include "Types.h"
#include "Car.h"


using namespace testing;


class TestFixture : public Test {
public:

};

TEST_F(TestFixture, sedan1) {
	CarSedan* pCar = new CarSedan();	
	pCar->SetBreakSystem(1);
	pCar->SetEngine(1);
	pCar->SetSteeringSystem(1);
	bool result = pCar->isValidCar();
	EXPECT_EQ(result, true);

	pCar->SetEngine(2);
	pCar->SetBreakSystem(2);
	pCar->SetSteeringSystem(2);
	result = pCar->isValidCar();
	EXPECT_EQ(result, false);

	pCar->SetEngine(3);
	pCar->SetBreakSystem(3);
	pCar->SetSteeringSystem(3);
	result = pCar->isValidCar();
	EXPECT_EQ(result, false);

	pCar->SetEngine(1);
	pCar->SetBreakSystem(2);
	pCar->SetSteeringSystem(3);
	result = pCar->isValidCar();
	EXPECT_EQ(result, false);

	pCar->SetEngine(3);
	pCar->SetBreakSystem(2);
	pCar->SetSteeringSystem(1);
	result = pCar->isValidCar();
	EXPECT_EQ(result, false);

	pCar->SetEngine(3);
	pCar->SetBreakSystem(2);
	pCar->SetSteeringSystem(3);
	result = pCar->isValidCar();
	EXPECT_EQ(result, false);
}


TEST_F(TestFixture, suv1) {
	CarSUV* pCar = new CarSUV();
	pCar->SetBreakSystem(1);
	pCar->SetEngine(1);
	pCar->SetSteeringSystem(1);
	bool result = pCar->isValidCar();
	EXPECT_EQ(result, true);

	pCar->SetEngine(2);
	pCar->SetBreakSystem(2);
	pCar->SetSteeringSystem(2);
	result = pCar->isValidCar();
	EXPECT_EQ(result, false);

	pCar->SetEngine(3);
	pCar->SetBreakSystem(3);
	pCar->SetSteeringSystem(3);
	result = pCar->isValidCar();
	EXPECT_EQ(result, false);

	pCar->SetEngine(1);
	pCar->SetBreakSystem(2);
	pCar->SetSteeringSystem(3);
	result = pCar->isValidCar();
	EXPECT_EQ(result, true);

	pCar->SetEngine(3);
	pCar->SetBreakSystem(2);
	pCar->SetSteeringSystem(1);
	result = pCar->isValidCar();
	EXPECT_EQ(result, true);
}


TEST_F(TestFixture, truck1) {
	CarTruck* pCar = new CarTruck();
	pCar->SetBreakSystem(1);
	pCar->SetEngine(1);
	pCar->SetSteeringSystem(1);
	bool result = pCar->isValidCar();
	EXPECT_EQ(result, false);

	pCar->SetEngine(2);
	pCar->SetBreakSystem(2);
	pCar->SetSteeringSystem(2);
	result = pCar->isValidCar();
	EXPECT_EQ(result, true);

	pCar->SetEngine(3);
	pCar->SetBreakSystem(3);
	pCar->SetSteeringSystem(3);
	result = pCar->isValidCar();
	EXPECT_EQ(result, false);

	pCar->SetEngine(1);
	pCar->SetBreakSystem(2);
	pCar->SetSteeringSystem(3);
	result = pCar->isValidCar();
	EXPECT_EQ(result, true);

	pCar->SetEngine(3);
	pCar->SetBreakSystem(2);
	pCar->SetSteeringSystem(1);
	result = pCar->isValidCar();
	EXPECT_EQ(result, false);
}



TEST_F(TestFixture, sedan2) {
	CarSedan* pCar = new CarSedan();
	pCar->SetEngine(1);
	pCar->SetBreakSystem(1);
	pCar->SetSteeringSystem(1);
	bool result = pCar->isValidCar();
	EXPECT_EQ(result, true);
}


TEST_F(TestFixture, suv2) {
	CarSUV* pCar = new CarSUV();
	pCar->SetEngine(1);
	pCar->SetBreakSystem(1);
	pCar->SetSteeringSystem(1);
	bool result = pCar->isValidCar();
	EXPECT_EQ(result, true);
}


TEST_F(TestFixture, truck2) {
	CarTruck* pCar = new CarTruck();
	pCar->SetEngine(2);
	pCar->SetBreakSystem(2);
	pCar->SetSteeringSystem(2);
	bool result = pCar->isValidCar();
	EXPECT_EQ(result, true);
}

TEST_F(TestFixture, factorySedan) {
	ICar* pCar = new CarSedan();
	pCar->SetBreakSystem(2);
	pCar->SetEngine(2);
	pCar->SetSteeringSystem(2);
	bool result = pCar->isValidCar();
	EXPECT_EQ(result, false);

	pCar->SetBreakSystem(1);
	pCar->SetEngine(1);
	pCar->SetSteeringSystem(1);
	result = pCar->isValidCar();
	EXPECT_EQ(result, true);
}

TEST_F(TestFixture, factorySUV) {
	ICar* pCar = new CarSUV();
	pCar->SetBreakSystem(2);
	pCar->SetEngine(2);
	pCar->SetSteeringSystem(2);
	bool result = pCar->isValidCar();
	EXPECT_EQ(result, false);

	pCar->SetBreakSystem(1);
	pCar->SetEngine(1);
	pCar->SetSteeringSystem(1);
	result = pCar->isValidCar();
	EXPECT_EQ(result, true);
}


TEST_F(TestFixture, factoryTruck) {
	ICar* pCar = new CarTruck();
	pCar->SetBreakSystem(2);
	pCar->SetEngine(2);
	pCar->SetSteeringSystem(2);
	bool result = pCar->isValidCar();
	EXPECT_EQ(result, true);

	pCar->SetBreakSystem(1);
	pCar->SetEngine(1);
	pCar->SetSteeringSystem(1);
	result = pCar->isValidCar();
	EXPECT_EQ(result, false);
}


TEST_F(TestFixture, factoryFuncSedan) {
	CarFactory* pFac = new CarFactory();
	pFac->SelectCarType(1);

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				pFac->SelectEngine(i);
				pFac->SelectbrakeSystem(j);
				pFac->SelectSteeringSystem(k);
				pFac->TestProducedCar();
				pFac->RunProducedCar();
			}
		}
	}
}

TEST_F(TestFixture, factoryFuncSUV) {
	CarFactory* pFac = new CarFactory();
	pFac->SelectCarType(2);

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				pFac->SelectEngine(i);
				pFac->SelectbrakeSystem(j);
				pFac->SelectSteeringSystem(k);
				pFac->TestProducedCar();
				pFac->RunProducedCar();
			}
		}
	}
}

TEST_F(TestFixture, factoryFuncTruck) {
	CarFactory* pFac = new CarFactory();
	pFac->SelectCarType(3);

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				pFac->SelectEngine(i);
				pFac->SelectbrakeSystem(j);
				pFac->SelectSteeringSystem(k);
				pFac->TestProducedCar();
				pFac->RunProducedCar();
			}
		}
	}
}

TEST_F(TestFixture, factoryFuncEtc1) {
	CarFactory* pFac = new CarFactory();
	pFac->nStep = CarType_Q;
	pFac->ShowPrint();

	pFac->nStep = Engine_Q;
	pFac->ShowPrint();

	pFac->nStep = brakeSystem_Q;
	pFac->ShowPrint();

	pFac->nStep = SteeringSystem_Q;
	pFac->ShowPrint();

	pFac->nStep = Run_Test;
	pFac->ShowPrint();
}