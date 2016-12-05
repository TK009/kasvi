
#include <Ticker.h>
#include <TickerScheduler.h>

int PumpPin = 2;
uint32_t PumpInterval = 60 * 60 * 1000;
uint32_t PumpOnTime = 60 * 1000;

TickerScheduler timer(1);

void errorBlink() {
    pinMode(LED_BUILTIN, OUTPUT);
    while (true) {
        digitalWrite(LED_BUILTIN, LOW); 
        delay(1000);
        digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
        delay(1000);
    }
}
void runPump() {
    digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
    digitalWrite(PumpPin, LOW);
    delay(PumpOnTime);
    digitalWrite(PumpPin, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH

}

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("Hello world");
    delay(1000);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(PumpPin, HIGH);
    pinMode(PumpPin, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
    

    if (!timer.add(0, PumpInterval, runPump, true)) {
        Serial.println("Error: timer didn't start");
        errorBlink();
    }
    timer.enableAll();
}



void loop() {
    timer.update();
    delay(2000);
}
