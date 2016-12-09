
#include <Ticker.h>
#include <TickerScheduler.h>

#define NUM_TIMERS 3
#define TimerMinute 0
//#define TimerPump1 1
#define Void ((void)0)
#define USELED 0

const int PumpPin = 2;
const uint32_t PumpIntervalMins = 120; //* 60 * 1000;
const uint32_t PumpOnTime = 55 * 1000;
const uint32_t MinuteInterval = 60 * 1000; //HeartbeatInterval
uint32_t minuteCounter = 0;

TickerScheduler timers(NUM_TIMERS);
Ticker pumpOffTimer;

#if USELED
inline void ledOn(){ digitalWrite(LED_BUILTIN, LOW); } // Turn the LED on (Note that LOW is the voltage level
inline void ledOff(){ digitalWrite(LED_BUILTIN, HIGH); } // Turn the LED off by making the voltage HIGH
#else
inline void ledOn(){ } // No operation
inline void ledOff(){ }
#endif
inline void pumpOn(){ digitalWrite(PumpPin, LOW); } // Using inverted input relay module
inline void pumpOff(){ digitalWrite(PumpPin, HIGH); }


void errorBlink() {
    pinMode(LED_BUILTIN, OUTPUT);
    while (true) {
        ledOn(); delay(500);
        ledOff(); delay(500);
    }
}

void pumpStop() {
    Serial.println("pump_off");
    pumpOff();
    //ledOff(); timers.enable(TimerLed);
}
void pumpStart() {
    Serial.println("pump_on");

    //timers.disable(TimerLed); ledOn(); // enabled in pumpStop()
    pumpOn();

    pumpOffTimer.once_ms(PumpOnTime, pumpStop);
}

void heartbeatMinute() {
    Serial.print("heartbeat");
    minuteCounter++;
    Serial.println(minuteCounter);
    if (minuteCounter % PumpIntervalMins == 0)
        pumpStart();
}


void setup() {
    pumpOff(); // try to ensure that pump doesn't start yet
    pinMode(PumpPin, OUTPUT);
    

    delay(3000); // some recovery time for serial from garbage
    Serial.begin(115200);
    delay(1000);
    Serial.println("booting");

#if USELED
    pinMode(LED_BUILTIN, OUTPUT);
#endif
    ledOff();


    Serial.print("scheduling... ");
    timers.add(TimerMinute, MinuteInterval, heartbeatMinute, false) ? Void : errorBlink();
    //timers.add(TimerPump1, PumpInterval, pumpStart, false) ? Void : errorBlink();
    Serial.println("OK");
}



void loop() {
    timers.update();
}
