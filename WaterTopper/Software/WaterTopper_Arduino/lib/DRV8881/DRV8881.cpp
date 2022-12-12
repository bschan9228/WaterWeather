#include "DRV8881.h"

/**
 * @brief Constructor for the motor driver library
 *
 */
DRV8881::DRV8881(int driver)
{
    this->driver = driver;
    pinMode(driver, OUTPUT);
}

/**
 * @brief Enables the motor driver
 *
 */
void DRV8881::enableDriver()
{
    digitalWrite(this->driver, HIGH);
}

/**
 * @brief Disables the motor driver
 *
 */
void DRV8881::disableDriver()
{
    digitalWrite(this->driver, LOW);
}

/**
 * @brief Turns on a motor
 *
 */
void DRV8881::enableMotor(int pin)
{
    digitalWrite(pin, HIGH);
}

/**
 * @brief Turns on a motor
 *
 */
void DRV8881::disableMotor(int pin)
{
    digitalWrite(pin, LOW);
}

/**
 * @brief Toggles a motor's state
 *
 * @param pin
 */
void DRV8881::toggleMotor(int pin)
{
    digitalWrite(pin, !digitalRead(pin));
}

void DRV8881::pwmInit()
{
    ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
}

void DRV8881::pwmInit(uint8_t channel, uint32_t freq, uint8_t resolution)
{
    ledcSetup(channel, freq, resolution);
}

void DRV8881::pwmAddPin(int pin)
{
    ledcAttachPin(pin, PWM_CHANNEL);
}

void DRV8881::pwmRemovePin(int pin)
{
    ledcDetachPin(pin);
}

void DRV8881::pwmEnable()
{

    // ledcWrite(pin, 100);
    for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++)
    {
        // changing the LED brightness with PWM
        ledcWrite(PWM_CHANNEL, dutyCycle);
        delay(2);
    }

    // decrease the LED brightness
    for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--)
    {
        // changing the LED brightness with PWM
        ledcWrite(PWM_CHANNEL, dutyCycle);
        delay(2);
    }
}