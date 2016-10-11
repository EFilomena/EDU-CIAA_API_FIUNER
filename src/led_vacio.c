/* Copyright 2016, 

 * Argentina
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Bare Metal driver for leds in the EDU-CIAA board.
 **
 **/

/*==================[inclusions]=============================================*/
#include "led.h"

/*==================[macros and definitions]=================================*/
/** Mapeo de pines Leds RGB
 * P2_0  en GPIO 5[0], LED0R y habilita el pull up.
 * P2_1  en GPIO 5[1], LED0G y habilita el pull up.
 * P2_2  en GPIO 5[2], LED0B y habilita el pull up.
 * */
#define LED_RGB_R_MUX_GROUP 2
#define LED_RGB_R_MUX_PIN 0
#define LED_RGB_R_GPIO_PORT 5
#define LED_RGB_R_GPIO_PIN 0

#define LED_RGB_G_MUX_GROUP 2
#define LED_RGB_G_MUX_PIN 1
#define LED_RGB_G_GPIO_PORT 5
#define LED_RGB_G_GPIO_PIN 1

#define LED_RGB_B_MUX_GROUP 2
#define LED_RGB_B_MUX_PIN 2
#define LED_RGB_B_GPIO_PORT 5
#define LED_RGB_B_GPIO_PIN 2

/** Mapeo de pines Leds 1, 2 y 3
 * P2_10 en GPIO 0[14], LED1 y habilita el pull up
 * P2_11 en GPIO 1[11], LED2 y habilita el pull up
 * P2_12 en GPIO 1[12], LED3 y habilita el pull up
 * */
#define LED1_MUX_GROUP 2
#define LED1_MUX_PIN 10
#define LED1_GPIO_PORT 0
#define LED1_GPIO_PIN 14

#define LED2_MUX_GROUP 2
#define LED2_MUX_PIN 11
#define LED2_GPIO_PORT 1
#define LED2_GPIO_PIN 11

#define LED3_MUX_GROUP 2
#define LED3_MUX_PIN 12
#define LED3_GPIO_PORT 1
#define LED3_GPIO_PIN 12

#define OUTPUT_DIRECTION 1
#define INPUT_DIRECTION 0

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/


/*==================[external functions definition]==========================*/

/** \brief Initialization function to control leds in the EDU-CIAA BOARD */
uint8_t initGPIO_leds_EDUCIAA(void)
{
    
}

/** \brief Function to turn on a specific led */
uint8_t ledOn(uint8_t led)
{
	
}

/** \brief Function to turn off a specific led */
uint8_t ledOff(uint8_t led)
{
	
}

/** \brief Function to turn off a specific led */
uint8_t toggleLed(uint8_t led)
{
	
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/



/* Funciones disponibles
 * Para los leds
 * Chip_GPIO_ClearValue();
 * Chip_GPIO_SetValue();
 * Chip_GPIO_SetPinOutLow();
 * Chip_GPIO_SetPinOutHigh();
 * Chip_GPIO_SetPortOutHigh();
 * Chip_GPIO_SetPinToggle();
 * Chip_GPIO_SetPortToggle();
 *
 * */
