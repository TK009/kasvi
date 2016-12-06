
#include <Ticker.h>
#include <TickerScheduler.h>

int PumpPin = 2;
uint32_t PumpInterval = 120 * 60 * 1000;
uint32_t PumpOnTime = 60 * 1000;

TickerScheduler timer(1);

inline void ledOn(){ digitalWrite(LED_BUILTIN, LOW); } // Turn the LED on (Note that LOW is the voltage level
inline void ledOff(){ digitalWrite(LED_BUILTIN, HIGH); } // Turn the LED off by making the voltage HIGH
inline void pumpOn(){ digitalWrite(PumpPin, LOW); } // Using inverted input relay module
inline void pumpOff(){ digitalWrite(PumpPin, HIGH); }

void errorBlink() {
    pinMode(LED_BUILTIN, OUTPUT);
    while (true) {
        ledOn(); delay(500);
        ledOff(); delay(500);
    }
}
void runPump() {
    Serial.print("pump_on\r\n");

    ledOn(); pumpOn();
    delay(PumpOnTime);
    pumpOff(); ledOff();

    Serial.print("pump_off\r\n");
}


void setup() {
    Serial.begin(115200);

    delay(1000);
    Serial.print("booting\r\n");
    delay(1000);

    pinMode(LED_BUILTIN, OUTPUT);
    ledOff();

    pumpOff(); // try to ensure that pump doesn't start yet
    pinMode(PumpPin, OUTPUT);
    

    if (!timer.add(0, PumpInterval, runPump, true)) {
        Serial.println("Error: timer didn't start");
        errorBlink();
    }
    timer.enableAll();
}



void loop() {
    timer.update();
    delay(10000);
    ledOn();
    Serial.print("heartbeat\r\n");
    delay(100);
    ledOff();
}
