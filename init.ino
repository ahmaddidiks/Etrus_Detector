
/*************  SENSOR    PH  ********************
 # This sample code is used to test the pH meter V1.1.
 # Editor : YouYou
 # Ver    : 1.1
 # DAT    : 2014.06.23
 # Product: analog pH meter V1.1
 # SKU    : SEN0161

wiring:
Kabel Merah -> 5V arduino
Kabel Biru ->  A1 arduino
Kabel Hitam -> GND arduino
*/
#define SensorPin A1            //pH meter Analog output to Arduino Analog Input 1
#define Offset 0.00            //deviation compensate
#define LED 13
#define samplingInterval 20
#define printInterval 800
#define ArrayLenth  40    //times of collection
int pHArray[ArrayLenth];   //Store the average value of the sensor feedback
int pHArrayIndex=0; 
//############### SENSOR GARAM ################### 


//************* SENSOR GARAM ********************
/*
wiring:
terminal 5V -> 5V arduino
terminal output ->  A0 arduino
terminal GND -> GND arduino
*/
#define analogInPin  A0  // Analog input pin 

//variable
int sensorValue; //adc value
float outputValueConductivity; //conductivity value
float outputValueTDS; //TDS value
//############### SENSOR GARAM ###################

//************* LCD ********************
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//############### LCD ###################


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED,OUTPUT); 






  //***************************** setup LCD ###############################
  //############################            *******************************
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  //display.display();
  //delay(0); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);
  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
  // display.display(). These examples demonstrate both approaches...
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(3,0);             // Start at top-left corner
  display.println(F("Sapi : Tidak"));
  display.setCursor(20,30);             // Start at top-left corner
  display.setTextSize(3);             // Normal 1:1 pixel scale
  display.println(F("20:00"));
  display.display();
}
