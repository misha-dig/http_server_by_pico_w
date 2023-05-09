/**
 * Copyright (C) 2023 by Misha Zaslavskis   
 * License is BSD 3-Clause
*/
/**
 * @file cgi.c
 * @author Misha Zaslavskis
 * @date 9 May 2023
 * @brief 
 * A code of CGI (Common gateway interface) application, which the website can run external programm in server (such led controller in server side) dependent sending request.
 * We can call a handler of function to able execute a external programm (switching LEDs colors in HTTP server based by Raspberry Pi PICO W).
 * You need to create form html with able changing values and parameters. (for example <form action="/btn_led.cgi"> </form> ). See in cgi.html file in fs folder
 * Index is amount of GCI handlers which use a function. Each next handle will add by one iIndex. 
 * Our project is use single GCI handler.  
 */
#include "cgi.h"
#include "led.h" /* Include file of led driver for defined each LED colors GPIO number pins */

bool led_state = 0; /* Declarate variable of led state for turning ON/OFF LEDs */
/**
 * @brief tCGI struct for initialize CGI feature with specfic file location in web page and CGI handler callback function
 * @see https://www.nongnu.org/lwip/2_1_x/structt_c_g_i.html 
*/
const tCGI led_controller_cgi = {"/btn_led.cgi", CGIBTN_Handler};

/**
 * @brief A callback of CGI handler for LED controlling. 
 * How work this handle please see in website @see https://www.nongnu.org/lwip/2_1_x/group__httpd.html#gafe011a487c5e8d03a6b2f629e14e6b5c
 * @param iIndex a number of CGI handler
 * @param iNumParams a number of html parameter in this handler 
 * @param pcParam a string value of html elements parameter
 * @param pcValue a string value of html elements value  
 * More information about CGI handler
 * @see https://www.nongnu.org/lwip/2_1_x/group__httpd.html#gafe011a487c5e8d03a6b2f629e14e6b5c
*/
const char *CGIBTN_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
	if (iIndex == 0) /* First CGI handler */
	{
		for (int i=0; i<iNumParams; i++) /* Interate maximum number of parameters */
		{
			if (strcmp(pcParam[i], "red") == 0) /* If found red parameter of html button */
			{
                led_state = gpio_get(LED_RED_PIN); /* Recieve GPIO pin of red LED */

                gpio_put(LED_RED_PIN, !led_state); /* Write GPIO pin of red LED with inverse state */
			}

            if (strcmp(pcParam[i], "green") == 0) /* If found green parameter of html button */
			{
                led_state = gpio_get(LED_GREEN_PIN); /* Recieve GPIO pin of green LED */

                gpio_put(LED_GREEN_PIN, !led_state); /* Write GPIO pin of green LED with inverse state */
			}

            if (strcmp(pcParam[i], "blue") == 0) /* If found blue parameter of html button */
			{
                led_state = gpio_get(LED_BLUE_PIN); /* Recieve GPIO pin of blue LED */

                gpio_put(LED_BLUE_PIN, !led_state); /* Write GPIO pin of blue LED with inverse state */
			}

            if (strcmp(pcParam[i], "white") == 0) /* If found white parameter of html button */
			{
                led_state = gpio_get(LED_WHITE_PIN); /* Recieve GPIO pin of white LED */

                gpio_put(LED_WHITE_PIN, !led_state); /* Write GPIO pin of white LED with inverse state */
			}
		}
	}

	return "/cgi.html"; /* Returning path file in http server requesting after usage CGI function in web page */
}