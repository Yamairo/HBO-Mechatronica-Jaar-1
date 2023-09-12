#include <avr/io.h> // voor gebruik DDRx
#include <util/delay.h> // voor delay_ms()
int main(void)
{
	DDRB = 0b11000000;
	while (1)
    {
        hz_1();
        hz_2();
	}
	return 0;
}

