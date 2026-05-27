#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3);  // RX, TX

void stopMotors() {
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void setup() {
  BT.begin(9600);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  stopMotors();
}

void loop() {

  if (BT.available()) {
    char c = BT.read();

    // FORWARD
    if (c == 'F') {
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      delay(400);
      stopMotors();
    }

    // BACKWARD
    else if (c == 'B') {
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      delay(400);
      stopMotors();
    }

    // LEFT
    else if (c == 'L') {
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      delay(250);
      stopMotors();
    }

    // RIGHT
    else if (c == 'R') {
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      delay(250);
      stopMotors();
    }

    // STOP
    else if (c == 'S') {
      stopMotors();
    }
  }
}