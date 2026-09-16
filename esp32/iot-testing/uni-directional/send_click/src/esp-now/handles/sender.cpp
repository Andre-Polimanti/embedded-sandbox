#include "esp-now/handles/sender.hpp"

uint8_t broadcastAddress[] = {0x30, 0x76, 0xF5, 0x90, 0xFA, 0x0C};
esp_now_peer_info_t peerInfo; // External type to store the paired board data

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) { // Tells us if the info got to the other board
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void sendData(const struct_message& data) { // Tells us if the board got to send the info
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &data, sizeof(data)); // Checks for errors
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  } else {
    Serial.println("Error sending the data");
  }
}