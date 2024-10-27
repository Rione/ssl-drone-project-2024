#ifndef _SETUP_H_
#define _SETUP_H_

#include <Adafruit_BNO055.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <pindef.h>
#include <utility/imumaths.h>

SoftwareSerial MySerial(PB4, PB3);

// Check I2C device address and correct line below (by default address is 0x29 or 0x28)
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28, &Wire);

void setup(void) {
      MySerial.begin(115200);
      while (!Serial) delay(10);  // wait for serial port to open!
      MySerial.println("DRONE START");

      pinMode(MOTOR_1, OUTPUT);
      pinMode(MOTOR_2, OUTPUT);
      pinMode(MOTOR_3, OUTPUT);
      pinMode(MOTOR_4, OUTPUT);
      pinMode(LED_1, OUTPUT);
      pinMode(LED_2, OUTPUT);
      pinMode(LED_3, OUTPUT);
      pinMode(LED_4, OUTPUT);
      analogWriteFrequency(100000);

      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, HIGH);
      digitalWrite(LED_4, HIGH);

      Wire.setSDA(PC9);
      Wire.setSCL(PA8);
      Wire.begin();

      /* Initialise the sensor */
      if (!bno.begin()) {
            /* There was a problem detecting the BNO055 ... check your connections */
            MySerial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
            while (1);
      }

      /* Display the current temperature */
      int8_t temp = bno.getTemp();
      MySerial.print("Current Temperature: ");
      MySerial.print(temp);
      MySerial.println(" C");
      MySerial.println("");

      bno.setExtCrystalUse(true);

      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, LOW);
      digitalWrite(LED_3, LOW);
      digitalWrite(LED_4, LOW);
}

#endif