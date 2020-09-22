/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
// defines pins numbers
const int trigPin = 11;
const int echoPin = 10;
// defines variables
long sonarDuration;
int sonarDistance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
void loop() {

digitalWrite(trigPin, LOW);       // Clears the trigPin
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);      // Sets the trigPin on HIGH state for 10 micro seconds
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
sonarDuration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds

sonarDistance= sonarDuration*0.034/2;   // Calculating the sonarDistance

Serial.print("sonarDistance: ");        // Prints the sonarDistance on the Serial Monitor
Serial.println(sonarDistance);
}
