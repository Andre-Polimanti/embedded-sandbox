#include <Arduino.h>

#include "config.hpp"
#include "esp-now/handler.hpp"

bool last_button_state = false;
unsigned long last_debounce = 0;
unsigned long debounce_time = 30; 
 
void setup() {
  Serial.begin(115200);

  pinMode(BUILT_IN_BUTTON, INPUT);
  pinMode(BUILT_IN_LED, OUTPUT);

  setupEspNow();

  msg_to_send.button_is_pressed = !digitalRead(BUILT_IN_BUTTON);
  last_button_state = msg_to_send.button_is_pressed;
}
 
void loop() {
  bool current_button_state = !digitalRead(BUILT_IN_BUTTON);

  if (current_button_state != last_button_state)  last_debounce = millis();
  if ((millis() - last_debounce) > debounce_time) {
    if (msg_to_send.button_is_pressed != current_button_state) {
      msg_to_send.button_is_pressed = current_button_state;
      sendMessage();
    }
  }
  receiveAnswer();
  last_button_state = current_button_state;
}