#include <M5TimerCAM.h>
#define SPEED 8
#define BIT8MAX 0x1
#define BIT9MAX 0x3

void setup() {
  TimerCAM.begin(true);
}

void loop() {
  delay(1); //allow core to do other stuff

  TimerCAM.Power.setLed( ( (millis() >> SPEED) & BIT9MAX) > BIT8MAX?   ~((millis() >> SPEED) & BIT9MAX): (millis() >> SPEED) & BIT9MAX)  ;

}
