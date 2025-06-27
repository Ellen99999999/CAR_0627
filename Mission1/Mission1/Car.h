#pragma once
constexpr int MS = 1000 * 1000;
int anCarInfo[10];
char buf[100];
int nStep;
int nUserInput;

void SelectCarType(int answer);
void SelectEngine(int answer);
void SelectbrakeSystem(int answer);
void SelectSteeringSystem(int answer);
void RunProducedCar();
void TestProducedCar();
void Delay(int ms);
void ShowPrint();
bool CheckInput();
bool CheckValidity();
void Process();
