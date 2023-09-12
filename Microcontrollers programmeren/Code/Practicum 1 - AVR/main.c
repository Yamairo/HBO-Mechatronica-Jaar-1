#include <avr/io.h> // voor gebruik DDRx
#include <util/delay.h> // voor delay_ms()
int main(void)
{
	// configureer
	DDRB = 0b10000000;
	// voor de Mega
	while (1)
	{
		// Zet led aan
		PORTB = 0b00000000;// aanzetten met '0'

		// Wacht 500 ms
		// Zet led uit
		PORTB = 0b10000000; // uitzetten met '1'
		_delay_ms(500);
		// Wacht 500 ms
	}
    return 0;
}
