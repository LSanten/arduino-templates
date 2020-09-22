/*
  Reading a serial ASCII-encoded string.

  This sketch demonstrates the Serial parseInt() function.
  It looks for an ASCII string of comma-separated values.
  It parses them into ints, and uses those to fade an RGB LED.

  Circuit: Common-Cathode RGB LED wired like so:
  - red anode: digital pin 3
  - green anode: digital pin 5
  - blue anode: digital pin 6
  - cathode: GND

  created 13 Apr 2012
  by Tom Igoe
  modified 14 Mar 2016
  by Arturo Guadalupi

  This example code is in the public domain.
*/

// pins for the LEDs:
#define LED 13;
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

int red = 0;
int green = 0;
int blue = 0;
int white = 0;
int state = 0;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {

  Serial.print(state);
  Serial.print(" ");
  Serial.print(red);
  Serial.print(" ");
  Serial.print(green);
  Serial.print(" ");
  Serial.print(blue);
  Serial.print(" ");
  Serial.println(white);
  
  // if there's any serial available, read it:
  while (Serial.available() >= 5) {

    // look for the next valid integer in the incoming serial stream:
    state = Serial.read();
    
    red = Serial.read();
    // do it again:
    green = Serial.read();
    // do it again:
    blue = Serial.read();
    
    white = Serial.read();

    // look for the newline. That's the end of your sentence:
    
    
    
  }
  
}
