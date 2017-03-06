
#include <Arduino.h>
#include "sntpClock.h"

void setup() {
    delay(5000);
    sntpClock_setup();
}

void loop() {
    sntpClock_loop_debug();
}

