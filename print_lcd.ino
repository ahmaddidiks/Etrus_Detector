void menu(){
    //display.clearDisplay();
    display.setTextSize(1);             // Normal 1:1 pixel scale
    display.setCursor(0,56);
    display.println("Back      Sw       Go");
    //display.display();
}
void perintah_ambil_sampling(){
  
        //perintah untuk mengambil sample
//        display.clearDisplay();
        display.setTextSize(1);   
        display.setCursor(35,30);  
        display.println("Tekan GO");
        display.setCursor(10,40); 
        display.println("untuk ambil data");
        //display.display();
}



//state 0
void pilih_jenis_sapi(){
     display.clearDisplay();
  display.setTextSize(2);   
  display.setCursor(40,0);          // Start at top-left corner
  if (jenis_sapi==0){
    display.println(F("Sapi"));
    display.setCursor(25,25);             // Start at top-left corner
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.println(F("Daging"));
                    }
  else if (jenis_sapi==1){
    display.println(F("Sapi"));
    display.setCursor(25,25);             // Start at top-left corner
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.println(F("Perah"));
                         }
  menu();
  display.display();
}

void tampil_jenis_sapi(){
    display.clearDisplay();
    display.setTextSize(1);             // Normal 1:1 pixel scale
    display.setCursor(0,30);
    if (jenis_sapi==0) display.println(" Dipilih Sapi Daging");
    else if (jenis_sapi==1) display.println(" Dipilih Sapi Perah");
    menu();
    display.display();
                              }


//state 1-3 
//membaca suhu,ph dan tds di file


void tampilkan_hasil_sampling(){
  display.clearDisplay();
  display.setTextSize(2);   
  if(state==1) {
        display.setCursor(0,0);  
        display.println("Suhu: ");
        display.setCursor(60,0);  
        display.println(suhu_final,1);
        display.setTextSize(1);   
        display.setCursor(110,12);  
        display.println("C");
  }
  else if(state==2){
        display.setCursor(0,0);  
        display.println("PH:");
        display.setCursor(35,0);  
        display.println(ph_final,1);
  }
  else {
        display.setCursor(0,0);  
        display.println("TDS:");
        display.setCursor(45,0);  
        display.println(persen,4);
        display.setTextSize(1);   
        display.setCursor(120,5);  
        display.println("%");
  }
   
  menu();
   display.setTextSize(1);   
   display.setCursor(10,30);  
   display.println("<==Back     GO==>");
   display.display();
}


void tampilkan_conclution(){
  display.clearDisplay();
    display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setCursor(30,0);             // Start at top-left corner
  if (jenis_sapi==0) display.println("Sapi Daging");
  else if (jenis_sapi==1) display.println("Sapi Perah");
  display.setTextSize(3);   
  display.setCursor(0,20);  
  if (hasil==0) display.println("NEGATIF");
  else if (hasil==1) display.println("POSITIF");
  menu();
  display.display();
}

void detail(){
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(30,0);             
        if (jenis_sapi==0) display.println("Sapi Daging");
        else if (jenis_sapi==1) display.println("Sapi Perah");   
  //suhu
        display.setCursor(0,20);  
        display.println("Suhu: ");
        display.setCursor(40,20);  
        display.println(suhu_final,1);
        display.setTextSize(1);   
        display.setCursor(63,14);  
        display.println("C");
  
 //ph
        display.setCursor(0,30);  
        display.println("PH:");
        display.setCursor(20,30);  
        display.println(ph_final,1);
  
  //dts
        display.setCursor(0,40);  
        display.println("TDS:");
        display.setCursor(30,40);  
        display.println(persen,4);
        display.setTextSize(1);   
        display.setCursor(70,40);  
        display.println("%");
      menu();
  display.display();   
}
