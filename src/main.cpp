#include <Arduino.h>

constexpr int BOUD_RATE = 9600;

void setup() {
    Serial.begin(BOUD_RATE);
}

void loop() {
    Serial.println("Hello, World!");
    delay(1000);
}