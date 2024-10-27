#include "setup.h"

#define DEBUG

void loop(void) {
      analogWrite(MOTOR_1, 100);
      analogWrite(MOTOR_2, 100);
      analogWrite(MOTOR_3, 100);
      analogWrite(MOTOR_4, 100);
      delay(1000);
      imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);

#ifdef DEBUG
      MySerial.print("X: ");
      MySerial.print(euler.x());
      MySerial.print(" Y: ");
      MySerial.print(euler.y());
      MySerial.print(" Z: ");
      MySerial.print(euler.z());
      MySerial.print("\t\t");
#endif
}
