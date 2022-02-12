# Quadruped_Robot

## 기본 정보
사용 MCU : ATmega128
사용 언어 : C
재료 : 포맥스, AX-12 모터 12개, 블루투스 모듈(FB-155BC), Controller 휴대폰

## Motive for Selection
배틀로봇 이후 여러 개의 모터를 사용한 작품을 만들어보고 싶어서 찾아보던 중 유튜브에서 사족보행 로봇이 움직이는 것을 보고 직접 구현해보고 싶어서 결정하였다.

## Development Goals
1. 4족 하드웨어 제작
2. 4족보행 알고리즘 구현
3. UART를 통한 AX-12모터 구동
4. 스마트폰 어플을 이용한 조종
	-블루투스 통신 이용
  
## Hardware Architecture
  <img src = "https://user-images.githubusercontent.com/53519801/153713518-521709df-666f-4525-a625-aa53dfef4b1a.png" width = "800" height = "300">
(손수 그림을 그렸던 귀여웠던 1학년 시절.. )

## System Architecture
![image](https://user-images.githubusercontent.com/53519801/153713533-a5f5da05-f003-4a89-89c5-cdc298208800.png)

##Project Contents
### Hareware
  <img src = "https://user-images.githubusercontent.com/53519801/153713594-4f6c644d-5f8f-47df-800b-4f0770964958.png" width = "500" height = "300">
(사진 출처 : 광운대학교 바람 16학번 제안서)

1. 한 다리당 세 개의 관절
2. 좌 우로 움직이는 1개의 모터와 위 아래로 움직이는 2개의 모터를 사용
3. 포맥스를 이용한 몸체 제작

### Motion
![image](https://user-images.githubusercontent.com/53519801/153713613-3964624b-cb9f-4ae9-a0e2-472e1e9945d2.png)

#### 1. 직진 (후진도 같은 원리)
![image](https://user-images.githubusercontent.com/53519801/153713974-5afbcbcc-d116-4b31-ada7-92a637e74177.png)

- 3개의 동작이 하나로, 3번의 동작을 한 후 원래 모양으로 돌아온다.
- 앞 발을 먼저 앞으로 뻗은 후 뒤로 미는 마찰과 반동을 이용하여 앞으로 전진한다. (후진도 같은 원리)
- 이동할 때 최소 3개의 다리가 지면에 붙어있어 높은 안정성을 가지고 있다.

#### 2. 회전
![image](https://user-images.githubusercontent.com/53519801/153713722-07728cd6-450a-4435-b91e-1debc25ce8ce.png)

- 4개의 동작이 하나로, 4번의 동작을 한 후 원래 모양으로 돌아온다.
- 이동할 때 지면에 3개의 다리가 붙어있어 높은 안정성을 가지고 있다.

### Controller
![image](https://user-images.githubusercontent.com/53519801/153714024-0f2a5b97-f4a2-4db2-8158-d174633573bb.png)

Bluetooth Controller 어플을 활용하였다.
  <img src = "https://user-images.githubusercontent.com/53519801/153714094-5db1d5a3-2503-4e88-a83d-fb14123f8771.png" width = "300" height = "600">

1. 어플의 버튼을 클릭할 때 마다 특정한 값은 전송한다.
2. Atmega128에서 값을 수신하여 변수에 저장한다.
3. 값에 맞는 동작을 실행한다.

## Project Scenarios
1. 평지에 로봇을 놓는다.
2. 스마트폰 조작에 따라 움직이는지 확인한다.

## Project Schedule
![image](https://user-images.githubusercontent.com/53519801/153714104-2e6f623c-5227-4c90-9126-f9825216254b.png)
(2018년 일정입니다.)
