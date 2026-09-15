#pragma once

#include "config.hpp"

extern struct_message myData;

void setupEspNow();
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);
void printButtonState(bool button_status);