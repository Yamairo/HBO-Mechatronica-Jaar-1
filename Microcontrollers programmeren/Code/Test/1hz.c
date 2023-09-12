#include <avr/io.h> // voor gebruik DDRx
#include <util/delay.h> // voor delay_ms()
int hz_1(void)
{
	DDRB = 0b11000000;
	while (1)
    {
        PORTB = 0b00000000;
        int a = 0;
        while(a < 5){
            _delay_ms(100);
            a++;
        }
		PORTB = 0b11000000;
		a = 0;
        while(a < 5){
            _delay_ms(100);
            a++;
        }
	}
	return 0;
}

