#include "esp-now/handles/sender.hpp"

const uint8_t broadcastAddress[] = {0x30, 0x76, 0xF5, 0x90, 0xFA, 0x0C};
esp_now_peer_info_t peerInfo; // External type to store the paired board data

message msg_to_send;

void sendMessage() {
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &msg_to_send, sizeof(msg_to_send)); // Checks for errors
   
  if (result == ESP_OK) {
     Serial.println("Data was received.");
  } else {
     Serial.println("Data was not received!");
  }
}

void OnMessageSent (const uint8_t *mac_addr, esp_now_send_status_t status) { // Tells us if the info got to the other board
  Serial.print("\r\nLast packet send status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
}