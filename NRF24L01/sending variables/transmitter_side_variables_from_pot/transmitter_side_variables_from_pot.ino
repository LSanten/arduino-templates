//Transmitter coding for the nrf24L01 radio transceiver.
//NRF24L01 and Arduino based Sensors monitoring
//https://www.electroniclinic.com/
/*
pins connections
 
vcc 3.3
gnd gnd
ce pin9
csn pin10
sck pin13
mosi pin11
miso pin12
 
*/
 
 
 
#include <SPI.h>
 #include <nRF24L01.h>
 #include <RF24.h>
 #define CE_PIN 9
 #define CSN_PIN 10
 #define Potentiometer1 A0
 #define Potentiometer2 A1
 #define Potentiometer3 A2
#define Pushbutton 2 
const uint64_t pipe = 0xE8E8F0F0E1LL;
 
RF24 radio(CE_PIN, CSN_PIN);
byte data[6]; // depending on the number of sensors used
 
 
void setup()
 {
 Serial.begin(9600);
 radio.begin();
 radio.openWritingPipe(pipe);
 pinMode(Potentiometer1,INPUT);
 pinMode(Potentiometer2, INPUT);
 pinMode(Potentiometer3, INPUT); 
 pinMode(Pushbutton,INPUT_PULLUP);
 
 
 }
 
void loop()
 {
 
data[0] = map(analogRead(Potentiometer1), 0, 1023, 0, 255); 
data[1] = map(analogRead(Potentiometer2), 0, 1023, 0, 255);
data[2] = map(analogRead(Potentiometer3),0 , 1023, 0, 255); 

Serial.println(data[0]);
Serial.println(data[1]);

 
if(digitalRead(Pushbutton) == LOW)
{
  data[3] = 1; 
}
if(digitalRead(Pushbutton) == HIGH)
{
  data[3] = 0; 
}

// SEND DATA
radio.write( data, sizeof(data) );
 }