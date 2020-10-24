void baca_suhu(){
  suhu = analogRead(A2)/2.0379;
  //delay(50);
  //menampilkan data di lcd
  display.clearDisplay();
  display.setTextSize(2);   
  display.setCursor(0,0);  
  display.println("Suhu: ");
  display.setCursor(60,0);  
  display.println(suhu,1);
   display.setTextSize(1);   
  display.setCursor(110,0);  
  display.println("C");
  display.setCursor(110,0);  
  display.println("C");
  display.setTextSize(1);   
        display.setCursor(35,30);  
        display.println("Tekan GO");
        display.setCursor(10,40); 
        display.println("untuk ambil data");
  menu();
  display.display();
}
