#include <avr/io.h> // voor gebruik DDRx
#include <util/delay.h> // voor delay_ms()
int main(void)
{
	DDRB = 0b10000000;
	while (1)
    {
		PORTB = 0b00000000;
		PORTB = 0b10000000;
		_delay_ms(500);
	}
	return 0;
}

