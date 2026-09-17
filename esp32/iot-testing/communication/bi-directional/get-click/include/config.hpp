#pragma once
#include <Arduino.h>

#include "dto.hpp"

const int BUILT_IN_LED = 2;

typedef struct struct_message {
   bool button_is_pressed;
} struct_message;
