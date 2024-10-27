#include "control.h"

#define DEBUG

void setup(void) {
      MySerial.begin(115200);
      while (!Serial) delay(10);
      MySerial.println("DRONE START");

      pinMode(LED_1, OUTPUT);
      pinMode(LED_2, OUTPUT);
      pinMode(LED_3, OUTPUT);
      pinMode(LED_4, OUTPUT);
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, HIGH);
      digitalWrite(LED_4, HIGH);

      analogWriteFrequency(PWM_FREQ);

      BnoSetup();

      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, LOW);
      digitalWrite(LED_3, LOW);
      digitalWrite(LED_4, LOW);
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
