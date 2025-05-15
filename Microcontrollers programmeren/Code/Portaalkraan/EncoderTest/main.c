#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile int8_t encoderValue = 0;

void setup()
{
    // Leds
    DDRB |= (1 << PB7); // Led 1
    DDRB |= (1 << PB6); // Led 2

    // Encoder inputs
    DDRB &= ~(1 << PB1); // A
    DDRB &= ~(1 << PB3); // B

    // Pull-up for encoder inputs
    PORTB |= (1 << PB1) | (1 << PB3);

    // Enable external interrupts for INT0 (PB1) and INT1 (PB3)
    EIMSK |= (1 << INT0) | (1 << INT1);

    // Trigger interrupt on logical change
    MCUCR |= (1 << ISC01) | (1 << ISC11);

    sei(); // Enable global interrupts
}

ISR(INT0_vect)
{
    // Handle interrupt for A (PB1)
    if (bit_is_clear(PINB, PB1))
    {
        if (bit_is_clear(PINB, PB3))
        {
            encoderValue++;
        }
        else
        {
            encoderValue--;
        }
    }
}

ISR(INT1_vect)
{
    // Handle interrupt for B (PB3)
    if (bit_is_clear(PINB, PB3))
    {
        if (bit_is_clear(PINB, PB1))
        {
            encoderValue--;
        }
        else
        {
            encoderValue++;
        }
    }
}

int main(void)
{
    setup();

    while (1)
    {
        // Handle encoder value and control LEDs accordingly
        if (encoderValue > 0)
        {
            PORTB |= (1 << PB7);
            PORTB &= ~(1 << PB6);
        }
        else if (encoderValue < 0)
        {
            PORTB |= (1 << PB6);
            PORTB &= ~(1 << PB7);
        }
        else
        {
            // Encoder value is zero, turn off both LEDs
            PORTB &= ~(1 << PB6) & ~(1 << PB7);
        }
        _delay_ms(10);
    }

    return 0;
}
