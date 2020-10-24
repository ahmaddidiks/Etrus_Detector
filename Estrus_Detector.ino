

/*************  WIRING  ********************
A0 = Sensor garam
A1 = Sensor PH
A2 = Sensor suhu

d1
d2
d3

************* SENSOR GARAM ********************/








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
unsigned int pHArray[ArrayLenth];   //Store the average value of the sensor feedback
unsigned int pHArrayIndex=0; 
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
unsigned int sensorValue; //adc value
float outputValueConductivity; //conductivity value
float outputValueTDS; //TDS value
float persen;
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

//************* PUSH BUTTON ********************
unsigned int go,pilih,back;
//############ PUSH BUTTON ###################

//************* SENSOR SUHU ********************
float suhu;
//############ SENSOR SUHU ###################

//************* Algoritma ********************
float suhu_final,
      temp,
      ph_final,
      ph_cpy,
      dts_final;
int
      state,
      sub_state,
      start,
      jenis_sapi,
      hasil,
      tunda=300
      
      ;
//############ Algoritma ###################


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(LED,OUTPUT); 
  pinMode(9,INPUT_PULLUP); //back
  pinMode(8,INPUT_PULLUP); //ganti
  pinMode(7,INPUT_PULLUP); //go
  pinMode(A0,INPUT); 
  pinMode(A1,INPUT); 
  pinMode(A2,INPUT); 




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
  display.setTextSize(3);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(10,10);             // Start at top-left corner
  display.println(F("Estrus"));
  display.setCursor(20,40);             // Start at top-left corner
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.println(F("Detector"));
  display.display();
  delay(3000); 
  display.clearDisplay();
  display.setTextSize(2);   
  display.setCursor(18,20);
  display.println("Tekan GO");
  display.display();
  //delay(5000); 
  
}

//void loop(){
//  detail();
//}



void loop() {
  
  // put your main code here, to run repeatedly:
  //kadar_garam(); //memanggil fungsi deteksi sensor garam
  //ph_sensor(); //memanggil fungsi pembacaan sensor ph
  //baca_suhu();
  Serial.print("state : ");
  Serial.print(state);
  Serial.print("  sub_state : ");
  Serial.print(sub_state);
  Serial.print("  start : ");
  Serial.print(start);
  Serial.print("  jenis sapi : ");
  Serial.println(jenis_sapi);
  back=digitalRead(9); //back
  pilih=digitalRead(8); //switch
  go=digitalRead(7); //go
   
  if (back==0){delay(100); start=1;}
  
  if(start==1){
    switch(state){
      case 0: 
             switch(sub_state)
                          {
                            case 0: //pilih jenis sapi
                                    //0 = sapi daging ; 1= sapi perah
                                    //pilih_jenis_sapi();
                                    if      (jenis_sapi==0 && pilih==0) {delay(100);jenis_sapi=1;}
                                    else if (jenis_sapi==1 && pilih==0) {delay(100);jenis_sapi=0;}
                                    pilih_jenis_sapi();
                                    if (go==0) {delay(100);sub_state=1;}
                                    
                                    break;
                            case 1: //memastikan pilihan
                                    tampil_jenis_sapi();
                                    if (go==0) {delay(tunda); state=1;}
                                    else if (back==0) {delay(tunda);sub_state=0;}
                                    break;
                          }
                            
              break;              
      case 1: 
             switch(sub_state)
                          {
                          case 0: 
                                  baca_suhu; //membaca data suhu
                                  if (go==0) {
                                        delay(tunda);
                                        sub_state=1;
                                      }
                                  break;
                          case 1: for(int i=1;i<=10;i++)
                                {
                                 suhu = analogRead(A2)/2.0379; //mengambil data suhu
                                  temp+=suhu;
                                 }
                                  suhu_final=temp/10;
                                  temp=0;
                                  sub_state=2;
                                  break;
                          case 2:
                                  tampilkan_hasil_sampling();
                                  
                                  if (go==0) { //lanjut
                                                delay(tunda);
                                                state=2;
                                                sub_state=0;
                                              }
                                  else if (back==0) { //ulang
                                                delay(tunda);
                                                sub_state=0;
                                              }            
                                  break;
                           }
              break;  
      case 2:  //dapat data ph
              
              switch(sub_state)
                          {
                          case 0: ph_sensor();
                                  if (go==0) {
                                        delay(tunda);
                                        sub_state=1;
                                      }
                                  break;
                          case 1: for(int i=1;i<=10;i++){
                                  ph_sensor();
                                  temp+=ph_cpy;
                                                        }
                                  ph_final=temp/10;
                                  temp=0;
                                  sub_state=2;
                                  break;
                          case 2:  tampilkan_hasil_sampling();
                                  
                                  if (go==0) { //lanjut
                                                delay(tunda);
                                                state=3;
                                                sub_state=0;
                                              }
                                  else if (back==0) { //ulang
                                                delay(tunda);
                                                sub_state=0;
                                              }            
                                  break;
                           }
              break;
      case 3:   //go//dapat data DTS
              
              switch(sub_state)
                          {
                          case 0: kadar_garam(); //membaca data suhu
                                  if (go==0) {
                                        delay(tunda);
                                        sub_state=1;
                                      }
                                  break;
                          case 1: for(int i=1;i<=10;i++){
                                  kadar_garam();
                                  temp+=persen;
                                                        }
                                  dts_final=temp/10;
                                             temp=0;
                                  sub_state=2;
                                  break;
                          case 2: tampilkan_hasil_sampling();
                                  
                                  if (go==0) { //lanjut
                                                delay(tunda);
                                                state=4;
                                                sub_state=0;
                                              }
                                  else if (back==0) { //ulang
                                                delay(tunda);
                                                sub_state=0;
                                              }            
                                  break;
                           }
              break;
      case 4:  switch(sub_state)
                          {
                          case 0: if(jenis_sapi==0){
                                            if(suhu_final>33 && ph_final>7 && dts_final>0.0020) hasil=1; //positif
                                            else hasil=0; //negatif
                                            }
                                   else if(jenis_sapi==1){
                                                    if(suhu_final>33 && ph_final>7 && dts_final>0.0020) hasil=1; //positif
                                                    else hasil=0; //negatif
                                                    }
                                   tampilkan_conclution();   
                                   if (go==0) { //selesai
                                                                    delay(tunda);
                                                                    state=0;
                                                                    sub_state=0;
                                                                  }
                                   else if (back==0) { //lihat hasil detail
                                                                    delay(tunda);
                                                                    sub_state=1;
                                                                  }                  
                                   break;
                            case 1: detail();
                                    if (go==0) { //selesai
                                                                    delay(tunda);
                                                                    state=0;
                                                                    sub_state=0;
                                                                  }
                                   break;
                    
    
    
                            }
               break;
        
    }
  }
}
