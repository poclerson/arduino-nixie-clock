#include "fonts.h"
#include "nixies.h"

int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
int readVoltagePin = A0;

int count;
float voltage;

byte nixies = 255;

void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, nixies);
  digitalWrite(latchPin, HIGH);
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(115200);
  beginMatrix();
}

void loop() {
  int currentMillis = millis();
  if (currentMillis % 10 != 0) {
    return;
  }

  writeVoltage(readVoltagePin);
  displayFrame();
}