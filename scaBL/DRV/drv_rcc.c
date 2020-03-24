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
 * @file   drv_rcc.c
 * @author ivan.juresa
 * @brief  Reset and Clock Control driver for STM32F42xxx.
 **************************************************************************************************/

#ifndef DRV_RCC_C_
#define DRV_RCC_C_

/***************************************************************************************************
 *                      INCLUDE FILES
 **************************************************************************************************/
#include "stm32f429xx.h"
#include "typedefs.h"

// DRV
#include "drv_rcc.h"

/***************************************************************************************************
 *                      PRIVATE DEFINES
 **************************************************************************************************/

/***************************************************************************************************
 *                      PRIVATE DATA TYPES
 **************************************************************************************************/

/***************************************************************************************************
 *                      PRIVATE VARIABLES
 **************************************************************************************************/
//! Flag indicating if DRV_RCC is initialized
static bool_t isInitialised = FALSE;

/***************************************************************************************************
 *                      GLOBAL VARIABLES DEFINITION
 **************************************************************************************************/

/***************************************************************************************************
 *                      PRIVATE FUNCTION DECLARATION
 **************************************************************************************************/

/***************************************************************************************************
 *                      PUBLIC FUNCTIONS DEFINITION
 **************************************************************************************************/
void DRV_RCC_init(void) {
    /*
     * Configure PPL before enabling HSE as if we enable HSE first PPL will go to ready state
     * and we won't be able to configure division factors.
     * */
    // Turn OFF PPL so it can be configured
    RCC->CR &= ~RCC_CR_PLLON;

    // Configure PPL
    RCC->PLLCFGR |= (RCC_PLLCFGR_PLLSRC_HSE
                      | RCC_PLLCFGR_PLLN_3
                      | RCC_PLLCFGR_PLLN_5
                      | RCC_PLLCFGR_PLLN_7
                      | RCC_PLLCFGR_PLLM_2
                      | RCC_PLLCFGR_PLLQ_0
                      | RCC_PLLCFGR_PLLQ_1
                      | RCC_PLLCFGR_PLLQ_2);

    // Enable HSE
    RCC->CR |= RCC_CR_HSEON;

    // Check if HSE is stable
    while(((RCC->CR & RCC_CR_HSEON) >> RCC_CR_HSEON_Pos) != TRUE);

    // Configure Clock
    RCC->CFGR |= RCC_CFGR_SW_HSE | RCC_CFGR_PPRE1_DIV4 | RCC_CFGR_PPRE2_DIV2;

    // Enable PPL
    RCC->CR |= RCC_CR_PLLON;

    // Wait for PPL to lock
    while(((RCC->CR & RCC_CR_PLLRDY) >> RCC_CR_PLLRDY_Pos) != TRUE);

    // Select PPL as System Clock
    RCC->CFGR = (((RCC->CFGR & (~RCC_CFGR_SW)) | RCC_CFGR_SW_PLL));

    // Wait for HW to indicate that PPL is used as System Clock
    while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

    isInitialised = TRUE;
}

void DRV_RCC_ahbEn(uint8_t inPeripheral, DRV_ERROR_err_E *outErr) {
    if(outErr != NULL_PTR) {
        if(isInitialised != TRUE) {
            *outErr = ERROR_err_NOT_INITIALISED;
        } else {
            *outErr = ERROR_err_OK;

            switch (inPeripheral) {
                case (uint8_t)RCC_ahbEn_GPIO_A:
                    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
                    break;

                case (uint8_t)RCC_ahbEn_GPIO_B:
                    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
                    break;

                case (uint8_t)RCC_ahbEn_GPIO_C:
                    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
                    break;

                case (uint8_t)RCC_ahbEn_GPIO_D:
                    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
                    break;

                case (uint8_t)RCC_ahbEn_GPIO_E:
                    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
                    break;

                case (uint8_t)RCC_ahbEn_GPIO_F:
                    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
                    break;

                case (uint8_t)RCC_ahbEn_GPIO_G:
                    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
                    break;

                case (uint8_t)RCC_ahbEn_GPIO_H:
                    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
                    break;

                case (uint8_t)RCC_ahbEn_GPIO_I:
                    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN;
                    break;

                case (uint8_t)RCC_ahbEn_GPIO_J:
                    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOJEN;
                    break;

                case (uint8_t)RCC_ahbEn_GPIO_K:
                    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOKEN;
                    break;

                case (uint8_t)RCC_ahbEn_CRC:
                    RCC->AHB1ENR |= RCC_AHB1ENR_CRCEN;
                    break;

                case (uint8_t)RCC_ahbEn_BKP_SRAM:
                    RCC->AHB1ENR |= RCC_AHB1ENR_BKPSRAMEN;
                    break;

                case (uint8_t)RCC_ahbEn_CCM_RAM:
                    RCC->AHB1ENR |= RCC_AHB1ENR_CCMDATARAMEN;
                    break;

                case (uint8_t)RCC_ahbEn_DMA_1:
                    RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;
                    break;

                case (uint8_t)RCC_ahbEn_DMA_2:
                    RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;
                    break;

                case (uint8_t)RCC_ahbEn_DMA_2D:
                    RCC->AHB1ENR |= RCC_AHB1ENR_DMA2DEN;
                    break;

                case (uint8_t)RCC_ahbEn_ETH_MAC:
                    RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACEN;
                    break;

                case (uint8_t)RCC_ahbEn_ETH_TX:
                    RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACTXEN;
                    break;

                case (uint8_t)RCC_ahbEn_ETH_RX:
                    RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACRXEN;
                    break;

                case (uint8_t)RCC_ahbEn_ETH_PTP:
                    RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACPTPEN;
                    break;

                case (uint8_t)RCC_ahbEn_USB_OTG_HS:
                    RCC->AHB1ENR |= RCC_AHB1ENR_OTGHSEN;
                    break;

                case (uint8_t)RCC_ahbEn_USB_OTG_HSULPI:
                    RCC->AHB1ENR |= RCC_AHB1ENR_OTGHSULPIEN;
                    break;

                case (uint8_t)RCC_ahbEn_DCMI:
                    RCC->AHB2ENR |= RCC_AHB2ENR_DCMIEN;
                    break;

                case (uint8_t)RCC_ahbEn_RNG:
                    RCC->AHB2ENR |= RCC_AHB2ENR_RNGEN;
                    break;

                case (uint8_t)RCC_ahbEn_USB_OTG_FS:
                    RCC->AHB2ENR |= RCC_AHB2ENR_OTGFSEN;
                    break;

                case (uint8_t)RCC_ahbEn_FMC:
                    RCC->AHB3ENR |= RCC_AHB3ENR_FMCEN;
                    break;

                default:
                    *outErr = ERROR_err_ARGS_OUT_OF_RANGE;
                    break;
            }
        }
    }
}

/***************************************************************************************************
 *                      PRIVATE FUNCTIONS DEFINITION
 **************************************************************************************************/

#endif // DRV_RCC_C_

/***************************************************************************************************
 *                      END OF FILE
 **************************************************************************************************/
