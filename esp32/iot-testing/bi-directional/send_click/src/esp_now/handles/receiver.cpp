#include "esp_now/handles/receiver.hpp"

volatile bool dataRcv = false;
volatile unsigned long timer = 0;

bool ledOn = false;
unsigned long ledStartTime = 0;

void receiveData(){
  if (dataRcv) {
    ledStartTime = millis();

    digitalWrite(BUILT_IN_LED, HIGH);
    ledOn = true;

    dataRcv = false;
  }

  if (ledOn && (millis() - ledStartTime >= timer)) {
    digitalWrite(BUILT_IN_LED, LOW);
    ledOn = false;
  }
}

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy((void*)&timer, incomingData, sizeof(timer));
  dataRcv = true;
}