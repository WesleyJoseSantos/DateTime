#include <Arduino.h>
#include "TimeClock.hpp"

TimeClock clock1 = TimeClock(3, 15, 36);
TimeClock clock2 = TimeClock(3, 16, 32);
TimeClock clock3 = TimeClock(1, 17, 50);
TimeClock clock4 = TimeClock(5, 20, 12);
TimeClock clock5 = TimeClock(5, 20, 13);
TimeClock clock6 = TimeClock(5, 20, 12);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void testCompare(TimeClock ck1, TimeClock ck2){
  Serial.print(ck1.toString());
  Serial.print(" < ");
  Serial.print(ck2.toString());
  Serial.print(" = ");
  Serial.println(ck1 < ck2);

  Serial.print(ck1.toString());
  Serial.print(" > ");
  Serial.print(ck2.toString());
  Serial.print(" = ");
  Serial.println(ck1 > ck2);

  Serial.print(ck1.toString());
  Serial.print(" == ");
  Serial.print(ck2.toString());
  Serial.print(" = ");
  Serial.println(ck1 == ck2);

  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  testCompare(clock1, clock2);
  testCompare(clock3, clock4);
  testCompare(clock5, clock6);
  testCompare(clock1, clock1);
  delay(1000);
}