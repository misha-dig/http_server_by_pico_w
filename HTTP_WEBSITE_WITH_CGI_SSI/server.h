/**
 * Copyright (C) 2023 by Misha Zaslavskis   
 * License is BSD 3-Clause
*/
/**
 * @file server.h
 * @author Misha Zaslavskis
 * @date 9 May 2023
 * @brief 
 * A header file of http server with SSI and GCI feature code. See code in server.c (Show how initialize server code)  
 */
#ifndef __SERVER_H__
#define __SERVER_H__

#include "lwip/apps/httpd.h" /* The include file for support lwIP HTTP web - application that able work it */
#include "lwipopts.h" /* The include file for lwIP configuration features and options. See in https://www.nongnu.org/lwip/2_1_x/group__lwip__opts.html */

#include "cgi.h" /* The include file for initialize and use GCI application */
#include "ssi.h" /* The include file for initialize and use SSI application */
#include "led.h" /* The include file for initialize LED */

/**
 * @brief Function of HTTP server for able run this server. Without initialization won't be work the server. 
*/
void server_init();

#endif // __SERVER_H__