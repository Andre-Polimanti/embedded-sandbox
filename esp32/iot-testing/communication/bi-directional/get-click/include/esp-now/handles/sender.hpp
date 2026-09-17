#pragma once
#include "config.hpp"

#include <esp_now.h>

extern uint8_t broadcastAddress[];
extern esp_now_peer_info_t peerInfo;

extern answer answer_to_send;

void sendAnswer();
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);
