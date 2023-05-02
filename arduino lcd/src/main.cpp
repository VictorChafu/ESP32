/* 
                MODIFICADO POR  :{==[=======>>>> ELECTROALL <<<<<=======]==}
                FACEBOOK        : https://web.facebook.com/ELECTROALL.ELECTRONICA/?_rdc=1&_rdr
                PÁGINA WEB      : http://che-charls-electroall.webnode.es/
                TWITTER         : https://twitter.com/ChCharlsELECTRO
                YOUTUBE         : https://www.youtube.com/c/ELECTROALL
                INSTAGRAM       : https://www.instagram.com/_electroall_/
           ___________________________________________________________________

           *** {==[=======> (MANEJO DEL I2C CON PANTALLA LCD) <=======]==}  ***
           ___________________________________________________________________
*/
/*
 Board I2C / TWI pins
Uno       =   A4 (SDA), A5 (SCL)
Mega2560  =   20 (SDA), 21 (SCL)
Leonardo  =   2 (SDA), 3 (SCL)
Due       =   20 (SDA), 21 (SCL), SDA1, SCL1

esta configuracion de estos pines se encuentran dentro de la librería "wire" mas info: https://www.arduino.cc/en/Reference/Wire
 */


#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Creamos el objeto lcd con la dirección 0x3F, 16 columnas y 2 filas
LiquidCrystal_I2C lcd(0x3F,16,2);  

void setup() {
  // Inicializamos el objeto lcd
  lcd.init();
  
  //Encendemos la luz de fondo.
  lcd.backlight();
  
  // Escribimos un Mensaje en la pantalla LCD.
  lcd.print("Hola Mundo");
}

void loop() {
   // Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
  lcd.setCursor(0, 1);
   // Escribimos el número de segundos trascurridos
  lcd.print(millis()/1000);
  lcd.print(" Segundos");
  delay(1000);
}