void setup()
{
  Serial.begin(9600);
  while (!Serial) delay(100);
  Serial1.begin(9600);

  Serial.println(F("GPSDeviceSerial1"));
  Serial.println();
}

void loop()
{
  // This sketch displays information every time a new sentence is correctly encoded.
  byte buf[16];
  while (Serial1.available() > 0)
  {
//    Serial.println("-");
//    char gpsChr = Serial1.read();
//    Serial.print(gpsChr);
//    if (10 == gpsChr)
//        delay (3000);

    int size = Serial1.readBytes(buf, sizeof (buf));
    if (0 < size)
        Serial.write(buf, size);
  }
  //Serial.println();
    
}
