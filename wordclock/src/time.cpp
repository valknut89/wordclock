#include <NTPClient.h>
#include <WiFiUdp.h>

#include "time.h"
//#include "de-DE.h"
#include "grid.h"

void Time::setup() {
  Time::ntpClient.begin();
  Time::ntpClient.update();
}

void Time::loop() {
  Time::ntpClient.update();

  int h = Time::ntpClient.getHours();
  int m = Time::ntpClient.getMinutes();

  if(m != Time::minute) {
    Time::hour = h;
    Time::minute = m;
    Grid::setTime(Time::hour, Time::minute);
  }
}

int Time::hour = -1;
int Time::minute = -1;
WiFiUDP Time::udp;
NTPClient Time::ntpClient = NTPClient(Time::udp);