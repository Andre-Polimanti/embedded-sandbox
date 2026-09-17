#pragma once
#include "config.hpp"

extern message received_msg;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);