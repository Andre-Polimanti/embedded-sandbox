#include <Arduino.h>

#include "config.hpp"
#include "esp-now/handler.hpp"

bool last_button_state = false;
unsigned long timer = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUILT_IN_LED, OUTPUT);
  
  setupEspNow();
}
 
void loop() {
  bool current_button_state = received_msg.button_is_pressed;

  if (current_button_state && !last_button_state) {
    digitalWrite(BUILT_IN_LED, HIGH);
    timer = millis();
  
  }else if (!current_button_state && last_button_state) {
    digitalWrite(BUILT_IN_LED, LOW);

    answer_to_send.press_duration = (millis() - timer);
    sendAnswer();
  }

  last_button_state = current_button_state;
}
