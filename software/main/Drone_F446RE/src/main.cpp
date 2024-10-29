#include "control.h"

// #define DEBUG

void setup(void) {
      MySerial.begin(115200);
      while (!Serial) delay(10);
      MySerial.println("DRONE START");

      pinMode(LED_1, OUTPUT);
      pinMode(LED_2, OUTPUT);
      pinMode(LED_3, OUTPUT);
      pinMode(LED_4, OUTPUT);
      digitalWrite(LED_2, HIGH);
      delay(200);
      digitalWrite(LED_1, HIGH);
      delay(200);
      digitalWrite(LED_4, HIGH);
      delay(200);
      digitalWrite(LED_3, HIGH);

      rollPID.SelectType(PID_TYPE);
      rollPID.SetGain(0.5, 0, 0.25);
      rollPID.SetILimit(100);

      pitchPID.SelectType(PID_TYPE);
      pitchPID.SetGain(0.5, 0, 0.25);
      pitchPID.SetILimit(100);

      BnoSetup();

      delay(2000);
      for (uint i = 1; i <= 2; i++) {
            analogWriteFrequency(i * 300);
            analogWrite(MOTOR_1, 100);
            analogWrite(MOTOR_2, 100);
            analogWrite(MOTOR_3, 100);
            analogWrite(MOTOR_4, 100);
            delay(100);
            analogWrite(MOTOR_1, 0);
            analogWrite(MOTOR_2, 0);
            analogWrite(MOTOR_3, 0);
            analogWrite(MOTOR_4, 0);
            delay(100);
      }

      analogWriteFrequency(PWM_FREQ);

      digitalWrite(LED_2, LOW);
      delay(200);
      digitalWrite(LED_1, LOW);
      delay(200);
      digitalWrite(LED_4, LOW);
      delay(200);
      digitalWrite(LED_3, LOW);
}

void loop(void) {
      while (1) {
            imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
            yaw = euler.x();
            pitch = euler.z();
            roll = euler.y();
            Control();

#ifdef DEBUG
            MySerial.print("YAW: ");
            MySerial.print(yaw);
            MySerial.print(" PITCH: ");
            MySerial.print(pitch);
            MySerial.print(" ROLL: ");
            MySerial.print(roll);
            MySerial.print("\n");
#endif
      }
}
