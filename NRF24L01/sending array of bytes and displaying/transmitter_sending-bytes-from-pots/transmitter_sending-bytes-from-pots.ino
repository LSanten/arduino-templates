// SimpleTx - the transmitter

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


#define CE_PIN   9
#define CSN_PIN 10

#define Potentiometer1 A0
#define Potentiometer2 A1

const byte slaveAddress[5] = {'R','x','A','A','A'};


RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

char dataToSend[10] = "Message 0";
char txNum = '0';

byte data[6];

unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 1000; // send once per second


void setup() {

    Serial.begin(9600);

    Serial.println("SimpleTx Starting");

    radio.begin();
    radio.setDataRate( RF24_250KBPS );
    radio.setRetries(3,5); // delay, count
    radio.openWritingPipe(slaveAddress);

    pinMode(Potentiometer1,INPUT);
    pinMode(Potentiometer2, INPUT);
}

//====================

void loop() {
    currentMillis = millis();

    data[0] = 5; //state
    data[1] = map(analogRead(Potentiometer1), 0, 1023, 0, 255);
    data[2] = map(analogRead(Potentiometer2),0 , 1023, 0, 255);

    Serial.println(data[1]);
    Serial.println(data[2]);

    updateMessage();

    send();
    delay(50);




}

//====================
// FUNCTIONS BELOW 
//====================

void send() {

    bool rslt;

    rslt = radio.write( &data, sizeof(data) );
        // Always use sizeof() as it gives the size as the number of bytes.
        // For example if dataToSend was an int sizeof() would correctly return 2

    Serial.print("Data Sent ");
    //Serial.print(dataToSend);
    if (rslt) {
        Serial.println("  Acknowledge received");
    }
    else {
        Serial.println("  Tx failed");
    }
}

//================

void updateMessage() {
        // so you can see that new data is being sent
    
    
    txNum += 1;
    if (txNum > '9') {
        txNum = '0';
    }
    dataToSend[8] = txNum;
}