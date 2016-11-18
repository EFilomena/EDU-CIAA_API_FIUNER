/* Copyright 2016, 
 * Eduardo Filomena
 * efilomena@bioingenieria.edu.ar
 * Juan Manuel Reta
 * jmrera@bioingenieria.edu.ar
 * Facultad de Ingeniería
 * Universidad Nacional de Entre Ríos
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
#ifndef GPIO_H
#define GIPO_H


/*==================[inclusions]=============================================*/
#include "stdint.h"
#include "chip.h"

/*==================[macros]=================================================*/
#define lpc4337            1
#define mk60fx512vlq15     2

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/
/** \brief Definition of constants to reference the EDU-CIAA GPIO.
 **
 **/
enum GPIO_NUM {GPIO0,GPIO1,GPIO2,GPIO3,GPIO4,GPIO5,GPIO6,GPIO7,GPIO8};


/** \brief Definition of constants to control the EDU-CIAA GPIO.
 **
 **/
enum GPIO_CONFIG {INPUT,OUTPUT,INPUT_PUP,INPUT_PDN_INPUT_PUP_PDN};

#define OUTPUT   1
#define INPUT    0


/*==================[external functions declaration]=========================*/

/** \brief Initialization function of EDU-CIAA GPIO
 **
 ** 
 ** \return TRUE if no error
 **/
uint8_t Init_GPIO(void);

/** \brief Direction setting of  GPIO
 **
 ** 
 ** \param[in] GPIO number (GPIO0... GPIO8)  and config (INPUT,OUTPUT, INPUT_PUP.....)
 ** 
 ** \return TRUE if no error
 **/
uint8_t GPIO_Set_Dir(uint8_t gpio_num,uint8_t gpio_config);
 
/** \brief Function to write on a specific GPIO 
 ** 
 ** \param[in] GPIO number (GPIO0... GPIO8) and status (0 or 1,  TRUE or FALSE)
 **
 ** \return FALSE if an error occurs, in other case returns TRUE
 **/
uint8_t GPIO_Write(uint8_t gpio_num, uint8_t status);

/** \brief Function to read a specific GPIO 
 ** 
 ** \param[in] GPIO number (GPIO0... GPIO8)
 **
 ** \return 0 or 1
 **/
uint8_t GPIO_Read(uint8_t gpio_num);



/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef GPIO_H */

