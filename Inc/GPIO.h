/*
 * filename: GPIO.h
 * author: Benen Crombie
 *
 * Header for GPIO functions
 */

#ifndef GPIO_H
#define GPIO_H

#include "main.h"

// void GPIO_Clocks_Enable(void);
void GPIO_Pin_Init(GPIO_TypeDef *port, uint8_t pin, uint8_t GPIOx_MODER, uint8_t GPIOx_OTYPER,
                   uint8_t GPIOx_OSPEEDR, uint8_t GPIOx_PUPDR, uint8_t GPIOx_AFR);
void GPIO_Set(GPIO_TypeDef *port, uint8_t pin);
void GPIO_Clear(GPIO_TypeDef *port, uint8_t pin);
bool GPIO_ReadInput(GPIO_TypeDef *port, uint8_t pin);
void GPIO_Initialize(void);
void GPIO_ToggleTestPin(void);

#endif