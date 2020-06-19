#include <Adafruit_SSD1306.h>
#include <splash.h>

#include <Adafruit_SHT31.h>

#include <Adafruit_GFX.h>
#include <Adafruit_MonoOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include "Adafruit_SHT31.h" //https://github.com/adafruit/Adafruit_SHT31/archive/master.zip
Adafruit_SHT31 sht31 = Adafruit_SHT31();
#include <Wire.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
void setup() {
  Serial.begin(9600);
  delay(10);
  sht31.begin(0x44);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();  //If you don't want to see the adfruit animation during the initialization,
                           //you can try to call display.clearDisplay() function right before calling
                           //display.display() in your setup function. This function, as its name suggests,
                           //clears the display completely.(we have done it)
  display.display();
  delay(500);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(2, 13);
  display.println("This is a 128X64 OLED display, used with an SHT3X Temp. & Humid sensor");
  display.display();
  delay(6000);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 13);
  display.println("Programmed By :"); //this is in the void setup() and not in void loop, 
                                      //because we  want it to be printed only once. 
                                      
  display.display();                  //if we write display.display() before delay(), then the next command will be executed 
                                      //after the delay() given, 
                                      //but if we dont write display.display(), the delay() command is not executed
                                      //and the next command is executed simultaneously with the previous one.
  delay(1500);
  /////////////////////////
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 25);
  display.println("Mohammad");
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 41);
  display.println("Talha");  
  display.display();
  delay(2000);
  
}

void loop() {

  float t = sht31.readTemperature();
  float h = sht31.readHumidity();
  Serial.print("TEMPERATURE: ");
  Serial.println(t);
  Serial.print("HUMIDITY: ");
  Serial.println(h);
  Serial.println();
  display.clearDisplay();
  delay(500);



  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 3);
  display.print("Temperature: ");
  display.setTextSize(2);
  display.setCursor(20, 13);
  display.print(t);

  display.setTextSize(1);
  display.setCursor(20, 39);
  display.print("Humidity: ");
  display.setTextSize(2);
  display.setCursor(20, 50);
  display.print(h);

  display.display();
  delay(500);
}
