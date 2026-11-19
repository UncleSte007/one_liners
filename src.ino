#include <M5TimerCAM.h>

#define SPEED 3
#define BIT8MAX 0xFF
#define BIT9MAX 0x1FF

void setup() {
  Serial.begin(115200);
  TimerCAM.begin(true);
}

void loop() {

  delay(1);

  // let the LED follow millis() value up, then back to zero, rinse, repeat:

  TimerCAM.Power.setLed( ( (millis() >> SPEED) & BIT9MAX) > BIT8MAX?   ~((millis() >> SPEED) & BIT9MAX): (millis() >> SPEED) & BIT9MAX)  ;
  // or
  analogWrite(LED_GPIO_NUM,  
            ((millis() >> SPEED) & BIT9MAX) > BIT8MAX ?   
              ~(millis() >> SPEED) & BIT9MAX
            :
              (millis() >> SPEED) & BIT9MAX
            ) ;
  
  //
  // do something else
  //

}
  
