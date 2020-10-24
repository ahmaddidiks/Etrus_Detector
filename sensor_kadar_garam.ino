
void kadar_garam(){
  //read the analog in value:
  sensorValue = analogRead(analogInPin);

  //Mathematical Conversion from ADC to conductivity (uSiemens)
  //rumus berdasarkan datasheet
  outputValueConductivity = (0.2142*sensorValue)+494.93;
  
  //Mathematical Conversion from ADC to TDS (ppm)
  //rumus berdasarkan datasheet
  outputValueTDS = (0.3417*sensorValue);//+281;
  
  //print the results to the serial monitor:
//  Serial.print("sensor ADC = ");
//  Serial.print(sensorValue);
//  Serial.print("  conductivity (uSiemens)= ");
//  Serial.print(outputValueConductivity);
//  Serial.print("  TDS(ppm)= ");
//  Serial.print(outputValueTDS);
//  Serial.print("  TDS(%)= ");
  persen=outputValueTDS*0.0001;
//  Serial.print(persen, 4);
//  Serial.println(" %");
  //delay(500);
  //menampilkan data di lcd
  display.clearDisplay();
  display.setTextSize(2);   
  display.setCursor(0,0);  
  display.println("TDS:");
  display.setCursor(45,0);  
  display.println(persen,4);
  display.setTextSize(1);   
  display.setCursor(120,5);  
  display.println("%");
  if (state==3 && sub_state==1) {//pass
                                }
  else {perintah_ambil_sampling();
        menu();}
  display.display();
}
