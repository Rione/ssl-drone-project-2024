#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "setup.h"

#define MAX_POWER 220

int motor_power[4];
float roll_target;
float pitch_target;

void Control() {
      motor_power[0] = 175;
      motor_power[1] = 175;
      motor_power[2] = 175;
      motor_power[3] = 175;

      roll_target -= (roll > 0 ? 0.002 : -0.002);
      pitch_target -= (pitch > 0 ? 0.002 : -0.002);
      roll_target = 0;
      pitch_target = 0;

#ifdef DEBUG
      MySerial.print("Roll: ");
      MySerial.print(roll_target);
      MySerial.print("  Pitch: ");
      MySerial.print(pitch_target);
      MySerial.print("\n");
#endif

      rollPID.Compute(roll, roll_target);
      pitchPID.Compute(pitch, pitch_target);

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
      if (abs(roll) < 45 && abs(pitch) < 45) {
            analogWrite(MOTOR_1, motor_power[0]);
            analogWrite(MOTOR_2, motor_power[1]);
            analogWrite(MOTOR_3, motor_power[2]);
            analogWrite(MOTOR_4, motor_power[3]);
      }
}

#endif