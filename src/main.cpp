#include <Arduino.h>
#include "DateTime.hpp"

DateTime tc = DateTime(Y2K_TIMESTAMP);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(tc.toString());
  delay(1000);
}