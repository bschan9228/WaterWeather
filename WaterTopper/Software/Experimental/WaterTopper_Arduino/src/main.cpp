#include <Arduino.h>
#include <USB.h>
#include "DRV8881.h"

DRV8881 motorDriver(MOTORDRIVER_1);

void setup()
{
  USBSerial.begin(115200);

  motorDriver.enableDriver();
  motorDriver.pwmInit();

  motorDriver.pwmAddPin(14);
  motorDriver.pwmAddPin(15);

  motorDriver.pwmEnable(pwm_fn, 2500);
}

void loop()
{
}

uint8_t pwm_duty = 0;
boolean pwm_status = 0;
void IRAM_ATTR pwm_fn()
{
  pwm_duty = pwm_status ? (pwm_duty - 5) : (pwm_duty + 5);

  if (pwm_duty <= 0 || pwm_duty >= MAX_DUTY)
  {
    pwm_status = !pwm_status;
    return;
  }

  ledcWrite(PWM_CHANNEL, pwm_duty);
}