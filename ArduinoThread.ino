/*
  Developer: Carlos Roberto Giancristóforo
  Date: 05/2017
  Description: Threads are used to start or stop functions in same time.
               In this example, Arduino will blink the red led every 60s and blue led every 6s.
  Highlights: Do not forget to set correct COM/TTY and correct board
  Version: 1.0
*/
#include <Thread.h>

int redLed = 10;
int blueLed = 11;
//Instance the Threads
Thread nThread = Thread();
Thread mThread = Thread();

void setup() {
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  //Calling the Thread on Setup
  nThread.onRun(RedLedStarter);
  nThread.setInterval(60000);
  mThread.onRun(BlueLedStarter);
  mThread.setInterval(6000);
}
void RedLedStarter() {
  digitalWrite(redLed, HIGH);
  delay(2000);
  digitalWrite(redLed, LOW);
  delay(2000);
}
void BlueLedStarter() {
  digitalWrite(blueLed, HIGH);
  delay(2000);
  digitalWrite(blueLed, LOW);
  delay(2000);
}
void loop() {
  if (nThread.shouldRun())
    nThread.run();
  if (mThread.shouldRun())
    mThread.run();
}
