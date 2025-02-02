/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#include "hal.h"

#if HAL_USE_PAL || defined(__DOXYGEN__)
/**
 * @brief   PAL setup.
 * @details Digital I/O ports static configuration as defined in @p board.h.
 *          This variable is used by the HAL when initializing the PAL driver.
 */
const PALConfig pal_default_config = {
  #if SN32_HAS_GPIOA
  {VAL_GPIOA_MODE},
  #endif
  #if SN32_HAS_GPIOB
  {VAL_GPIOB_MODE},
  #endif
  #if SN32_HAS_GPIOC
  {VAL_GPIOC_MODE},
  #endif
  #if SN32_HAS_GPIOD
  {VAL_GPIOD_MODE},
  #endif
};
#endif

static int flag __attribute__((section(".flag"))) __attribute__((__used__)) = 0xAAAA5555;

/**
 * @brief   Early initialization code.
 * @details This initialization must be performed just after stack setup
 *          and before any other initialization.
 */
void __early_init(void) {
  sn32_clock_init();
}

// void Reset_Handler(void) {
//     setPinOutput(C4);
//     setPinInputHigh(A0);
//     if (readPin(A0) == 0) {
//         asm ("mov %%sp, %0; bx %1;"
//                 :
//                 : "r"(0x200006C8), "r"(0x1fff0009)
//                 : );
//     }
//     asm ("mov %%sp, %0; bx %1;"
//             :
//             : "r"(0x200006C8), "r"(0x7801)
//             : );
// }

/**
 * @brief   Board-specific initialization code.
 */
void boardInit(void) {
  SN_SYS0->SWDCTRL_b.SWDDIS = 1; // Disable SWD
}
