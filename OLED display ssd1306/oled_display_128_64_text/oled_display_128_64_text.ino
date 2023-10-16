/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Hello, world!");
  display.display(); 
  delay(200);
  display.println("Hello, 1!");
  display.display(); 
  delay(200);
  display.println("Hello, 2!");
  display.display();
  delay(200);
  display.println("blablablalblalblal");
  display.display();  
  delay(200);
  display.println("blablablalblalblal");
  display.display(); 
  delay(200);
  display.println("blablablalblalblal");
  display.display(); 

  delay(2000);
  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(10, 0);
  display.println(F("scroll"));
  display.println(F("state: 2"));
  display.println(F("A: 234"));
  display.println(F("B: 50%"));
  display.display();      // Show initial text

  /******** USEFUL COMMANDS
  display.clearDisplay() – all pixels are off
  display.drawPixel(x,y, color) – plot a pixel in the x,y coordinates
  display.setTextSize(n) – set the font size, supports sizes from 1 to 8
  display.setCursor(x,y) – set the coordinates to start writing text
  display.print(“message”) – print the characters at location x,y
  display.display() – call this method for the changes to make effect

  https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/
  *********/


}

void loop() {
  
}