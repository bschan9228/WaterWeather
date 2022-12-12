#include <Arduino.h>

// use first channel of 16 channels (started from zero)
#define LEDC_CHANNEL_0 0

// use 12 bit precission for LEDC timer
#define LEDC_TIMER_12_BIT 12

// use 5000 Hz as a LEDC base frequency
#define LEDC_BASE_FREQ 5000

// fade LED PIN (replace with LED_BUILTIN constant for built-in LED)
#define LED_PIN 5

int brightness = 75; // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

void ledcAnalogWrite(uint8_t channel, uint32_t value, uint32_t valueMax = 255)
{
  // calculate duty, 4095 from 2 ^ 12 - 1
  uint32_t duty = (4095 / valueMax) * min(value, valueMax);

  // write duty to LEDC
  ledcWrite(channel, duty);
}

void IRAM_ATTR isr()
{
  // digitalWrite(18, !digitalRead(23));
  if (digitalRead(23))
    ledcAnalogWrite(LEDC_CHANNEL_0, 100);
  else
    ledcAnalogWrite(LEDC_CHANNEL_0, 255);
}

void setup()
{
  Serial.begin(115200);
  pinMode(23, INPUT);
  pinMode(23, INPUT_PULLUP);

  // pinMode(18, OUTPUT);

  ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_12_BIT);
  ledcAttachPin(18, LEDC_CHANNEL_0);

  attachInterrupt(23, isr, CHANGE);
}

void loop()
{

  // Serial.println(digitalRead(18));
  // delay(500);

  // // set the brightness on LEDC channel 0
  // ledcAnalogWrite(LEDC_CHANNEL_0, brightness);

  // // change the brightness for next time through the loop:
  // brightness = brightness + fadeAmount;

  // // reverse the direction of the fading at the ends of the fade:
  // if (brightness <= 75 || brightness >= 255)
  // {
  //   fadeAmount = -fadeAmount;
  // }
  // // wait for 30 milliseconds to see the dimming effect
  // delay(50);
}