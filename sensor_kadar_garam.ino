
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
  Serial.print("sensor ADC = ");
  Serial.print(sensorValue);
  Serial.print("  conductivity (uSiemens)= ");
  Serial.print(outputValueConductivity);
  Serial.print("  TDS(ppm)= ");
  Serial.print(outputValueTDS);
  Serial.print("  TDS(%)= ");
  Serial.print(outputValueTDS*0.0001);
  Serial.println(" %");
  delay(500);
}
