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

/** \brief Bare Metal driver for reles in the CIAA-NXP board.
 **
 **/



/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20170608 v0.1 initials initial version Eduardo Filomena
 */

/*==================[inclusions]=============================================*/
#include "rele.h"

/*==================[macros and definitions]=================================*/
/** Mapping Rele pins
 *
 * P4_4  en GPIO 2[4] -> Rele 0.
 * P4_5  en GPIO 2[5] -> Rele 1.
 * P4_6  en GPIO 2[6] -> Rele 2.
 * P2_1  en GPIO 5[1] -> Rele 3.
 *
 * */


/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/


/*==================[external functions definition]==========================*/

/** \brief Initialization function to control reles in the CIAA-NXP BOARD */
uint8_t Init_Reles(void)
{
	/** \details This method calls LPCOpen functions to initialize four reles
	 * in the CIAA-NXP board. This method has to be invoked first.
	 * */

	/** Configuration of the GPIO port*/
	Chip_GPIO_Init(LPC_GPIO_PORT);

	/** Mapping of rele pins*/
	Chip_SCU_PinMux(2,1,MD_PUP,FUNC4);
    
	/** Set rele port as output*/
    Chip_GPIO_SetDir(LPC_GPIO_PORT, 2,(1<<4)|(1<<5)|(1<<6),1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 5,(1<<1),1);

	
	/** Set rele initial state*/
    Chip_GPIO_ClearValue(LPC_GPIO_PORT, 2,(1<<4)|(1<<5)|(1<<6));
    Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5,(1<<1));

	

	return TRUE;
}

/** \brief Function to turn on a specific rele */
uint8_t Rele_On(uint8_t rele)
{
	/** \details Function to turn on a specific rele at the CIAA-NXP board.
	 * 	\params uint8_t rele: this word represent a specific rele based on the RELE enumeration.
	 * */
	uint8_t result = FALSE;

	if (rele & RELE_0)
	{
		Chip_GPIO_SetValue(LPC_GPIO_PORT, 2, 1<<4);
		result = TRUE;
	}
	if (rele & RELE_1)
	{
		Chip_GPIO_SetValue(LPC_GPIO_PORT, 2, 1<<5);
		result = TRUE;
	}
	if (rele & RELE_2)
	{
		Chip_GPIO_SetValue(LPC_GPIO_PORT, 2, 1<<6);
		result = TRUE;
	}
    if (rele & RELE_3)
	{
		Chip_GPIO_SetValue(LPC_GPIO_PORT, 5, 1<<1);
		result = TRUE;
	}
		return result;
}

/** \brief Function to turn off a specific rele */
uint8_t Rele_Off(uint8_t rele)
{
	/** \details Function to turn off a specific rele at the CIAA-NXP board.
		 * 	\params uint8_t rele: this word represent a specific rele based on the RELE enumeration.
		 * */
	uint8_t result = FALSE;

	if (rele & RELE_0)
	{
		Chip_GPIO_ClearValue(LPC_GPIO_PORT, 2, 1<<4);
		result = TRUE;
	}
	if (rele & RELE_1)
	{
		Chip_GPIO_ClearValue(LPC_GPIO_PORT, 2, 1<<5);
		result = TRUE;
	}
	if (rele & RELE_2)
	{
		Chip_GPIO_ClearValue(LPC_GPIO_PORT, 2, 1<<6);
		result = TRUE;
	}
	if (rele & RELE_3)
	{
		Chip_GPIO_ClearValue(LPC_GPIO_PORT, 5, 1<<1);
		result = TRUE;
	}
	return result;
}

/** \brief Function to toggle a specific rele */
uint8_t Rele_Toggle(uint8_t rele)
{
	/** \details Function to toogle a specific rele at the CIAA-NXP board.
	 * 	\params uint8_t rele: this word represent a specific rele based on the RELE enumeration.
	 * */
uint8_t result = FALSE;
	if (rele & RELE_0)
	{
		Chip_GPIO_ToggleValue(LPC_GPIO_PORT, 2, 1<<4);
		result = TRUE;
	}
	if (rele & RELE_1)
	{
		Chip_GPIO_ToggleValue(LPC_GPIO_PORT, 2, 1<<5);
		result = TRUE;
	}
	if (rele & RELE_2)
	{
		Chip_GPIO_ToggleValue(LPC_GPIO_PORT, 2, 1<<6);
		result = TRUE;
	}
	if (rele & RELE_3)
	{
		Chip_GPIO_ToggleValue(LPC_GPIO_PORT, 5, 1<<1);
		result = TRUE;
	}
	return result;

	
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
