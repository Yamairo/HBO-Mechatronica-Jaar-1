#include <avr/io.h> // voor gebruik DDRx
#include <util/delay.h> // voor delay_ms()
int hz_2(void)
{
	DDRB = 0b11000000;
	while (1)
    {
        PORTB = 0b00000000;
		_delay_ms(250);
		PORTB = 0b10000000;
		_delay_ms(250);
		PORTB = 0b00000000;
		_delay_ms(250);
		PORTB = 0b11000000;
		_delay_ms(250);
	}
	return 0;
}

