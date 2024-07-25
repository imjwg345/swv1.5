#include <Servo.h>

// 서보 모터 객체 생성
Servo servoLeft;   // 왼쪽 서보 모터
Servo servoRight;  // 오른쪽 서보 모터
Servo servoUp;     // 위쪽 서보 모터
Servo servoDown;   // 아래쪽 서보 모터

void setup() {
  // 서보 모터 핀 초기화
  servoLeft.attach(9);    // 핀 9에 왼쪽 서보 모터 연결
  servoRight.attach(10);  // 핀 10에 오른쪽 서보 모터 연결
  servoUp.attach(11);     // 핀 11에 위쪽 서보 모터 연결
  servoDown.attach(12);   // 핀 12에 아래쪽 서보 모터 연결

  // 시리얼 통신 초기화
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();  // 시리얼 데이터 읽기

    // 모든 서보 모터를 중립 상태로 초기화
    servoLeft.write(90);
    servoRight.write(90);
    servoUp.write(90);
    servoDown.write(90);

    switch (command) {
      case 'L': // 왼쪽
        servoLeft.write(0);    // 왼쪽 서보 모터를 0도로 설정
        Serial.println("Moving Left");
        break;
      case 'R': // 오른쪽
        servoRight.write(180); // 오른쪽 서보 모터를 180도로 설정
        Serial.println("Moving Right");
        break;
      case 'U': // 위쪽
        servoUp.write(0);     // 위쪽 서보 모터를 0도로 설정
        Serial.println("Moving Up");
        break;
      case 'D': // 아래쪽
        servoDown.write(180); // 아래쪽 서보 모터를 180도로 설정
        Serial.println("Moving Down");
        break;
      default:
        // 알 수 없는 명령
        Serial.println("Unknown Command");
        break;
    }
  }
}
