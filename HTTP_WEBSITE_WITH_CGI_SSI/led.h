/**
 * Copyright (C) 2023 by Misha Zaslavskis   
 * License is BSD 3-Clause
*/
/**
 * @file led.h
 * @author Misha Zaslavskis
 * @date 9 May 2023
 * @brief 
 * A header file of LEDs code. See code in led.c  
 */
#ifndef __LED_H__
#define __LED_H__

#include "hardware/gpio.h" /* Add PICO SDK include file for support GPIO drive pins */
/**
 * @brief Defined number of LED pins
 * This macros are showed number of gpio that I will connect to LED diode/driver.
 * Red LED is connected in number 19 pin of Raspberry PI Pico W board 
*/
#define LED_RED_PIN 19
/**
 * @brief Defined number of LED pins
 * This macros are showed number of gpio that I will connect to LED diode/driver.
 * Green LED is connected in number 20 pin of Raspberry PI Pico W board 
*/
#define LED_GREEN_PIN 20
/**
 * @brief Defined number of LED pins
 * This macros are showed number of gpio that I will connect to LED diode/driver.
 * Blue LED is connected in number 21 pin of Raspberry PI Pico W board 
*/
#define LED_BLUE_PIN 21
/**
 * @brief Defined number of LED pins
 * This macros are showed number of gpio that I will connect to LED diode/driver.
 * White LED is connected in number 18 pin of Raspberry PI Pico W board 
*/
#define LED_WHITE_PIN 18

/**
 * @brief Function of GPIO initialize for driving LEDs diode/driver. 
*/
void led_init();

#endif // __LED_H__