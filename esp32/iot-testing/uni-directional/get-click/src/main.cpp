#include <Arduino.h>

#include "config.hpp"
#include "esp_now_handler.hpp"

void setup() {
  Serial.begin(115200);
  pinMode(BUILT_IN_LED, OUTPUT);
  
  setupEspNow();
}
 
void loop() {
  if (myData.button_is_pressed) {
    digitalWrite(BUILT_IN_LED, HIGH);
  }else{
    digitalWrite(BUILT_IN_LED, LOW);
  }
}
