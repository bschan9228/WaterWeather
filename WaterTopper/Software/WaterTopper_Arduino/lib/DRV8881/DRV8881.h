#ifndef DRV8881_H
#define DRV8881_H

#include <Arduino.h>
#include "DRV8881_config.h"

#define PWM_FREQ 5000
#define PWM_RESOLUTION 8
#define PWM_CHANNEL 0
#define MAX_DUTY 255

void IRAM_ATTR pwmTimer();

class DRV8881
{
private:
    int driver;

public:
    // ------------------------------------------- ------------ ------------------------------------------- //
    // ------------------------------------------- MOTOR DRIVER ------------------------------------------- //
    // ------------------------------------------- ------------ ------------------------------------------- //

    /**
     * @brief Initializes the motor driver library
     * @param driver Motor driver pin number
     */
    DRV8881(int driver);

    /**
     * @brief Enables the motor driver
     *
     */
    void enableDriver();

    /**
     * @brief Disables the motor driver
     *
     */
    void disableDriver();

    /**
     * @brief Turns on a motor
     *
     */
    void enableMotor(int pin);

    /**
     * @brief Turns on a motor
     *
     */
    void disableMotor(int pin);

    /**
     * @brief Toggles a motor's state
     *
     */
    void toggleMotor(int pin);

    // ------------------------------------------------ --- ------------------------------------------------ //
    // ------------------------------------------------ PWM ------------------------------------------------ //
    // ------------------------------------------------ --- ------------------------------------------------ //

    void pwmInit();

    void pwmInit(uint8_t channel, uint32_t freq, uint8_t resolution);

    void pwmAddPin(int pin);

    void pwmRemovePin(int pin);

    void pwmEnable();

    void pwmEnable(void (*fn)(), uint64_t freq);

    void pwmDisable();
};

#endif