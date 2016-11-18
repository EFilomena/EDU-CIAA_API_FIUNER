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

/** \brief Bare Metal driver for GPIO in the EDU-CIAA board.
 **
 **/

/*
 * Initials     Name
 * ---------------------------
 * EF		Eduardo Filomena
 * JMR		Juan Manuel Reta
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20161711 v0.1 initials initial version EF
 */

/*==================[inclusions]=============================================*/
#include "GPIO.h"

/*==================[macros and definitions]=================================*/
/** Mapping GPIO pins
 *
 *  GPIO0	pin 6_1		FUNC0	gpio3[0]
 *  GPIO1	pin 6_4		FUNC0	gpio3[3]
 *  GPIO2	pin 6_5		FUNC0	gpio3[4]
 *  GPIO3	pin 6_7		FUNC4	gpio5[15]
 *  GPIO4	pin 6_8		FUNC4	gpio5[16]
 *  GPIO5	pin 6_9		FUNC0	gpio3[5]
 *  GPIO6	pin 6_10	FUNC0	gpio3[6]
 *  GPIO7	pin 6_11	FUNC0	gpio3[7]
 *  GPIO8	pin 6_12	FUNC0	gpio3[8]
 *
 * */

#define GPIO0_PIN_GROUP       6
#define GPIO0_PIN			  1
#define GPIO0_PORT            3
#define GPIO0_BIT             0

#define GPIO1_PIN_GROUP       6
#define GPIO1_PIN			  4
#define GPIO1_PORT            3
#define GPIO1_BIT             3

#define GPIO2_PIN_GROUP       6
#define GPIO2_PIN			  5
#define GPIO2_PORT            3
#define GPIO2_BIT             4

#define GPIO3_PIN_GROUP       6
#define GPIO3_PIN			  7
#define GPIO3_PORT            5
#define GPIO3_BIT             15

#define GPIO4_PIN_GROUP       6
#define GPIO4_PIN			  8
#define GPIO4_PORT            5
#define GPIO4_BIT             16

#define GPIO5_PIN_GROUP       6
#define GPIO5_PIN			  9
#define GPIO5_PORT            3
#define GPIO5_BIT             5

#define GPIO6_PIN_GROUP       6
#define GPIO6_PIN			  10
#define GPIO6_PORT            3
#define GPIO6_BIT             6

#define GPIO7_PIN_GROUP       6
#define GPIO7_PIN			  11
#define GPIO7_PORT            3
#define GPIO7_BIT             7

#define GPIO8_PIN_GROUP       6
#define GPIO8_PIN			  12
#define GPIO8_PORT            3
#define GPIO8_BIT             8


/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/


/*==================[external functions definition]==========================*/

/** \brief Initialization function to control GPIO in the EDU-CIAA BOARD */
uint8_t Init_GPIO(void)
{
	/** \details This method calls LPCOpen functions to initialize GPIO
	 * in the EDU-CIAA board. This method has to be invoked first.
	 * */

	/** Configuration of the GPIO port*/
	Chip_GPIO_Init(LPC_GPIO_PORT);

	/** Mapping of GPIO  pins*/
	Chip_SCU_PinMux(GPIO0_PIN_GROUP,GPIO0_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC0);
	Chip_SCU_PinMux(GPIO1_PIN_GROUP,GPIO1_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC0);
	Chip_SCU_PinMux(GPIO2_PIN_GROUP,GPIO2_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC0);
	Chip_SCU_PinMux(GPIO3_PIN_GROUP,GPIO3_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC4);
	Chip_SCU_PinMux(GPIO4_PIN_GROUP,GPIO4_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC4);
	Chip_SCU_PinMux(GPIO5_PIN_GROUP,GPIO5_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC0);
	Chip_SCU_PinMux(GPIO6_PIN_GROUP,GPIO6_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC0);
	Chip_SCU_PinMux(GPIO7_PIN_GROUP,GPIO7_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC0);
	Chip_SCU_PinMux(GPIO8_PIN_GROUP,GPIO8_PIN,MD_PUP|MD_EZI|MD_ZI,FUNC0);

	return TRUE;
}

/** \brief GPIO Direction setting */
uint8_t GPIO_Set_Dir(uint8_t gpio_num,uint8_t gpio_config)
{
	uint8_t result = FALSE;
   
	if (gpio_num == GPIO0)
	{
	  Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO0_PORT,1<<GPIO0_BIT,gpio_config);
	  result = TRUE;
	}
	if (gpio_num == GPIO1)
	{
	  Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO1_PORT,1<<GPIO1_BIT,gpio_config);
	  result = TRUE;
	}
	if (gpio_num == GPIO2)
	{
	  Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO2_PORT,1<<GPIO2_BIT,gpio_config);
	  result = TRUE;
	}
	if (gpio_num == GPIO3)
	{
	  Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO3_PORT,1<<GPIO3_BIT,gpio_config);
	  result = TRUE;
	}
	if (gpio_num == GPIO4)
	{
	  Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO4_PORT,1<<GPIO4_BIT,gpio_config);
	  result = TRUE;
	}
	if (gpio_num == GPIO5)
	{
	  Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO5_PORT,1<<GPIO5_BIT,gpio_config);
	  result = TRUE;
	}
	if (gpio_num == GPIO6)
	{
	  Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO6_PORT,1<<GPIO6_BIT,gpio_config);
	  result = TRUE;
	}
	if (gpio_num == GPIO7)
	{
	  Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO7_PORT,1<<GPIO7_BIT,gpio_config);
	  result = TRUE;
	}
	if (gpio_num == GPIO8)
	{
	  Chip_GPIO_SetDir(LPC_GPIO_PORT, GPIO8_PORT,1<<GPIO8_BIT,gpio_config);
	  result = TRUE;
	}
	
	return result;
}

/** \brief Function to write on a specific GPIO */
uint8_t GPIO_Write(uint8_t gpio_num, uint8_t status)
{
	uint8_t result = FALSE;
    if (gpio_num == GPIO0)
	{
	  if (status)
	    Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,GPIO0_PORT,GPIO0_BIT);
	  else
	    Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,GPIO0_PORT,GPIO0_BIT);
	  result = TRUE;
	}
	if (gpio_num == GPIO1)
	{
	  if (status)
	    Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,GPIO1_PORT,GPIO1_BIT);
	  else
	    Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,GPIO1_PORT,GPIO1_BIT);
	  result = TRUE;
	}
	if (gpio_num == GPIO2)
	{
	  if (status)
	    Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,GPIO2_PORT,GPIO2_BIT);
	  else
	    Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,GPIO2_PORT,GPIO2_BIT);
	  result = TRUE;
	}
	if (gpio_num == GPIO3)
	{
	  if (status)
	    Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,GPIO3_PORT,GPIO3_BIT);
	  else
	    Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,GPIO3_PORT,GPIO3_BIT);
	  result = TRUE;
	}
	if (gpio_num == GPIO4)
	{
	  if (status)
	    Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,GPIO4_PORT,GPIO4_BIT);
	  else
	    Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,GPIO4_PORT,GPIO4_BIT);
	  result = TRUE;
	}
	if (gpio_num == GPIO5)
	{
	  if (status)
	    Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,GPIO5_PORT,GPIO5_BIT);
	  else
	    Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,GPIO5_PORT,GPIO5_BIT);
	  result = TRUE;
	}
	if (gpio_num == GPIO6)
	{
	  if (status)
	    Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,GPIO6_PORT,GPIO6_BIT);
	  else
	    Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,GPIO6_PORT,GPIO6_BIT);
	  result = TRUE;
	}
	if (gpio_num == GPIO7)
	{
	  if (status)
	    Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,GPIO7_PORT,GPIO7_BIT);
	  else
	    Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,GPIO7_PORT,GPIO7_BIT);
	  result = TRUE;
	}
	if (gpio_num == GPIO8)
	{
	  if (status)
	    Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,GPIO8_PORT,GPIO0_BIT);
	  else
	    Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,GPIO8_PORT,GPIO8_BIT);
	  result = TRUE;
	}
	return result;
}

/** \brief Function to read a specific GPIO */
uint8_t GPIO_Read(uint8_t gpio_num)
{
	/** \details Function to toogle a specific led at the EDU-CIAA board.
	 * 	\params uint8_t led: this word represent a specific led based on the LED_COLOR enumeration.
	 * */
    switch (gpio_num)
	{
	case GPIO0: 
	  if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,GPIO0_PORT,GPIO0_BIT))
	    return TRUE;
	  else 
        return FALSE;	  
	  break;
	case GPIO1:
	  if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,GPIO1_PORT,GPIO1_BIT))
	    return TRUE;
	  else
        return FALSE;
	  break;
	case GPIO2:
	  if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,GPIO2_PORT,GPIO2_BIT))
	    return TRUE;
	  else
        return FALSE;
	  break;
	case GPIO3:
	  if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,GPIO3_PORT,GPIO3_BIT))
	    return TRUE;
	  else
        return FALSE;
	  break;
	case GPIO4:
	  if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,GPIO4_PORT,GPIO4_BIT))
	    return TRUE;
	  else
        return FALSE;
	  break;
	case GPIO5:
	  if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,GPIO5_PORT,GPIO5_BIT))
	    return TRUE;
	  else
        return FALSE;
	  break;
	case GPIO6:
	  if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,GPIO6_PORT,GPIO6_BIT))
	    return TRUE;
	  else
        return FALSE;
	  break;
	case GPIO7:
	  if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,GPIO7_PORT,GPIO7_BIT))
	    return TRUE;
	  else
        return FALSE;
	  break;
	case GPIO8:
	  if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT,GPIO8_PORT,GPIO8_BIT))
	    return TRUE;
	  else
        return FALSE;
	  break;
	}
return FALSE;
	
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
