#include <Arduino.h>
#include "LuxMeter.h"
#include "LightDependantResistor.h"
#include "AmbientLight.h"

// ##### Preferences #####
constexpr uint32_t LIGHT_ON_TIME = 5000;
constexpr uint16_t ENOUGH_LUX_THRESHOLD = 5;

// ##### Runtime #####
constexpr uint16_t BAUD_RATE = 9600;
constexpr uint32_t LOOP_DELAY = 100;

// ##### Hardware #####
// ##### Board #####
constexpr double OPERATING_VOLTAGE = 3.3;
constexpr uint16_t ADC_RESOLUTION = 4096;
constexpr uint8_t BUILTIN_LED_PIN = 2;
// ##### Motion sensor #####
constexpr uint8_t MOTION_SENSOR_PIN = 4;
// ##### Light Dependant Resistor #####
constexpr uint8_t LIGHT_DEPENDANT_RESISTOR_PIN = 15;
constexpr uint32_t LIGHT_DEPENDANT_RESISTOR_PULL_UP_RESISTOR = 10000;


unsigned long lastTrigger = 0;

LuxMeter *lightDependantResistor = new LightDependantResistor(LIGHT_DEPENDANT_RESISTOR_PIN, OPERATING_VOLTAGE,
                                                              ADC_RESOLUTION,
                                                              LIGHT_DEPENDANT_RESISTOR_PULL_UP_RESISTOR);

AmbientLight ambientLight(*lightDependantResistor, ENOUGH_LUX_THRESHOLD);

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

    Serial.println(ambientLight.enoughLux());

    delay(LOOP_DELAY);
}
