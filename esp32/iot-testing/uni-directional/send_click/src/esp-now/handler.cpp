#include "esp-now/handler.hpp"

#include <esp_now.h>
#include <WiFi.h>

void setupEspNow() {
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(esp_now_send_cb_t(OnDataSent)); // Registering our callback function
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6); // A mac always has 6 bytes of size
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}