#include <Arduino.h>

#include "heltec.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <iostream>
#include <sstream>
const int oneWireBus = 21;
SSD1306Wire display(0x3c, 4, 15, GEOMETRY_64_32);
OneWire oneWire(oneWireBus);
DallasTemperature sensors (&oneWire);


void VextON(void)
{
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext, LOW);
}
void VextOFF(void) //Vext default OFF
{
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext, HIGH);
}
void setup() {
 VextON();
  delay(100);

  display.init();
  display.clear();
  display.display();
  
  display.setContrast(255);
}
void loop() {
  display.clear();
     sensors.requestTemperatures();
   float temperatureC = sensors.getTempCByIndex(0);
  String temp = String(temperatureC);
    display.drawString(50, 32-3/2,"T: ");
    display.drawString(64, 32-3/2,temp);
  display.display();
}
