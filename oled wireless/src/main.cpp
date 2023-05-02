#include <Arduino.h>

#include "heltec.h"

//rotate only for GEOMETRY_128_64
 SSD1306Wire display(0x3c, SDA_OLED, SCL_OLED, RST_OLED);

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
  
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_10);
  display.drawString(64, 32-3/2, "Jesús te ama \n <3");
  display.display();
  delay(2000);

}

void loop() { }