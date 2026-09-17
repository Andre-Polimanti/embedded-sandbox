#include "esp-now/handles/receiver.hpp"

answer received_answer;
volatile bool dataRcv = false;

bool ledOn = false;
unsigned long ledStartTime = 0;

void receiveAnswer(){
  if (dataRcv) {
    ledStartTime = millis();

    digitalWrite(BUILT_IN_LED, HIGH);
    ledOn = true;

    dataRcv = false;
  }

  if (ledOn && (millis() - ledStartTime >= received_answer.press_duration)) {
    digitalWrite(BUILT_IN_LED, LOW);
    ledOn = false;
  }
}

void OnAnswerRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  if (len == sizeof(answer)) {
    memcpy(&received_answer, incomingData, sizeof(received_answer));
    dataRcv = true;
  }
}