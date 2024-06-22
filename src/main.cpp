#include <Arduino.h>

constexpr int BAUD_RATE = 9600;
constexpr int LOOP_DELAY = 100;

constexpr int LIGHT_ON_TIME = 5000;

constexpr int MOTION_SENSOR_PIN = 4;
constexpr int BUILTIN_LED_PIN = 2;

unsigned long lastTrigger = 0;

void onLightTrigger() {
    Serial.print("Light triggered ");
    Serial.println(millis());

    lastTrigger = millis();
    digitalWrite(BUILTIN_LED_PIN, HIGH);
}

void setup() {
    Serial.begin(BAUD_RATE);

    pinMode(BUILTIN_LED_PIN, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(MOTION_SENSOR_PIN), onLightTrigger, RISING);
}

void loop() {
    if (millis() - lastTrigger > LIGHT_ON_TIME) {
        digitalWrite(BUILTIN_LED_PIN, LOW);
    }
    delay(LOOP_DELAY);
}
