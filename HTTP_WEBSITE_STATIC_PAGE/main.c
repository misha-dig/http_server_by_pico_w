/**
 * Copyright (C) 2023 by Misha Zaslavskis   
 * License is BSD 3-Clause
*/

/**
 * @file main.c
 * @author Misha Zaslavskis
 * @date 9 May 2023
 * @brief 
 * A main code that able initialize, configuare your WIFI connection and http static web-server
 * This code take from Raspberry Pi pico examples (For WIFI connection configuration).
 * You can to change any htmls and media files, you need to generate file by using automated scripts makefs.sh or makefsdata.sh
 * makefs.sh - a script which able renaming file fsdata.c into ssi_fsdata.c (you can change own filename, but you require change filename in lwipopts.sh and makefs.sh) (I created myself)
 * makefsdata - a script that generating fsdata.c (this script is created by lwIP library)
 */

#include <stdio.h> /* Use std library for printing message via printf function */
#include "pico/stdlib.h" /* Core library for supporting minimun working with Raspberry Pi PICO W */
#include "pico/cyw43_arch.h" /* Use PICO-SDK library for wifi driver*/

/**
 * @brief A main function in run time code to able initialize, configure wifi connection and http web server. 
 * All c/c++ code must include int main() or int main(int argc, char **argv) function. 
*/
int main() {

    /*
    * Text console initialize over external and internal UART interface
    * Default speed is 115200 bps and 8 bit, 1 stop bit (8N1) and no parity, flow controll XON/XOFF
    */
    stdio_init_all(); 

    /* 
     * A initialize with code of country specfic of WIFI.
     * So you can look the code in official Raspberry Pi PICO W documentation:
     * @see https://datasheets.raspberrypi.com/picow/connecting-to-the-internet-with-pico-w.pdf 
    */
    if (cyw43_arch_init_with_country(CYW43_COUNTRY_UK))  {
        printf("failed to initialise\n"); /* Print failed initialization status */
        return 1; /* Return non zero value if error appear (this code terminate in your MCU) */
    }

    printf("initialised\n"); /* Message that we initialized */

    cyw43_arch_enable_sta_mode(); /* Set WIFI mode station, which this WIFI shared to access point  */

    /* 
     * Authenicate wifi SSID and password. 
     * You can change required password and SSID of WIFI login via changing defined values by cmake building configuration
     * use argument of cmake command -DWIFI_SSID="Example_SSID" -DWIFI_SSID="Example_pwd_1234" when you configure this building configuration
     * cmake -DPICO_BOARD=pico_w -DWIFI_SSID="TPLINK" -DWIFI_PASSWORD="1234567890" ..
     */
    if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 10000)) { 
        printf("failed to connect. Please check your router setting and restart your RPI PICO W\n"); /* Print failed initialization status*/
        return 1; /* Return non zero value if error appear (this code terminate in your MCU) */
    }

    printf("Connected your WIFI. Enjoy our web server :). You can look your RPI PICO W IP address below \n"); /* Message that connection finished */

    extern cyw43_t cyw43_state; /* Initialize struct of cyw43_state for retrieving IP address */
    auto ip_addr = cyw43_state.netif[CYW43_ITF_STA].ip_addr.addr; /* Get server IP adress from router decision  */
    printf("IP Address: %lu.%lu.%lu.%lu\n", ip_addr & 0xFF, (ip_addr >> 8) & 0xFF, (ip_addr >> 16) & 0xFF, ip_addr >> 24); /* Print your IP address */
    
    httpd_init(); /* HTTP server initialization, which lwIP function is used */

    printf("Http server initialized.\n"); /* Message that finished initialization with server */

    for (;;) {} /* Infinity loops */
}
    


