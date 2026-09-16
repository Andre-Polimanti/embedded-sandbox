#include "esp_now/handles/sender.hpp"

uint8_t broadcastAddress[] = {0x10, 0x97, 0xBD, 0xCA, 0xD0, 0x24};
esp_now_peer_info_t peerInfo;

void sendData(int& data) {
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &data, sizeof(data)); // Checks for errors
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  } else {
    Serial.println("Error sending the data");
  }
}

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) { // Tells us if the info got to the other board
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
