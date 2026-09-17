#pragma once
#include "config.hpp"

extern bool ledOn;
extern unsigned long ledStartTime;

extern answer answer_received;

void receiveAnswer();
void OnAnswerRecv(const uint8_t * mac, const uint8_t *incomingData, int len);