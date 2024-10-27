#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "setup.h"

#define MAX_POWER 250

int motor_power[4];

void Control() {
      motor_power[0] = 220;
      motor_power[1] = 220;
      motor_power[2] = 220;
      motor_power[3] = 220;

      rollPID.Compute(roll, 0);
      pitchPID.Compute(pitch, 0);

      motor_power[0] -= rollPID.Get();
      motor_power[1] -= rollPID.Get();
      motor_power[2] += rollPID.Get();
      motor_power[3] += rollPID.Get();

      motor_power[0] += pitchPID.Get();
      motor_power[1] -= pitchPID.Get();
      motor_power[2] -= pitchPID.Get();
      motor_power[3] += pitchPID.Get();

      for (uint8_t i = 0; i < 4; i++) {
            if (motor_power[i] < 0) motor_power[i] = 0;
            if (motor_power[i] > MAX_POWER) motor_power[i] = MAX_POWER;
      }

      // 出力
      analogWrite(MOTOR_1, motor_power[0]);
      analogWrite(MOTOR_2, motor_power[1]);
      analogWrite(MOTOR_3, motor_power[2]);
      analogWrite(MOTOR_4, motor_power[3]);
}

#endif