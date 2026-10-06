#include <Arduino.h>

const uint8_t SENSOR_DO_PIN = 2;
const uint8_t FLAME_LED_PIN = 7;
const unsigned long PRINT_INTERVAL_MS = 500;

unsigned long lastPrintTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_DO_PIN, INPUT_PULLUP);
  pinMode(FLAME_LED_PIN, OUTPUT);
}

void loop() {
  unsigned long now = millis();
  if (now - lastPrintTime >= PRINT_INTERVAL_MS) {
    lastPrintTime = now;

    bool flameDetected = digitalRead(SENSOR_DO_PIN) == LOW;

    digitalWrite(FLAME_LED_PIN, flameDetected ? HIGH : LOW);

    Serial.println(flameDetected ? "FLAME DETECTED" : "NO FLAME");
  }
}
