#pragma once
#include "config.hpp"

#include <esp_now.h>

extern const uint8_t broadcastAddress[];
extern esp_now_peer_info_t peerInfo;

extern message msg_to_send;

void sendMessage();
void OnMessageSent(const uint8_t *mac_addr, esp_now_send_status_t status);