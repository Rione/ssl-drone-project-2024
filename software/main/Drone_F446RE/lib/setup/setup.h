#ifndef _SETUP_H_
#define _SETUP_H_

#include <Adafruit_BNO055.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <pindef.h>
#include <utility/imumaths.h>

#include "control.h"
#include "pid.h"

#define PWM_FREQ 250000  //(kHz)

SoftwareSerial MySerial(PB4, PB3);

// Check I2C device address and correct line below (by default address is 0x29 or 0x28)
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28, &Wire);

PID rollPID;
PID pitchPID;

float yaw, pitch, roll;

void BnoSetup() {
      Wire.setSDA(PC9);
      Wire.setSCL(PA8);
      Wire.begin();

      /* Initialise the sensor */
      if (!bno.begin()) {
            /* There was a problem detecting the BNO055 ... check your connections */
            MySerial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
            while (1);
      }

      bno.setExtCrystalUse(true);
}

#endif