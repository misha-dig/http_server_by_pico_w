/**
 * Copyright (C) 2023 by Misha Zaslavskis   
 * License is BSD 3-Clause
*/
/**
 * @file cgi.h
 * @author Misha Zaslavskis
 * @date 9 May 2023
 * @brief 
 * A header file of CGI functionality code. See code in cgi.c  
 */
#ifndef __CGI_H__
#define __CGI_H__
#include "lwip/apps/httpd.h"

/**
 * @brief A callback of CGI handler for maniplulate programm in server side when sent request in http server .  
*/
const char *CGIBTN_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);

#endif // __CGI_H__