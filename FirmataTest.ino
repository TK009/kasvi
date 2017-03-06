
#define DEBUGFIRMATA 1
#include <Arduino.h>
#include <FirmataConstants.h>
#include "StandardFirmata.h"


using namespace firmata;
const char ledPin[] = {SET_PIN_MODE,          LED_BUILTIN, PIN_MODE_OUTPUT}; 
const char ledOn[]  = {SET_DIGITAL_PIN_VALUE, LED_BUILTIN, 0}; 
const char ledOff[] = {SET_DIGITAL_PIN_VALUE, LED_BUILTIN, 1}; 

unsigned int nextTrigger = 0;
bool onFlag = true;

void setup() {
    Serial.begin(115200);
    delay(5000);

    Serial.println(F("[SETUP] firmata"));
    Serial.flush();
    firmata_setup();
    Serial.println(F("[SETUP] pinMode"));
    Serial.flush();
    FirmataConnector.provideInput(ledPin);

    nextTrigger = millis()+1000;
}

void loop() {
    firmata_loop();

    if (nextTrigger <= millis()){
        if (onFlag) {
            Serial.println(F("[LOOP] ledOff"));
            FirmataConnector.provideInput(ledOff, sizeof(ledOff));
            onFlag = false;
        } else {
            Serial.println(F("[LOOP] ledOn"));
            FirmataConnector.provideInput(ledOn, sizeof(ledOn));
            onFlag = true;
        }
        nextTrigger = millis()+1000;
    }
}

