/**
 * Copyright (C) 2023 by Misha Zaslavskis   
 * License is BSD 3-Clause
*/
/**
 * @file ssi.h
 * @author Misha Zaslavskis
 * @date 9 May 2023
 * @brief A header file of SSI feature http server. See in ssi.c (code of SSI feature)
 */
#ifndef __SSI_H__
#define __SSI_H__

/**
 * @brief A callback SSI (Server side includes) handler for retreiving value in website page
 * See in ssi.c code
*/
u16_t __time_critical_func(ssi_handler)(int iIndex, char *pcInsert, int iInsertLen);
/*
* @brief A function SSI initialization
* See in ssi.c code
*/
void ssi_init();
#endif // __SSI_H__