// Definitions of the ARM chip and on-chip peripherals.
#include "at91sam7s64.h" 

//up counting loop to waste some tome
void delay()
{
	int i = 0;
	for (i = 0; i < 300000; i++){
		asm("nop");//embeded ASM "no peration"
	}
}


int main()
{
	//Get a pointer to the I/O datastructure
	volatile AT91PS_PIO pPIO = AT91C_BASE_PIOA;
	
	//Enable the I/O pins
	//this is a bit mask
	//here all 32 pins are enabled
	pPIO->PIO_PER = 0xFFFFFFFF;//LED_MASK;
	
	//set all 32 pins as output
	pPIO->PIO_OER = 0xFFFFFFFF;//LED_MASK;

	while(1)
	{
		//Set all 32 pins high
		pPIO->PIO_SODR = 0xFFFFFFFF; 

		delay();//wait

		//Set all 32 pins low
		pPIO->PIO_CODR = 0xFFFFFFFF;

		delay();//wait
	}

	return 0;
}
