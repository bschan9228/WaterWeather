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

// ------------------------------------------------ --- ------------------------------------------------ //
// ------------------------------------------------ PWM ------------------------------------------------ //
// ------------------------------------------------ --- ------------------------------------------------ //

hw_timer_t *timer;

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
    // TODO: ledattach & pinmode overrides each other?
    ledcAttachPin(pin, PWM_CHANNEL);
    // pinMode(pin, OUTPUT);
}

void DRV8881::pwmRemovePin(int pin)
{
    ledcDetachPin(pin);
}

/**
 * @brief Enables PWM. Default timer set at 1s.
 *
 */
void DRV8881::pwmEnable()
{
    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &pwmTimer, true);
    timerAlarmWrite(timer, 1000000, true);
    timerAlarmEnable(timer);
}

void DRV8881::pwmEnable(void (*pwm_fn)(), uint64_t freq)
{
    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, pwm_fn, true);
    timerAlarmWrite(timer, freq, true);
    timerAlarmEnable(timer);
}

void DRV8881::pwmDisable()
{
    ledcWrite(PWM_CHANNEL, 0);
    timerAlarmDisable(timer);
}
