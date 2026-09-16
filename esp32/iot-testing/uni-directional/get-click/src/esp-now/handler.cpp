#include "esp-now/handler.hpp"

#include <esp_now.h>
#include <WiFi.h>

void setupEspNow() {
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv)); // Registering callback function
}