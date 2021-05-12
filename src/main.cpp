#include <Arduino.h>
#include "DateTime.hpp"
#include "TimeClock.hpp"
#include "Curve.hpp"
#include "compile_time.h"

TimeClock clock1 = TimeClock(0, 0, 0);
TimeClock clock2 = TimeClock(0, 0, 5);
TimeClock clock3 = TimeClock(1, 17, 50);
TimeClock clock4 = TimeClock(5, 20, 12);
TimeClock clock5 = TimeClock(5, 20, 13);
TimeClock clock6 = TimeClock(5, 20, 12);

int p1[10] = {0, 100, 200, 300, 400, 500, 600, 700, 800, 900};
int p2[10] = {1000, 100, 900, 300, 400, 800, 600, 700, 800, 600};

Curve c1 = Curve(p1, clock1.toTimestamp(), 2);
Curve c2 = Curve(p2, clock2.toTimestamp(), 3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(74400);
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

void testTimestamp(TimeClock tc){
  String text = tc.toString();
  time_t timestamp = tc.toTimestamp();
  TimeClock tc2;
  tc2.fromTimestamp(timestamp);
  Serial.print(text);
  Serial.print(" = ");
  Serial.print(timestamp);
  Serial.print(" = ");
  Serial.println(tc2.toString());
}

void test_rtc(){
  TimeClock rtc;
  Serial.print(rtc.toString());
  Serial.print(" ");
  Serial.print(c1.getInterpolation(rtc.toTimestamp()));
  Serial.print(" ");
  Serial.println(c2.getInterpolation(rtc.toTimestamp()));
}

void loop() {
  // put your main code here, to run repeatedly:
  // testCompare(clock1, clock2);
  // testCompare(clock3, clock4);
  // testCompare(clock5, clock6);
  // testCompare(clock1, clock1);

  // testTimestamp(clock1);
  // testTimestamp(clock2);
  // testTimestamp(clock3);
  // testTimestamp(clock4);
  // testTimestamp(clock5);
  // testTimestamp(clock6);

  test_rtc();
  delay(1000);
}