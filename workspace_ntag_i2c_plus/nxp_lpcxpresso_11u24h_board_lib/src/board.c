/*
 * @brief NXP LPCXpresso 11U37H board file
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2013
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"


/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/



/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/* System oscillator rate and clock rate on the CLKIN pin */
const uint32_t OscRateIn = 12000000;
const uint32_t ExtRateIn = 0;

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/

#define MAXLEDS 3
static const uint8_t ledBits[] = {7, 8, 9};


/* Initializes board LED(s) */
static void Board_LED_Init(void)
{
	int idx;

	for (idx = 0; idx < MAXLEDS; idx++) {
		/* Set the GPIO as output with initial state off (low) */
		Chip_GPIO_SetPinDIROutput(LPC_GPIO, 0, ledBits[idx]);
		Chip_GPIO_SetPinState(LPC_GPIO, 0, ledBits[idx], true);
	}
}


/* Sets the state of a board LED to on or off */
void Board_LED_Set(uint8_t LEDNumber, bool On)
{
	if (LEDNumber < MAXLEDS) {
		/* Toggle state, low is on, high is off */
		Chip_GPIO_SetPinState(LPC_GPIO, 0, ledBits[LEDNumber], !On);
	}
}


/* Returns the current state of a board LED */
bool Board_LED_Test(uint8_t LEDNumber)
{
	bool state = false;

	if (LEDNumber < MAXLEDS) {
		state = !Chip_GPIO_GetPinState(LPC_GPIO, 0, ledBits[LEDNumber]);
	}

	return state;
}


void Board_LED_Toggle(uint8_t LEDNumber)
{
	if (LEDNumber < MAXLEDS) {
		Chip_GPIO_SetPinToggle(LPC_GPIO, 0, ledBits[LEDNumber]);
	}
}


/* Set up and initialize all required blocks and functions related to the
   board hardware */
void Board_Init(void)
{
BOOL_32 VCC_SW_State;

	Chip_GPIO_Init(LPC_GPIO); /* Enable GPIO */

	/* Initialize LEDs */
	Board_LED_Init();

	// Setup the pins on the microcontroller
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, 1, FD_PIN);

	VCC_SW_State = Chip_GPIO_ReadPortBit(LPC_GPIO, 0, VCC_SW);

	if (VCC_SW_State) // VCC_SW_State=high if Rev G
	{
		CHAR_BOARD_MAJ = 'H';
		CHAR_BOARD_MIN = ' ';
	}
	else
	{
		Chip_GPIO_SetPinDIROutput(LPC_GPIO, 0, VCC_SW);	//switch on power for NTAG I2C
		Chip_GPIO_SetPinState(LPC_GPIO, 0, VCC_SW, true);
		CHAR_BOARD_MAJ = 'F';
		CHAR_BOARD_MIN = ' ';
	}

}

