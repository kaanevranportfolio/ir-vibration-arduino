#include <Arduino.h>

const uint8_t LED_PIN = 13;
const unsigned long BLINK_INTERVAL_MS = 500; // 1 Hz toggle -> 2 Hz full cycle

unsigned long lastToggleTime = 0;
bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledState);
}

void loop() {
  unsigned long now = millis();
  if (now - lastToggleTime >= BLINK_INTERVAL_MS) {
    lastToggleTime = now;
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }
}
