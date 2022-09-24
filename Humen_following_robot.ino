/*Human following robot with arduino.
  created by the SriTu Hobby team.
  Read the code below and use it for any of your creations.
*/

#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int Speed = 200;

#define sensor1 A0
#define sensor2 A1

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
}

void loop() {

  bool value1 = digitalRead(sensor1);
  bool value2 = digitalRead(sensor2);
  Serial.println(value2);
  Serial.println(value1);

  if (value1 == 0 && value2 == 0 ) {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  } else if (value1 == 1 && value2 == 1) {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  } else if (value1 == 0 && value2 == 1) {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  } else if (value1 == 1 && value2 == 0) {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
}
