#include <Arduino.h>
#include "DRV8881.h"

DRV8881 motorDriver(MOTORDRIVER_1);

void setup()
{

  motorDriver.enableDriver();
  motorDriver.pwmInit();
  motorDriver.pwmAddPin(15);
  motorDriver.pwmAddPin(14);
}

void loop()
{
  motorDriver.pwmEnable();
  motorDriver.pwmRemovePin(14);
  // motorDriver.pwm();
}