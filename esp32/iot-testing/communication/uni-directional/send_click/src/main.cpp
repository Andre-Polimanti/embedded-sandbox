#include <Arduino.h>
#include "config.hpp"
#include "esp-now/handler.hpp"

struct_message myData;
 
void setup() {
  Serial.begin(115200);
  pinMode(BUILT_IN_BUTTON, INPUT);

  setupEspNow();
}
 
void loop() {
  myData.button_is_pressed = !digitalRead(BUILT_IN_BUTTON);
  
  sendData(myData);
  delay(30);
}