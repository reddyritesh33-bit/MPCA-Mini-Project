#include <Servo.h>

Servo myServo;

int irPin = 2;
int servoPin = 7;

bool triggered = false;

void setup() {
  pinMode(irPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(90);
}

void loop() {
  int sensorValue = digitalRead(irPin);

  if (sensorValue == LOW && !triggered) {
    triggered = true;

    myServo.write(180);
    delay(5000);
    myServo.write(90);
  }

  // Reset trigger when object removed
  if (sensorValue == HIGH) {
    triggered = false;
  }
}