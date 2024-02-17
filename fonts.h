#ifndef FONTS_H
#define FONTS_H
#include <Arduino.h>
#include "Arduino_LED_Matrix.h"
#include <string>
  void writeToFrame(char character, int position);
  void clearFrame();
  void displayFrame(ArduinoLEDMatrix matrix);
  float getVoltage(int pin);
  String toStringVoltage(float voltage);
  void writeVoltage(int pin);
#endif