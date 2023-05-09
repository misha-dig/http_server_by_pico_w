/**
 * Copyright (C) 2023 by Misha Zaslavskis   
 * License is BSD 3-Clause
*/
/**
 * @file ssi.c
 * @author Misha Zaslavskis
 * @date 9 May 2023
 * @brief Code of support SSI feature for creating dynamic web page by changing value. 
 * Each html comment is SSI tags if defined exact name of SSI tags in list SSI tage (see array of const char *  __not_in_flash("httpd") ssi_tags[] )
 * Example html comment is <!--#Vol--> that will retrieve data of 'Vol'
 * Important that you need to follow sequence index in SSI tage list, otherwise you will get confused value. 
 * In our ssi.c code, 
 * 0 index - 'uptime' value
 * 1 index - 'Vol' value
 * 2 index - 'temp' value
 * 
 * More info: 
 * @see https://www.nongnu.org/lwip/2_1_x/group__httpd.html#gaf88dacc4f18d299084cab75252001319
 * @see https://www.nongnu.org/lwip/2_1_x/group__httpd.html#ga8834ecb16d9a7d6c128bdf9514b7879c
 * 
 * Note: Temperature value won't update becuase i haven't digital temperature sensor (i don't want to build thermistor circuit becuase diffculity to calculate for me)
 * I very sorry that missing real thermometer in this project due insuffcient temperature sensor. We will add temperature sensor in this code.
 */
#include "lwip/apps/httpd.h"
#include "pico/cyw43_arch.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "ssi.h"
/**
 * @brief A variable of uptime since Raspberry Pi PICO W since boot (Connected to power into MCU board) in seconds.
 * Look timer callback in main.c
*/
extern uint64_t current_time_in_seconds;
/** 
 * @brief A list of SSI tags, which they will dynamical changing value by refreshing webpage. 
 * */
const char *  __not_in_flash("httpd") ssi_tags[] = {
    "uptime", // 0th index
    "Vol", // 1st index
    "temp", // 2nd index
};
/**
 * @brief A SSI callback for settings value and executing programm by server side. A client side will recieve data form http web page.   
*/
u16_t __time_critical_func(ssi_handler)(int iIndex, char *pcInsert, int iInsertLen) {
    size_t printed;
    switch (iIndex) {
        case 0: // uptime value
        {
            printed = snprintf(pcInsert, iInsertLen, "%d", current_time_in_seconds); /* Print received current uptime into SSI html (shtml) page */
        }
        break;
        case 1: // Vol value
        {
            float result = adc_read() * (3.3f / (1 << 12)); /* Measure voltage of ADC in GPIO 26 */
            printed = snprintf(pcInsert, iInsertLen, "%.2f", result); /* Print received value of voltage into SSI html (shtml) page */
        }
        break; 
        case 2: // temp value
        {
            float exp_val = 24.9; /* Measure temperature of air (Note: For illustrate the example how works SSI feature) */
            printed = snprintf(pcInsert, iInsertLen, "%.1f", exp_val); /* Print received value of air temperature into SSI html (shtml page) */
        }
        break;
        /* Other case with SSI event. Please see in lwIP documentation @see https://www.nongnu.org/lwip/2_1_x/group__httpd.html#gafe011a487c5e8d03a6b2f629e14e6b5c */
        default: // Unknown values and tags
        printed = 0; /* So not print any value into SSI html page unless specfic tags commented in shtml file */
        break;
    }

    LWIP_ASSERT("same length", printed <= 0xFFFF);
    return (u16_t)printed; /* Return printed value if correct work */
}
/**
 * @brief SSI HTTP server initialization SSI feature
 * This function can use after calling function httpd_init();
*/
void ssi_init()
{
    /* Check array size of ssi tags */
    for (size_t i = 0; i < LWIP_ARRAYSIZE(ssi_tags); i++) {
        LWIP_ASSERT("tag too long for LWIP_HTTPD_MAX_TAG_NAME_LEN",
                    strlen(ssi_tags[i]) <= LWIP_HTTPD_MAX_TAG_NAME_LEN);
    }
    http_set_ssi_handler(ssi_handler, ssi_tags, LWIP_ARRAYSIZE(ssi_tags)); /* HTTP server with SSI feature setting */
    
    /* To initialize GPIO and ADCs by using PICO SDK API function */
    adc_init(); /* ADC initialization */
    adc_gpio_init(26); /* ADC GPIO allocation initialization */
    adc_select_input(0); /* Number ADC selection (see in PICO SDK API Documentation) */
}
