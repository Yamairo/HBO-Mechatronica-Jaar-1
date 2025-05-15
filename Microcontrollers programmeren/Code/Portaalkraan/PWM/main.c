/*
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void initLed()
{
    DDRB |= (1 << PB6);
}

static void initTimer(void)
{
    TCCR3A = 0;
    TCCR3B = (1 << CS32) | (1 << CS30);
    TCCR3C = 0;
    TIMSK3 = (1 << TOIE3);
}

ISR(TIMER3_OVF_vect)
{
    DDRB &= ~(1 << PB6);
    _delay_ms(100);
}

int teller = 0;
while (1)
{
    if (TIFR0 & (1 << TOV0))
    { // Timer overflow, +/- 1 ms voorbij
        TIFR0 = (1 << TOV0);
        if (teller++ > 500)
        {
            teller = 0; // Wis flag
            PORTB ^= (1 << PB7);
        }
    }
}
