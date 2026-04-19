/**
 * filename: GPIO.c
 * author: Benen Crombie
 *
 * Contains initialization and basic functions of GPIOs.
 *
 * Refer to the document RM0394, Rev 5. References for RM0394 chapters/sections
 * will be referenced inline (e.g., [8.5.1]).
 */

#include "GPIO.h"
#include "main.h"

bool f_test_pin_set = false; // Variable used for testing pin hooked up to LED

/**
 * @brief Enable GPIO port A/B/C clocks
 * @param void
 * @return void
 */
static void GPIO_Clocks_Enable(void)
{
    // Enable AHB1ENR for GPIOA
    RCC->AHB1ENR |= (1 << 0);

    // Enable AHB1ENR for GPIOB
    RCC->AHB1ENR |= (1 << 1);

    // Enable AHB1ENR for GPIOC
    RCC->AHB1ENR |= (1 << 2);
}

/**
 * @brief initialize a gpio with relevant registers, MODER, OTYPER, OSPEEDR,
 * PUPDR, and AFRL/H
 */
void GPIO_Pin_Init(GPIO_TypeDef *port, uint8_t pin, uint8_t GPIOx_MODER, uint8_t GPIOx_OTYPER,
                   uint8_t GPIOx_OSPEEDR, uint8_t GPIOx_PUPDR, uint8_t GPIOx_AFR)
{
    // port->REG is a specific block that has 2 bits for each pin.
    // For example, port-MODER, bits 3:2 refer to MODER for Pin 2,
    // so the starting index is further offset by (pin * 2).
    // Caveat for AFR: this is 4 bits per pin spanning two registers

    // [8.5.1] MODER, mode register
    port->MODER &= ~(0x3 << (pin * 2));        // clear 2 bits at index pin*2
    port->MODER |= (GPIOx_MODER << (pin * 2)); // set 2 bits to the new MODER

    // [8.5.2] OTYPER, output type register
    port->OTYPER &= ~(0x1 << pin);
    port->OTYPER |= (GPIOx_OTYPER << pin);

    // [8.5.3] OSPEEDR, output speed register
    port->OSPEEDR &= ~(0x3 << (pin * 2));
    port->OSPEEDR |= (GPIOx_OSPEEDR << (pin * 2));

    // [8.5.4] PUPDR, internal pull-up pull-down register
    port->PUPDR &= ~(0x3 << (pin * 2));
    port->PUPDR |= (GPIOx_PUPDR << (pin * 2));

    // AFR, alternative function register, is split into two: AFRL (low, pins
    // 0-7) and AFRH (high, pins 8-15). Each pin has 4 bits
    if (pin < 8)
    {
        // [8.5.9] AFR[0], pins 0 to 7
        port->AFR[0] &= ~(0xF << (pin * 4));
        port->AFR[0] |= (GPIOx_AFR << (pin * 4));
    }
    else
    {
        // [8.5.10] AFR[0], pins 8 to 15
        port->AFR[1] &= ~(0xF << ((pin - 8) * 4));
        port->AFR[1] |= (GPIOx_AFR << ((pin - 8) * 4));
    }
}

/**
 * @brief set a pin using BSRR
 * @param *port the gpio's port
 * @param pin the gpio pin
 * @return void
 */
void GPIO_Set(GPIO_TypeDef *port, uint8_t pin)
{
    // [8.5.7] BSRR, bit set/reset register
    // I've used ODR in the past, but BSRR simply pulses a set/reset register
    // the first 16 bits are set pins, second 16 are reset pins. Seems like the modern approach
    port->BSRR = (0x1 << pin);
}

/**
 * @brief clear a pin using BSRR
 * @param *port the gpio's port
 * @param pin the gpio pin
 * @return void
 */
void GPIO_Clear(GPIO_TypeDef *port, uint8_t pin)
{
    // [8.5.7] BSSR, bit set register
    // second 16 bits are reset, so shift pin indexer by 16
    port->BSRR = (0x1 << (pin + 16));
}

/**
 * @brief read input from the input data register (IDR)
 * @param *port the gpio's port
 * @param pin the gpio pin
 * @return void
 * @return bool output high (1) or low (0)
 */
bool GPIO_ReadInput(GPIO_TypeDef *port, uint8_t pin)
{
    // Read from IDR
    return (port->IDR >> pin) & 0x1;
}

/**
 * @brief initialize all GPIOs used in this project. See rationale behind pin
 * assignments in main.h
 * @param void
 * @return void
 */
void GPIO_Initialize(void)
{
    // Enable AHB1ENR for ports A, B, and C
    GPIO_Clocks_Enable();

    // Initialize Standard Outputs
    uint8_t OUT_MODER   = 0x01; // 01 is general purpose output mode
    uint8_t OUT_OTYPER  = 0x00; // 00 is push-pull
    uint8_t OUT_OSPEEDR = 0x03; // 11 is very high speed
    uint8_t OUT_PUPDR   = 0x00; // 00 is no pu/pd
    uint8_t OUT_AFR     = 0x00; // not relevant for standard outs

    GPIO_Pin_Init(TEST_GPIO_PORT, TEST_GPIO_PIN, OUT_MODER, OUT_OTYPER, OUT_OSPEEDR, OUT_PUPDR,
                  OUT_AFR);

    GPIO_Pin_Init(MTR_EN_PORT, MTR0_EN_PIN, OUT_MODER, OUT_OTYPER, OUT_OSPEEDR, OUT_PUPDR, OUT_AFR);
    GPIO_Pin_Init(MTR_EN_PORT, MTR1_EN_PIN, OUT_MODER, OUT_OTYPER, OUT_OSPEEDR, OUT_PUPDR, OUT_AFR);
    GPIO_Pin_Init(MTR_EN_PORT, MTR2_EN_PIN, OUT_MODER, OUT_OTYPER, OUT_OSPEEDR, OUT_PUPDR, OUT_AFR);
    GPIO_Pin_Init(MTR_EN_PORT, MTR3_EN_PIN, OUT_MODER, OUT_OTYPER, OUT_OSPEEDR, OUT_PUPDR, OUT_AFR);
    GPIO_Pin_Init(MTR_EN_PORT, MTR4_EN_PIN, OUT_MODER, OUT_OTYPER, OUT_OSPEEDR, OUT_PUPDR, OUT_AFR);
    GPIO_Pin_Init(MTR_EN_PORT, MTR5_EN_PIN, OUT_MODER, OUT_OTYPER, OUT_OSPEEDR, OUT_PUPDR, OUT_AFR);

    GPIO_Pin_Init(MTR_DIR_PORT, MTR0_DIR_PIN, OUT_MODER, OUT_OTYPER, OUT_OSPEEDR, OUT_PUPDR,
                  OUT_AFR);
    GPIO_Pin_Init(MTR_DIR_PORT, MTR1_DIR_PIN, OUT_MODER, OUT_OTYPER, OUT_OSPEEDR, OUT_PUPDR,
                  OUT_AFR);
    GPIO_Pin_Init(MTR_DIR_PORT, MTR2_DIR_PIN, OUT_MODER, OUT_OTYPER, OUT_OSPEEDR, OUT_PUPDR,
                  OUT_AFR);
    GPIO_Pin_Init(MTR_DIR_PORT, MTR3_DIR_PIN, OUT_MODER, OUT_OTYPER, OUT_OSPEEDR, OUT_PUPDR,
                  OUT_AFR);
    GPIO_Pin_Init(MTR_DIR_PORT, MTR4_DIR_PIN, OUT_MODER, OUT_OTYPER, OUT_OSPEEDR, OUT_PUPDR,
                  OUT_AFR);
    GPIO_Pin_Init(MTR_DIR_PORT, MTR5_DIR_PIN, OUT_MODER, OUT_OTYPER, OUT_OSPEEDR, OUT_PUPDR,
                  OUT_AFR);

    // // Initialize Standard Inputs
    // uint8_t IN_MODER   = 0x00; // 00 is input mode
    // uint8_t IN_OTYPER  = 0x00; // 00 is push-pull
    // uint8_t IN_OSPEEDR = 0x03; // 11 is very high speed
    // uint8_t IN_PUPDR   = 0x00; // 00 is no pu/pd
    // uint8_t IN_AFR     = 0x00; // not relevant for standard ins

    // // Initialize Analogs
    // uint8_t ANLG_MODER   = 0x03; // 11 is analog mode
    // uint8_t ANLG_OTYPER  = 0x00; // not relevant for analog
    // uint8_t ANLG_OSPEEDR = 0x00; // not relevant for analog
    // uint8_t ANLG_PUPDR   = 0x00; // 00 is no pu/pd
    // uint8_t ANLG_AFR     = 0x00; // not relevant for analog

    // Initialize PWM/Timer configs
    uint8_t PWM_MODER   = 0x02; // 10 is af mode
    uint8_t PWM_OTYPER  = 0x00; // 00 is push-pull
    uint8_t PWM_OSPEEDR = 0x03; // 11 is very high speed
    uint8_t PWM_PUPDR   = 0x00; // 00 is no pu/pd
    uint8_t PWM_AFR     = 0x01; // AF1 applies to motor STEPs 0 and 4

    GPIO_Pin_Init(MTR0_STEP_PORT, MTR0_STEP_PIN, PWM_MODER, PWM_OTYPER, PWM_OSPEEDR, PWM_PUPDR,
                  PWM_AFR);
    GPIO_Pin_Init(MTR4_STEP_PORT, MTR4_STEP_PIN, PWM_MODER, PWM_OTYPER, PWM_OSPEEDR, PWM_PUPDR,
                  PWM_AFR);

    PWM_AFR = 0x02; // AF2 applies to motor STEPs 1,2,3, and 5

    GPIO_Pin_Init(MTR1_STEP_PORT, MTR1_STEP_PIN, PWM_MODER, PWM_OTYPER, PWM_OSPEEDR, PWM_PUPDR,
                  PWM_AFR);
    GPIO_Pin_Init(MTR2_STEP_PORT, MTR2_STEP_PIN, PWM_MODER, PWM_OTYPER, PWM_OSPEEDR, PWM_PUPDR,
                  PWM_AFR);
    GPIO_Pin_Init(MTR3_STEP_PORT, MTR3_STEP_PIN, PWM_MODER, PWM_OTYPER, PWM_OSPEEDR, PWM_PUPDR,
                  PWM_AFR);
    GPIO_Pin_Init(MTR5_STEP_PORT, MTR5_STEP_PIN, PWM_MODER, PWM_OTYPER, PWM_OSPEEDR, PWM_PUPDR,
                  PWM_AFR);

    // Initialize UARTs
    uint8_t UART_MODER   = 0x02; // 10 is af mode
    uint8_t UART_OTYPER  = 0x00; // 00 is push-pull
    uint8_t UART_OSPEEDR = 0x03; // 11 is very high speed
    uint8_t UART_PUPDR   = 0x00; // 00 is no pu/pd
    uint8_t UART_AFR     = 0x07; // AF7 for all UARTs

    GPIO_Pin_Init(USART2_PORT, USART2_RX_PIN, UART_MODER, UART_OTYPER, UART_OSPEEDR, UART_PUPDR,
                  UART_AFR);
    GPIO_Pin_Init(USART2_PORT, USART2_TX_PIN, UART_MODER, UART_OTYPER, UART_OSPEEDR, UART_PUPDR,
                  UART_AFR);
    GPIO_Pin_Init(USART1_PORT, USART1_RX_PIN, UART_MODER, UART_OTYPER, UART_OSPEEDR, UART_PUPDR,
                  UART_AFR);
    GPIO_Pin_Init(USART1_PORT, USART1_TX_PIN, UART_MODER, UART_OTYPER, UART_OSPEEDR, UART_PUPDR,
                  UART_AFR);

    // I2C/SPI/Other peripherals? None yet
}

/**
 * @brief toggle the testing pin, used for testing/validating stuff is happening
 * @param void
 * @return void
 */
void GPIO_ToggleTestPin(void)
{
    // If the test pin is on, turn it off and clear flag
    if (f_test_pin_set)
    {
        GPIO_Clear(TEST_GPIO_PORT, TEST_GPIO_PIN);
        f_test_pin_set = false;
    }
    // If the test pin is off, turn it on and set flag
    else
    {
        GPIO_Set(TEST_GPIO_PORT, TEST_GPIO_PIN);
        f_test_pin_set = true;
    }
}