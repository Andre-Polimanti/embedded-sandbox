#pragma once
#include "config.hpp"

extern volatile bool dataRcv;
extern volatile unsigned long timer;

extern bool ledOn;
extern unsigned long ledStartTime;

void receiveData();
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);