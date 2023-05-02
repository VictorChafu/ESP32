//Incluir las bibliotecas OneWire y DallasTemperature

#include <OneWire.h>

#include <DallasTemperature.h>
int button;
String temp = "La Temperatura es de: ";

//Selecciona el pin al que se conecta el sensor de temperatura

const int oneWireBus = 22;

//Comunicar que vamos a utilizar la interfaz oneWire

OneWire oneWire(oneWireBus);

//Indica que el sensor utilizará la interfaz OneWire

DallasTemperature sensors (&oneWire);

void setup() {

  //Ajustar la velocidad para el monitor serie

  Serial.begin(9600);

}

void loop() {
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);

  while (Serial.available() == 0 ){

  }
  Serial.println(temp);
  button = Serial.parseInt(); //parse==analizar Int == lo va analizar como unmero entero
  Serial.println(temperatureC);

}