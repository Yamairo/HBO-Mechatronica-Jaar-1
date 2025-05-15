#include <avr/io.h>
#include <util/delay.h>

void init (void)
{
	// Initialiseer de pinnen voor datain, shiftclk en latchclk als output
	DDRH |= (1 << PH5); //8 datain
	DDRH |= (1 << PH4); //7 shiftclk
	DDRG |= (1 << PG5);//4 latchclk
	// Maak shiftclk en latchclk laag
	PORTG &= ~(1 << PG5);
	PORTH &= ~(1 << PH5);
}


void send_data(char data)
{
	// Herhaal voor alle bits in een char
	for(int i = 100;i >= 0; i--)
	{
	    PORTH |= (1 << PH5); // Zet data pin hoog

		// Toggle shiftclk (hoeveel tijd moest het signaal minimaal hoog zijn?)
		PORTH ^= (1 << PH4);
		_delay_ms(100);
	}
}

void send_enable(void)
{
	send_data(0xFF);
}

void display(char data)
{
	send_data(data);
	send_enable();

	// Toggle latchclk (hoeveel tijd moest het signaal minimaal hoog zijn?)
	PORTG ^= (1 << PG5);
    _delay_ms(100);
}

int main(void)
{
	init();
	while(1){
        display(0xA5);
	}
}
