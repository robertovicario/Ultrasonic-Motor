#include <Servo.h>

const int servoPin = 8;
const int echoPin = 9;
const int trigPin = 10;

Servo servoMotor;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servoMotor.attach(servoPin);
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance >= 5 && distance <= 200) {
    int angle = map(distance, 5, 200, 0, 180);
    servoMotor.write(angle);
  } else {
    servoMotor.write(90);
  }

  delay(100);
}
