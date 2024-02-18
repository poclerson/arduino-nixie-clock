#include "fonts.h"

byte frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }
};

ArduinoLEDMatrix matrix;

byte fonts[11][8] = {
  {
    // 0
    0b01110,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b01110,
  },
  {
    // 1
    0b01100,
    0b01110,
    0b01100,
    0b01100,
    0b01100,
    0b01100,
    0b01100,
    0b11111,
  },
  {
    // 2
    0b11110,
    0b10000,
    0b01000,
    0b00100,
    0b00010,
    0b00001,
    0b00001,
    0b11111,
  },
  {
    // 3
    0b01111,
    0b10000,
    0b01000,
    0b00100,
    0b01100,
    0b10000,
    0b10000,
    0b01111,
  },
  {
    // 4
    0b01000,
    0b01100,
    0b01010,
    0b01001,
    0b11111,
    0b01000,
    0b01000,
    0b01000,
  },
  {
    // 5
    0b11111,
    0b00001,
    0b00001,
    0b01111,
    0b10000,
    0b10000,
    0b10001,
    0b01110,
  },
  {
    // 6
    0b01110,
    0b00001,
    0b00001,
    0b01111,
    0b10001,
    0b10001,
    0b10001,
    0b01110,
  },
  {
    // 7
    0b11111,
    0b10000,
    0b01000,
    0b00100,
    0b01010,
    0b00010,
    0b00001,
    0b00001,
  },
  {
    // 8
    0b01110,
    0b10001,
    0b10001,
    0b01110,
    0b10001,
    0b10001,
    0b10001,
    0b01110,
  },
  {
    // 9
    0b01110,
    0b10001,
    0b10001,
    0b10001,
    0b11110,
    0b10000,
    0b10000,
    0b11110,
  },
  {
    // .
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00100,
  },
};

uint8_t framePositions[3] = {
  0, 6, 7
};

/**
 * @brief Modifies `frame` using a 0-9 number or the "." character at a given position
 * 
 * @param character Character to be written on `frame`
 * @param position Position of the character on `frame` 
 */
void writeToFrame(char character, int position) {
  int index = -1;
  if (character >= '0' && character <= '9')
    index = character - '0';
  else if (character == '.')
    index = 10;
  else {
    Serial.println("WARNING: unsupported character");
    return;
  }

  for (int row = 0; row < 8; row++) {
    byte characterRow = fonts[index][row];

    for (int col = 0; col < 5; col++) {
      byte bit = bitRead(characterRow, col);
      frame[row][col + position] = bit;
    }
  }
}

void printFrame() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 12; col++) {
      if (col == 11) {
        Serial.println(frame[row][col]);
      }
      else {
        Serial.print(frame[row][col]);
      }
    }
  }
}

void beginMatrix() {
  matrix.begin();
}

void displayFrame() {
  matrix.renderBitmap(frame, 8, 12);
}

/**
 * @brief Get voltage from a pin
 * 
 * @param Integer representing the pin
 * @return Voltage
 */
float getVoltage(int pin) {
  int sensorValue = analogRead(pin);
  float voltage = sensorValue * (5.0 / 1023.0);
  return voltage;
}

/**
 * @brief Converts a `float` voltage to a `String` one with one decimal number
 * 
 * @param voltage 
 * @return String 
 */
String toStringVoltage(float voltage) {
  double roundedVoltage = round(voltage * 10) / 10;

  String stringVoltage = String(roundedVoltage);
  return stringVoltage;
}

/**
 * @brief Write voltage to the `frame`
 * 
 * @param pin 
 */
void writeVoltage(int pin) {
  float voltage = getVoltage(pin);
  String stringVoltage = toStringVoltage(voltage);

  char chars[3] = {};

  stringVoltage.toCharArray(chars, 4);
  for (int character = 0; character < 3; character++) {
    writeToFrame(chars[character], framePositions[character]);
  }
}