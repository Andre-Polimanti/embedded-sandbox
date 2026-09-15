#include "esp_now_handler.hpp"

#include <esp_now.h>
#include <WiFi.h>

uint8_t broadcastAddress[] = {0x30, 0x76, 0xF5, 0x90, 0xFA, 0x0C};
esp_now_peer_info_t peerInfo; // External type to store the paired board data

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) { // Tells us if the info got to the other board
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

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

void sendData(const struct_message& data) { // Tells us if the board got to send the info
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &data, sizeof(data)); // Checks for errors
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  } else {
    Serial.println("Error sending the data");
  }
}