//https://www.electroniclinic.com/
// SLIGHTLY CHANGED FROM https://www.electroniclinic.com/nrf24l01-with-arduino-nrf24l01-pinout-and-example-codes/#24G_NRF24LO1_Transceiver_Module
// because read function does not output anyting anymore 
/*
pins connections
 
vcc 3.3
gnd gnd
ce pin9
scn pin10
sck pin13
mosi pin11
moso pin12
 
 
*/
#include <SPI.h>
 #include <nRF24L01.h>
 #include <RF24.h>
 #define CE_PIN 9
 #define CSN_PIN 10
 
 const uint64_t pipe = 0xE8E8F0F0E1LL;
 
RF24 radio(CE_PIN, CSN_PIN);
byte data[6]; // depending on the number of sensors used
 
unsigned long lastReceiveTime = 0;
unsigned long currentTime = 0;
 
 
void setup()
 {
 Serial.begin(9600);
 delay(1000);
 Serial.println("Nrf24L01 Receiver Starting");
 radio.begin();
 radio.openReadingPipe(1,pipe);
 radio.startListening();
 }
  
void loop()
 {


 if ( radio.available() ) {
  radio.read( data, sizeof(data) );
  Serial.println("Data:");
  Serial.println(data[0]);
  Serial.println(data[1]);
  Serial.println(data[2]);
  Serial.println(data[3]); 
 }
 }