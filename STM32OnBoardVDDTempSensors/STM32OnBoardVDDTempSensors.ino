// Reading Vdd and Temperature Sensor
// Pito 8/2016
// Temperature sensor at ADC16, VREFINT at ADC17
// BluePill and Maple Mini

void setup_vdd_tempr_sensor() {
    adc_reg_map *regs = ADC1->regs;
    //regs->CR2 |= ADC_CR2_TSEREFE;    // enable VREFINT and Temperature sensor
    regs->CR2 |= ADC_CR2_TSVREFE;    
    // sample rate for VREFINT ADC channel and for Temperature sensor
    regs->SMPR1 |=  (0b111 << 18);  // sample rate temperature
    regs->SMPR1 |=  (0b111 << 21);  // sample rate vrefint
    adc_calibrate(ADC1);
}

void setup(){
    setup_vdd_tempr_sensor();
    pinMode(PC13, OUTPUT);    
    Serial.begin(115200);
    //while (0 == Serial.available())
      //delay(1);
      while (!Serial)
      {
        digitalWrite(PC13, !digitalRead(PC13));
        delay(30);
      }
    Serial.print("Vdd,V Temp,C");
}

short cnt(2048);
float minT(200), maxT(0), minV(12), maxV(0);
void loop() {
    float tempr, vdd;
    // reading Vdd by utilising the internal 1.20V VREF
    vdd = 1.20 * 4096.0 / adc_read(ADC1, 17);
    if (vdd >= maxV) maxV = vdd;
    if (vdd <= minV) minV = vdd;
    // following 1.43 and 0.0043 parameters come from F103 datasheet - ch. 5.9.13
    // and need to be calibrated for every chip (large fab parameters variance)
    tempr = (1.43 - (vdd / 4096.0 * adc_read(ADC1, 16))) / 0.0043 + 25.0;
    if (tempr >= maxT) maxT = tempr;
    if (tempr <= minT) minT = tempr;

    //Serial.print(vdd);Serial.print(" ");
    //Serial.print(tempr);Serial.println(" ");
    if (!--cnt)
    {
        cnt = 2048;
        digitalWrite(PC13, !digitalRead(PC13));
        Serial.print(minV);Serial.print(" ");
        Serial.print(minT);Serial.print(" ");
        Serial.print(maxV);Serial.print(" ");
        Serial.print(maxT);Serial.println(" ");
        minT = 200;
        maxT = 0;
        minV = 12;
        maxV = 0;
    }
    delay(10);
}
