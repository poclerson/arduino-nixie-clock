#include "fonts.h"

uint8_t frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

uint8_t fonts[11][8][5] = {
  {
    // 0
    { 0, 1, 1, 1, 0 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 0, 1, 1, 1, 0 },
  },
  {
    // 1
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
  },
  {
    // 2
    { 0, 0, 1, 1, 0 },
    { 0, 1, 0, 0, 1 },
    { 0, 1, 0, 0, 1 },
    { 0, 0, 0, 0, 1 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 1, 1, 1 },
  },
  {
    // 3
    { 0, 1, 1, 1, 0 },
    { 1, 0, 0, 0, 1 },
    { 0, 0, 0, 0, 1 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 0, 1, 1, 1, 0 },
  },
  {
    // 4
    { 0, 1, 0, 0, 1 },
    { 0, 1, 0, 0, 1 },
    { 0, 1, 0, 0, 1 },
    { 0, 1, 1, 1, 1 },
    { 0, 0, 0, 0, 1 },
    { 0, 0, 0, 0, 1 },
    { 0, 0, 0, 0, 1 },
    { 0, 0, 0, 0, 1 },
  },
  {
    // 5
    { 0, 1, 1, 1, 1 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 0, 0, 0, 1 },
    { 0, 0, 0, 0, 1 },
    { 0, 1, 0, 0, 1 },
    { 0, 0, 1, 1, 0 },
  },
  {
    // 6
    { 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 1, 1, 1, 1 },
  },
  {
    // 7
    { 1, 1, 1, 1, 1 },
    { 0, 0, 0, 0, 1 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
  },
  {
    // 8
    { 0, 1, 1, 1, 0 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 0, 1, 1, 1, 0 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 0, 1, 1, 1, 0 },
  },
  {
    // 9
    { 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 0, 1, 1, 1, 1 },
    { 0, 0, 0, 0, 1 },
    { 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 0, 1, 1, 1, 1 },
  },
  {
    // .
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
  }
};

uint8_t framePositions[3] = {
  0, 6, 7
};

void writeToFrame(char character, int position) {
  int index = -1;
  if (character >= '0' && character <= '9')
    index = character - '0';
  else if (character == '.')
    index = '10';
  else {
    Serial.println("WARNING: unsupported character");
    return;
  }

  // for (int row = 0; row < 8; row++) {
  //   uint8_t *charRow = fonts[index][row];
  //   for (int col = position; col < 12; col++) {
  //     frame[row][col] = charRow[col];
  //   }
  // }
}

void clearFrame() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 12; col++) {
      frame[row][col] = 0;
    }
  }
}

void displayFrame(ArduinoLEDMatrix matrix) {
  matrix.renderBitmap(frame, 8, 12);
}

float getVoltage(int pin) {
  int sensorValue = analogRead(pin);
  float voltage = sensorValue * (5.0 / 1023.0);
  return voltage;
}

String toStringVoltage(float voltage) {
  double roundedVoltage = round(voltage * 10) / 10;

  String stringVoltage = String(roundedVoltage);
  return stringVoltage;
}

void writeVoltage(int pin) {
  float voltage = getVoltage(pin);
  String stringVoltage = toStringVoltage(voltage);

  char chars[3] = {};

  stringVoltage.toCharArray(chars, 4);
  for (int character = 0; character < 3; character++) {
    writeToFrame(chars[character], framePositions[character]);
  }
}