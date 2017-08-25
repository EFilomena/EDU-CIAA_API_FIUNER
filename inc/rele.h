/* Copyright 2017, 
 * Eduardo Filomena
 * efilomena@bioingenieria.edu.ar
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
#ifndef RELE_H
#define RELE_H


/*==================[inclusions]=============================================*/
#include "stdint.h"
#include "chip.h"

/*==================[macros]=================================================*/
#define lpc4337            1
#define mk60fx512vlq15     2

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/
/** \brief Definition of constants to reference the CIAA-NXP reles.
 **
 **/
enum RELE {RELE_0=1, RELE_1=2, RELE_2=4, RELE_3=8};




/*==================[external functions declaration]=========================*/

/** \brief Initialization function of CIAA-NXP reles
 **
 ** \Mapping ports (PinMux function), set direction and initial state of leds ports
 **
 ** \param[in] No parameter
 ** 
 ** \return TRUE if no error
 **/
uint8_t Init_Reles(void);


/** \brief Function to turn on a specific rele 
 ** 
 ** \param[in] rele
 **
 ** \return FALSE if an error occurs, in other case returns TRUE
 **/
uint8_t Rele_On(uint8_t rele);

/** \brief Function to turn off a specific rele 
 ** 
 ** \param[in] rele 
 **
 ** \return FALSE if an error occurs, in other case returns TRUE
 **/
uint8_t Rele_Off(uint8_t rele);

/** \brief Function to toggle a specific rele 
 ** 
 ** \param[in] rele 
 **
 ** \return FALSE if an error occurs, in other case returns TRUE
 **/
uint8_t Rele_Toggle(uint8_t rele);

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef RELE_H */

