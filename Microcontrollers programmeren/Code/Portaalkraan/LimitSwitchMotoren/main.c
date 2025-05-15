#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*
aansluitingen

magneet:        port 47
knop_magneet:   port 49

5Volt:          port 22
rpwm:           port 44
lpwm:           port 46
knop_motor:     port 51
                port 53
limit_switch    port 31

encoder:  A:    port 52
          B:    port 50


*/
volatile int8_t encoderValue = 0;

volatile int knop_R = 0;
volatile int knop_L = 0;
volatile int knop_m = 0;

volatile int richting;

int init(void)
{
    DDRB |=(1<<PB7);

    DDRL |=(1<<PL5); //RPWM PL5
    DDRL |=(1<<PL3); //LPWM PL3
    DDRA |=(1<<PA0); //5 volt aan

    DDRF &=~(1<<PF1);
    DDRF &=~(1<<PF2);
    DDRF &=~(1<<PF3);

    //magneet
    DDRB |= (1<<PB7); //LED D1
    DDRL |= (1<<PL2); //port 47
    DDRL |= (1<<PL0); //Port 49 knop magneet

    // knop motor
    DDRB |= (1<<PB0);   //53 omlaag LPWM
    DDRB |= (1<<PB2);   //51 omhoog RPWM

    // limit switch
    DDRC |= (1<<PC6);
}

int beweegLinks(void)
{
    PORTL &= ~(1<<PL3); //LPWM PL3
    PORTL |= (1<<PL5);
    richting = -1;
}

int beweegRechts(void)
{
    PORTL &= ~(1<<PL5); //RPWM PL5
    PORTL |= (1<<PL3);
    richting = 1;
}

int stop(void)
{
    PORTL |= (1 << PL3);
    PORTL |= (1 << PL5);
}

//toggle rechts
int toggleRechts(void)
{
    /*
    Toggled de Rechter motor aan of uit
    int rechts
    int knop_R
    */
    if (!(PINB &(1<<PB0))==0)
    {
        richting = 1;
        if (!knop_R)
            {
                knop_R = 1;
            }
    }
    else
    {
        richting = 0;
        if (knop_R)
        {
            knop_R = 0;
            PORTL ^=(1<<PL5); //RPWM PL5
            PORTL |=(1<<PL3); //LPWM PL3
        }
    }
}

                                                //togglelinks
int toggleLinks(void)
{
    /*
    Toggled de linker motor aan of uit
    int links
    int knop_L
    */
    if (!(PINB & (1<<PB2))==0)
    {
        richting = -1;
        if (!knop_L)
            {
                knop_L = 1;
            }
    }
    else
    {
        richting = 0;
        if (knop_L)
        {
            knop_L = 0;
            PORTL ^=(1<<PL3); //RPWM PL5
            PORTL |=(1<<PL5); //LPWM PL3
        }
    }
}

                                                //magneet
int toggleMagneet(void)
{
    if (!(PINL & (1<<PL0))==0)
    {
        if (!knop_m)
            {
                knop_m = 1;
            }
    }
    else
    {
        if (knop_m)
        {
            knop_m = 0;
            PORTL ^=(1<<PL2); //magneet

        }
    }
}


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
        toggleRechts();
        toggleLinks();
    }

    return 0;
}
