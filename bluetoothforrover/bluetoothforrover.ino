#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
#define BLYNK_PRINT Serial
#include <BlynkSimpleSerialBLE.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
//#define BLYNK_DEBUG // Optional, this enables lots of prints

#include <SoftwareSerial.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "c517e585e86249ce98435ad237a5aeea";


SoftwareSerial SerialBLE(10, 11); // RX, TX

Adafruit_MotorShield AFMS = Adafruit_MotorShield();


Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *motor2 = AFMS.getMotor(2);

void setup()
{
   Serial.println("oh boi");

  // Debug console
  Serial.begin(9600);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");
    AFMS.begin();  // create with the default frequency 1.6KHz
  // Set the speed to start, from 0 (off) to 255 (max speed)
  motor1->setSpeed(225);
  motor2->setSpeed(225);
}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  Serial.print("V0 Slider value is: ");
  Serial.println(pinValue);
  motor1->setSpeed(pinValue);
  motor2->setSpeed(pinValue);
  //motor3->setSpeed(pinValue);
  //motor4->setSpeed(pinValue);
}

// Motor 1 Forward
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.print("Motor 1 Forward: ");
  Serial.println(pinValue);
  if (pinValue == 1) {
    motor1->run(FORWARD);
    //motor3->run(FORWARD);
  }
  if (pinValue == 0) {
    motor1->run(RELEASE);
    //motor3->run(RELEASE);
  }
}


// Motor 2 Forward
BLYNK_WRITE(V2)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.print("Motor 2 Forward: ");
  Serial.println(pinValue);
  if (pinValue == 1) {
    motor2->run(FORWARD);
    //motor4->run(FORWARD);
  }
  if (pinValue == 0) {
    motor2->run(RELEASE);
    //motor4->run(RELEASE);
  }
}

// Motor 1 Backward
BLYNK_WRITE(V3)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.print("Motor 1 Backward: ");
  Serial.println(pinValue);
  if (pinValue == 1) {
    motor1->run(BACKWARD);
    //motor3->run(BACKWARD);
  }
  if (pinValue == 0) {
    motor1->run(RELEASE);
    //motor3->run(RELEASE);
  }
}

// Motor 2 Backward
BLYNK_WRITE(V4)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.print("Motor 2 Backward: ");
  Serial.println(pinValue);
  if (pinValue == 1) {
    motor2->run(BACKWARD);
    //motor4->run(BACKWARD);
  }
  if (pinValue == 0) {
    motor2->run(RELEASE);
    //motor4->run(RELEASE);
  }
}
