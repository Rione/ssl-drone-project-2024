#include <Arduino.h>
#include <SoftwareSerial.h>

#include "gyro.h"

#define MOTOR_1 PB5
#define MOTOR_2 PB7
#define MOTOR_3 PA0
#define MOTOR_4 PA1
#define LED_1 PB13
#define LED_2 PB15
#define LED_3 PA5
#define LED_4 PA7

Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28, &Wire);
GYRO gyro(&bno);

SoftwareSerial MySerial(PB4, PB3);


void setup() {
      MySerial.begin(115200);
      MySerial.println("START");
      pinMode(MOTOR_1, OUTPUT);
      pinMode(MOTOR_2, OUTPUT);
      pinMode(MOTOR_3, OUTPUT);
      pinMode(MOTOR_4, OUTPUT);
      pinMode(LED_1, OUTPUT);
      pinMode(LED_2, OUTPUT);
      pinMode(LED_3, OUTPUT);
      pinMode(LED_4, OUTPUT);

      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, HIGH);
      digitalWrite(LED_4, HIGH);

      Wire.setSDA(PC_7);
      Wire.setSCL(PC_6);
      Wire.begin();
      gyro.init();
      gyro.setOffset();
      delay(100);

      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, LOW);
      digitalWrite(LED_3, LOW);
      digitalWrite(LED_4, LOW);
}
void loop() {
      // analogWrite(MOTOR_1, 200);
      // analogWrite(MOTOR_2, 200);
      // analogWrite(MOTOR_3, 200);
      // analogWrite(MOTOR_4, 200);
      // delay(1000);
      gyro.read();
      int yaw = gyro.deg;
      MySerial.printf("%d\n", yaw);
      // if (yaw < 0) {
      //       digitalWrite(LED_1, HIGH);
      //       digitalWrite(LED_2, HIGH);
      //       digitalWrite(LED_3, HIGH);
      //       digitalWrite(LED_4, HIGH);
      // } else {
      //       digitalWrite(LED_1, LOW);
      //       digitalWrite(LED_2, LOW);
      //       digitalWrite(LED_3, LOW);
      //       digitalWrite(LED_4, LOW);
      // }
}