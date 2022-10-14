#include <Arduino.h>
#include <Adafruit_AHTX0.h> 


Adafruit_AHTX0 aht;
sensors_event_t humidity, temp;

const int del = 2000;

float tmp = 0;
int clim = 0;

void setup() {

  Serial.begin(9600);

  if (aht.begin()) {
    Serial.println("Found AHT20");
  } else {
    Serial.println("Didn't find AHT20");
  }

}

void loop() {
  
  aht.getEvent(&humidity, &temp);
  tmp = temp.temperature;
  Serial.println(tmp);
  
  if (tmp > 27){
    clim = 1;
    Serial.println(clim);
  }else{
    clim = 0;
    Serial.println(clim);
  }
  delay(del);

}