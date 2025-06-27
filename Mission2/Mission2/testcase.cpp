#include "gmock/gmock.h"
#include "Types.h"
#include "Car.h"


using namespace testing;


class TestFixture : public Test {
public:
	CarInfo stInfo = {};

};

TEST_F(TestFixture, sedan1) {
	CarSedan* pCar = new CarSedan();	
	stInfo = { 1,1,1,1 };	
	bool result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);

	stInfo = { 1,2,1,1 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);

	stInfo = { 1,2,3,1 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);

	stInfo = { 1,2,3,4 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);
}


TEST_F(TestFixture, suv1) {
	CarSUV* pCar = new CarSUV();
	stInfo = { 2,1,1,1 };
	bool result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);

	stInfo = { 2,2,1,1 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, false);

	stInfo = { 2,2,3,1 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, false);

	stInfo = { 2,2,3,4 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, false);

	stInfo = { 2,1,1,1 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);

	stInfo = { 2,3,3,1 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);

	stInfo = { 2,3,1,1 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);
}


TEST_F(TestFixture, truck1) {
	CarTruck* pCar = new CarTruck();
	stInfo = { 3,1,1,1 };
	bool result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);

	stInfo = { 3,2,1,1 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);

	stInfo = { 3,2,3,1 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);

	stInfo = { 3,2,3,4 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);

	stInfo = { 3,1,1,4 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);
}



TEST_F(TestFixture, sedan2) {
	CarSedan* pCar = new CarSedan();
	stInfo = { 1,1,1,1 };
	pCar->SetEngine(1);
	pCar->SetBreakSystem(1);
	pCar->SetSteeringSystem(1);
	bool result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);
}


TEST_F(TestFixture, suv2) {
	CarSUV* pCar = new CarSUV();
	stInfo = { 2,1,1,1 };
	pCar->SetEngine(1);
	pCar->SetBreakSystem(1);
	pCar->SetSteeringSystem(1);
	bool result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);
}


TEST_F(TestFixture, truck2) {
	CarTruck* pCar = new CarTruck();
	stInfo = { 3,2,2,2 };
	pCar->SetEngine(2);
	pCar->SetBreakSystem(2);
	pCar->SetSteeringSystem(2);
	bool result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);
}

TEST_F(TestFixture, factorySedan) {
	ICar* pCar = new CarSedan();
	pCar->SetBreakSystem(2);
	pCar->SetEngine(2);
	pCar->SetSteeringSystem(2);
	stInfo = {1,2,2,2};
	bool result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, false);

	pCar->SetBreakSystem(1);
	pCar->SetEngine(1);
	pCar->SetSteeringSystem(1);
	stInfo = { 1,1,1,1 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);
}

TEST_F(TestFixture, factorySUV) {
	ICar* pCar = new CarSUV();
	pCar->SetBreakSystem(2);
	pCar->SetEngine(2);
	pCar->SetSteeringSystem(2);
	stInfo = { 2,2,2,2 };
	bool result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, false);

	pCar->SetBreakSystem(1);
	pCar->SetEngine(1);
	pCar->SetSteeringSystem(1);
	stInfo = { 2,1,1,1 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);
}


TEST_F(TestFixture, factoryTruck) {
	ICar* pCar = new CarTruck();
	pCar->SetBreakSystem(2);
	pCar->SetEngine(2);
	pCar->SetSteeringSystem(2);
	stInfo = { 3,2,2,2 };
	bool result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, true);

	pCar->SetBreakSystem(1);
	pCar->SetEngine(1);
	pCar->SetSteeringSystem(1);
	stInfo = { 3,1,1,1 };
	result = pCar->isValidCar(stInfo);
	EXPECT_EQ(result, false);
}


TEST_F(TestFixture, factoryFunc1) {
	CarFactory* pFac = new CarFactory();
	pFac->ShowPrint();
	pFac->SelectCarType(1);
	pFac->SelectEngine(1);
	pFac->SelectbrakeSystem(1);
	pFac->SelectSteeringSystem(1);
	pFac->TestProducedCar();
	pFac->RunProducedCar();
}

TEST_F(TestFixture, factoryFunc2) {
	CarFactory* pFac = new CarFactory();
	pFac->SelectCarType(2);
	pFac->SelectEngine(2);
	pFac->SelectbrakeSystem(2);
	pFac->SelectSteeringSystem(2);
	pFac->TestProducedCar();
	pFac->RunProducedCar();
}

TEST_F(TestFixture, factoryFunc3) {
	CarFactory* pFac = new CarFactory();
	pFac->SelectCarType(3);
	pFac->SelectEngine(3);
	pFac->SelectbrakeSystem(3);
	pFac->SelectSteeringSystem(3);
	pFac->TestProducedCar();
	pFac->RunProducedCar();
}
