#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "setup.h"

#define ROLL_P 25
#define PITCH_P 25
#define YAW_P 10

#define MAX_POWER 250

int MotorPower[4];

void Control() {
      MotorPower[0] = 210;
      MotorPower[1] = 210;
      MotorPower[2] = 210;
      MotorPower[3] = 210;

      MotorPower[0] += roll * ROLL_P;
      MotorPower[1] += roll * ROLL_P;
      MotorPower[2] -= roll * ROLL_P;
      MotorPower[3] -= roll * ROLL_P;

      MotorPower[0] -= pitch * PITCH_P;
      MotorPower[1] += pitch * PITCH_P;
      MotorPower[2] += pitch * PITCH_P;
      MotorPower[3] -= pitch * PITCH_P;

      for (uint8_t i = 0; i < 4; i++) {
            if (MotorPower[i] < 0) MotorPower[i] = 0;
            if (MotorPower[i] > MAX_POWER) MotorPower[i] = MAX_POWER;
      }

      // 出力
      analogWrite(MOTOR_1, MotorPower[0]);
      analogWrite(MOTOR_2, MotorPower[1]);
      analogWrite(MOTOR_3, MotorPower[2]);
      analogWrite(MOTOR_4, MotorPower[3]);
}

#endif