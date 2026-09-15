#include "esp_now_handler.hpp"

#include <esp_now.h>
#include <WiFi.h>

struct_message myData;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));

  Serial.print("Bytes received: ");
  Serial.println(len);

  printButtonState(myData.button_is_pressed);
}

void setupEspNow() {
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv)); // Registering callback function
}

void printButtonState(bool button_status) {
  Serial.print("The button is ");

  if (myData.button_is_pressed) {
    Serial.print("pressed, led on.");
  }else{
    Serial.print("unpressed, led off.");
  }
  Serial.println();
}