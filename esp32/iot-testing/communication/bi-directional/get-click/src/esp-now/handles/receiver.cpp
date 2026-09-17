#include "esp-now/handles/receiver.hpp"

message received_msg;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  if (len == sizeof(message)) {
    memcpy(&received_msg, incomingData, sizeof(received_msg));
  }
}