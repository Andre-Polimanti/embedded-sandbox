#pragma once

typedef struct __attribute__((packed)) {
  volatile bool button_is_pressed;
} message;

typedef struct __attribute__((packed)) {
  volatile unsigned long press_duration;
} answer;