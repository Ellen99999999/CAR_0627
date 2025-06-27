# CAR 리팩토링 실습 (전은실) 
코드리뷰에이전트과정 실습

# 요구사항 체크리스트
* D1 : O
* D2 : O
* D3 : O
* D4 : O
* D5 : O

# 파일 구성
미션별로 솔루션 두 개로 나눴습니다.

## Mission 1
* 솔루션 파일 : https://github.com/Ellen99999999/CAR_0627/blob/main/Mission1/Mission1/Mission1.sln
* 생성한 파일 리스트
  * Car.cpp : 기존 예제 파일을 함수 단위로 쪼갰습니다.
  * Car.h : 헤더파일을 따로 뻈습니다.
  * Types.h : 각종 enum 타입은 여기 몰아놨습니다.


## Mission 2
* 솔루션 파일 : https://github.com/Ellen99999999/CAR_0627/blob/main/Mission2/Mission2/Mission2.sln
* 생성한 파일 리스트
  * Car.h : 구현 내용을 여기 다 넣었습니다.
  * main.cpp : main() 가 여기 있습니다. 릴리즈모드로 실행하면 일반 모드, 디버그모드에서 실행하면 gtest가 동작하는 형태입니다.
  * testcase.cpp : TC 가 들어있습니다.
  * Types.h : 각종 enum 타입은 여기 몰아놨습니다.

## Coverage 결과 100% 달성
* https://github.com/Ellen99999999/CAR_0627/tree/main/Mission2/Mission2/coverage 폴더 안에 있습니다.
  * https://github.com/Ellen99999999/CAR_0627/blob/main/Mission2/Mission2/coverage/index.html 이 파일이 커버리지 결과 파일입니다.
* 커버리지 파일 생성한 실행 명령 (디버그 모드) : OpenCppCoverage.exe --sources C:\Eunshil\CAR_0627\Mission2\Mission2\Car.h --export_type=html:coverage -- .\x64\Debug\Mission2.exe
* ![image](https://github.com/user-attachments/assets/81e9ccf0-6cda-40b8-ba17-4e9abb6ba50c)
* ![image](https://github.com/user-attachments/assets/5a08fbff-b0ab-46ae-afa4-91051922007c)
* ![image](https://github.com/user-attachments/assets/5e3b1cc5-f787-4efe-b454-5e1e86455488)
* ![image](https://github.com/user-attachments/assets/35febfc0-03f0-4a9d-a09a-8ae6c8506efd)
* ![image](https://github.com/user-attachments/assets/20e4470c-6e0f-49a2-b3f6-32105c73955f)
* ![image](https://github.com/user-attachments/assets/dca29501-24f9-4a9c-ba30-aba81f880431)
* ![image](https://github.com/user-attachments/assets/80c4ffc2-9a8c-4f86-a346-8d3ed985e79d)
* ![image](https://github.com/user-attachments/assets/3fead2d6-0331-4086-9c5d-68d1982c6797)
* ![image](https://github.com/user-attachments/assets/dd66078b-f968-4382-8aac-c5804a96147e)
* ![image](https://github.com/user-attachments/assets/56063a01-217c-44e2-b58a-bdd85234ecf3)









