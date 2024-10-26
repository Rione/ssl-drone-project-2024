#include <Arduino.h>

#include "gyro.h"

#define MOTOR_1 PB_5
#define MOTOR_2 PB_7
#define MOTOR_3 PA_0
#define MOTOR_4 PA_1
#define LED_1 PB_13
#define LED_2 PB_15
#define LED_3 PA_5
#define LED_4 PA_7

// Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28, &Wire);
// GYRO gyro(&bno);

HardwareSerial serial(PB_6, NC);

void setup() {
      serial.begin(9600);
      serial.printf("START");
      pinMode(MOTOR_1, OUTPUT);
      pinMode(MOTOR_2, OUTPUT);
      pinMode(MOTOR_3, OUTPUT);
      pinMode(MOTOR_4, OUTPUT);
      pinMode(LED_1, OUTPUT);
      pinMode(LED_2, OUTPUT);
      pinMode(LED_3, OUTPUT);
      pinMode(LED_4, OUTPUT);

      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, LOW);
      digitalWrite(LED_3, LOW);
      digitalWrite(LED_4, LOW);

      Wire.setSDA(PC_7);
      Wire.setSCL(PC_6);
      Wire.begin();
      // gyro.init();
      // gyro.setOffset();
}
void loop() {
      // analogWrite(MOTOR_1, 200);
      // analogWrite(MOTOR_2, 200);
      // analogWrite(MOTOR_3, 200);
      // analogWrite(MOTOR_4, 200);
      // delay(1000);
      // int yaw = gyro.read();
      // serial.printf("%d¥n", yaw);
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, HIGH);
      digitalWrite(LED_4, HIGH);
}