/**
 * Copyright (C) 2023 by Misha Zaslavskis   
 * License is BSD 3-Clause
*/
/**
 * @file led.c
 * @author Misha Zaslavskis
 * @date 9 May 2023
 * @brief 
 * Led code of driving led via standard Raspberry Pi PICO W GPIOs pins. 
 * We made code organization for somebody able to find my code easily
 * It used for gpio initialize to able drive led properly  
 */

#include "led.h"

/**
 * @brief A function to initialize led to able work with LED.
 * We used and learned example from official Raspberry Pi PICO codes.
 * You allow to use a function gpio_put() after initialize    
*/
void led_init()
{
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);

    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);

    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);

    gpio_init(LED_WHITE_PIN);
    gpio_set_dir(LED_WHITE_PIN, GPIO_OUT);
}