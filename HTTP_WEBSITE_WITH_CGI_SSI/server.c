/**
 * Copyright (C) 2023 by Misha Zaslavskis   
 * License is BSD 3-Clause
*/
/**
 * @file server.c
 * @author Misha Zaslavskis
 * @date 9 May 2023
 * @brief Server initialization code. 
 * You must use function server_init() before running your http server. 
 * This function shoulde be use after configuration WIFI connection/mode.
 * Note: my SSI handler function - @see ssi.h and ssi.c
 * Note: my CGI handler function - @see gci.h and gci.c
 */
#include "server.h"
/**
 * @brief tCGI struct for initialize CGI feature with specfic file location in web page and CGI handler callback function
 * @see https://www.nongnu.org/lwip/2_1_x/structt_c_g_i.html 
 * @see cgi.c code for detail code
*/
extern const tCGI led_controller_cgi;
/**
 * @brief A function that http server initialized for web application with GCI and SSI feature
 * See lwIP documentation 
*/
void server_init()
{
    led_init(); /* led initialization (See in led.c and led.h) */

    httpd_init(); /* HTTP server initialization, which lwIP function is used */
    
    ssi_init(); /* SSI content supporting in HTTP server initialization (lwIP function) */

    http_set_cgi_handlers (&led_controller_cgi, 1); /* GCI handler initialization (lwIP function, but you need to create your CGI Handle function) */

    printf("Http server initialized.\n"); /* Message that finished initialization with server */
}
