//#include <BlynkSimpleCurieBLE.h>
#define BLYNK_PRINT Serial
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10,11);//RX, 
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>
//#include <BlynkSimpleStream.h>
//#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_MS_PWMServoDriver.h"

char auth[] = "aea48e30619145f0ba3c2dfa106b033d";

//BLEPeripheral  blePeripheral;
SoftwareSerial SerialBLE(10,11);//RX, TX

// Create the motor shield object with the default I2C address
//Adafruit_MotorShield AFMS = Adafruit_MotorShield();
//
//// Select which 'port' M1, M2, M3 or M4.
//// Just using two motors
//Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
//Adafruit_DCMotor *motor2 = AFMS.getMotor(2);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  SerialBLE.begin(9600);
  Serial.print("Starting...\n");
//
//  blePeripheral.setLocalName("ArduinoRover");
//  blePeripheral.setDeviceName("ArduinoRover");
//  blePeripheral.setAppearance(384);

//  Blynk.begin(auth, blePeripheral);
  Blynk.begin(SerialBLE, auth);
//  Blynk.begin(auth);

//    blePeripheral.begin();
  Serial.println("Waiting for connections...");
//  Serial.println("Adafruit Motorshield v2 - DC Motor");


//  AFMS.begin();  // create with the default frequency 1.6KHz
//  // Set the speed to start, from 0 (off) to 255 (max speed)
//  motor1->setSpeed(225);
//  motor2->setSpeed(225);
}

void loop() {
  // put your main code here, to run repeatedly:  
  Blynk.run();
//  blePeripheral.poll();

}
//BLYNK_WRITE(V0)
//{
//  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
//  // You can also use:
//  // String i = param.asStr();
//  // double d = param.asDouble();
//  Serial.print("V0 Slider value is: ");
//  Serial.println(pinValue);
//  motor1->setSpeed(pinValue);
//  motor2->setSpeed(pinValue);
//  //motor3->setSpeed(pinValue);
//  //motor4->setSpeed(pinValue);
//}
//
//// Motor 1 Forward
//BLYNK_WRITE(V1)
//{
//  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
//  Serial.print("Motor 1 Forward: ");
//  Serial.println(pinValue);
//  if (pinValue == 1) {
//    motor1->run(FORWARD);
//    //motor3->run(FORWARD);
//  }
//  if (pinValue == 0) {
//    motor1->run(RELEASE);
//    //motor3->run(RELEASE);
//  }
//}
//
//
//// Motor 2 Forward
//BLYNK_WRITE(V2)
//{
//  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
//  Serial.print("Motor 2 Forward: ");
//  Serial.println(pinValue);
//  if (pinValue == 1) {
//    motor2->run(FORWARD);
//    //motor4->run(FORWARD);
//  }
//  if (pinValue == 0) {
//    motor2->run(RELEASE);
//    //motor4->run(RELEASE);
//  }
//}
//
//// Motor 1 Backward
//BLYNK_WRITE(V3)
//{
//  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
//  Serial.print("Motor 1 Backward: ");
//  Serial.println(pinValue);
//  if (pinValue == 1) {
//    motor1->run(BACKWARD);
//    //motor3->run(BACKWARD);
//  }
//  if (pinValue == 0) {
//    motor1->run(RELEASE);
//    //motor3->run(RELEASE);
//  }
//}
//
//// Motor 2 Backward
//BLYNK_WRITE(V4)
//{
//  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
//  Serial.print("Motor 2 Backward: ");
//  Serial.println(pinValue);
//  if (pinValue == 1) {
//    motor2->run(BACKWARD);
//    //motor4->run(BACKWARD);
//  }
//  if (pinValue == 0) {
//    motor2->run(RELEASE);
//    //motor4->run(RELEASE);
//  }
//}
