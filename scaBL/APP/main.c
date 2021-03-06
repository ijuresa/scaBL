/***********************************************************************************************//**
 * MIT License
 * 
 * Copyright (c) 2020 ivan.juresa
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **************************************************************************************************
 * @file   main.c
 * @author ivan.juresa
 * @brief  Main file for scaBL.
 **************************************************************************************************/

#ifndef MAIN_C_
#define MAIN_C_

/***************************************************************************************************
 *                      INCLUDE FILES
 **************************************************************************************************/
#include "typedefs.h"

// DRV
#include "drv_error.h"
#include "drv_rcc.h"
#include "drv_gpio.h"

/***************************************************************************************************
 *                      PRIVATE DEFINES
 **************************************************************************************************/

/***************************************************************************************************
 *                      PRIVATE DATA TYPES
 **************************************************************************************************/

/***************************************************************************************************
 *                      PRIVATE VARIABLES
 **************************************************************************************************/

/***************************************************************************************************
 *                      GLOBAL VARIABLES DEFINITION
 **************************************************************************************************/

/***************************************************************************************************
 *                      PRIVATE FUNCTION DECLARATION
 **************************************************************************************************/
static void DRV_init(void);

/***************************************************************************************************
 *                      PUBLIC FUNCTIONS DEFINITION
 **************************************************************************************************/
int main(void) {
    /* Initialization procedure */
    // DRV
    DRV_init();

    while(TRUE);

    return 0;
}

/***************************************************************************************************
 *                      PRIVATE FUNCTIONS DEFINITION
 **************************************************************************************************/
static void DRV_init(void) {
    DRV_ERROR_err_E drvErr = ERROR_err_OK;

    // Clock
    DRV_RCC_init();

    // Initialize one LED
    DRV_GPIO_init((uint8_t)GPIO_port_G,
                  13u,
                  (uint8_t)GPIO_mode_OUTPUT,
                  (uint8_t)GPIO_oType_PUSH_PULL,
                  (uint8_t)GPIO_oSpeed_MEDIUM,
                  (uint8_t)GPIO_pupd_NONE,
                  0u,
                  &drvErr);

    DRV_GPIO_writePin((uint8_t)GPIO_port_G, 13u, 1u, &drvErr);
}

#endif // MAIN_C_

/***************************************************************************************************
 *                      END OF FILE
 **************************************************************************************************/
