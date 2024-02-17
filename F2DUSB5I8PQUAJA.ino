#include "fonts.h"
#include "nixies.h"

int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
int readVoltagePin = A0;

int count;
float voltage;

ArduinoLEDMatrix matrix;

int charTable[] = { 0, 128, 64, 192, 32, 160, 96, 224, 16, 144, 8, 136, 72, 200, 40, 168, 104, 232, 24, 152, 4, 132, 68, 196, 36, 164, 100, 228, 20, 148, 12, 140, 76, 204, 44,
                    172, 108, 236, 28, 156, 2, 130, 66, 194, 34, 162, 98, 226,
                    18, 146, 10, 138, 74, 202, 42, 170, 106, 234, 26, 154, 6, 134, 70, 198, 38, 166, 102, 230, 22, 150, 14, 142, 78, 206, 46, 174, 110, 238, 30, 158, 1, 129,
                    65, 193, 33, 161, 97, 225, 17, 145, 9, 137, 73, 201, 41, 169, 105, 233, 25, 153 };


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
  Serial.begin(9600);
  matrix.begin();
}

void loop() {
  Serial.print("Voltage = ");
  Serial.println(voltage);

  writeVoltage(readVoltagePin);
  // displayFrame(matrix);

  delay(500);

  clearFrame();
  // displayFrame(matrix);

  delay(500);

  nixies = 255;
  updateShiftRegister();
  // delay(500);

  // for (count = 0; count < 100; count++) {
  //   nixies = charTable[count];

  //   updateShiftRegister();
  //   delay(500);

  // Serial.print("x = ");
  // Serial.println(count);
  // Serial.print("nixies = ");
  // Serial.println(nixies);
  // }
}