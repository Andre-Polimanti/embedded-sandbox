#pragma once

#include <Arduino.h>

const int BUILT_IN_BUTTON = 35;
const int BUILT_IN_LED = 15;

typedef struct struct_message {
  bool button_is_pressed;
} struct_message;