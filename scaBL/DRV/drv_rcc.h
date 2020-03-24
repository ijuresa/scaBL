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
 * @file   drv_rcc.h
 * @author ivan.juresa
 **************************************************************************************************/

#ifndef DRV_RCC_H_
#define DRV_RCC_H_

/***************************************************************************************************
 *                      INCLUDE FILES
 **************************************************************************************************/
#include <stdint.h>
#include "typedefs.h"

// DRV
#include "drv_error.h"

/***************************************************************************************************
 *                      DEFINES
 **************************************************************************************************/

/***************************************************************************************************
 *                      ENUMERATIONS
 **************************************************************************************************/
//! RCC AHB1 Peripheral clock register enable
typedef enum RCC_ahbEn_ENUM {
   RCC_ahbEn_GPIO_A         = 0u,
   RCC_ahbEn_GPIO_B         = 1u,
   RCC_ahbEn_GPIO_C         = 2u,
   RCC_ahbEn_GPIO_D         = 3u,
   RCC_ahbEn_GPIO_E         = 4u,
   RCC_ahbEn_GPIO_F         = 5u,
   RCC_ahbEn_GPIO_G         = 6u,
   RCC_ahbEn_GPIO_H         = 7u,
   RCC_ahbEn_GPIO_I         = 8u,
   RCC_ahbEn_GPIO_J         = 9u,
   RCC_ahbEn_GPIO_K         = 10u,
   RCC_ahbEn_CRC            = 11u,
   RCC_ahbEn_BKP_SRAM       = 12u,
   RCC_ahbEn_CCM_RAM        = 13u,
   RCC_ahbEn_DMA_1          = 14u,
   RCC_ahbEn_DMA_2          = 15u,
   RCC_ahbEn_DMA_2D         = 16u,
   RCC_ahbEn_ETH_MAC        = 17u,
   RCC_ahbEn_ETH_TX         = 18u,
   RCC_ahbEn_ETH_RX         = 19u,
   RCC_ahbEn_ETH_PTP        = 20u,
   RCC_ahbEn_USB_OTG_HS     = 21u,
   RCC_ahbEn_USB_OTG_HSULPI = 22u,
   RCC_ahbEn_DCMI           = 23u,
   RCC_ahbEn_RNG            = 24u,
   RCC_ahbEn_USB_OTG_FS     = 25u,
   RCC_ahbEn_FMC            = 26u,
   RCC_ahbEn_COUNT          = 27u
} RCC_ahbEn_E;

/***************************************************************************************************
 *                      UNIONS
 **************************************************************************************************/

/***************************************************************************************************
 *                      DATA TYPES
 **************************************************************************************************/

/***************************************************************************************************
 *                      DATA STRUCTURES
 **************************************************************************************************/

/***************************************************************************************************
 *                      GLOBAL VARIABLES DECLARATIONS
 **************************************************************************************************/

/***************************************************************************************************
 *                      PUBLIC FUNCTION PROTOTYPES
 **************************************************************************************************/
void DRV_RCC_init(void);
void DRV_RCC_ahbEn(uint8_t inPeripheral, DRV_ERROR_err_E *outErr);

#endif /* DRV_RCC_H_ */

/***************************************************************************************************
 *                      END OF FILE
 **************************************************************************************************/
