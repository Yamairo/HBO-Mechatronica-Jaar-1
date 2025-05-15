#include <avr/io.h>

int init(void)
{
    DDRB |=(1<<PB7);

    DDRL |=(1<<PL5); //RPWM PL5
    DDRL |=(1<<PL3);//LPWM PL3
    DDRA |=(1<<PA0);//5 volt aan

    DDRF &=~(1<<PF1);
    DDRF &=~(1<<PF2);
    DDRF &=~(1<<PF3);

    //magneet
    DDRB |= (1<<PB7); //LED D1
    DDRB |= (1<<PB1); //port 52
    DDRB |= (1<<PA2); //Port 24 knop magneet

    // knop motor
    DDRB |= (1<<PB3);   //50 omlaag LPWM
    DDRL |= (1<<PL1);   //48 omhoog RPWM
}

int beweegLinks(void)
{
    PORTA &=~(1<<PA0);
    PORTL &=~(1<<PL3);
    PORTL |=(1<<PL5);
    PORTB &=~(1<<PB7);
}


int beweegRechts(void)
{
    PORTA &=~(1<<PA0);
    PORTL &=~(1<<PL5);
    PORTL |=(1<<PL3);
    PORTB &=~(1<<PB7);
}

int zetMagneetAan(void)
{
    PORTB &= ~(1<<PB1);
}

int zetMagneeUit(void)
{
    PORTB |= (1<<PB1);
}


int main(void)
{





    while(1)
    {
        PORTL |=(1<<PL5);
        PORTL |=(1<<PL3);
        PORTB |=(1<<PB7);
    //motor
        {

    //magneet
        if ((PINA & (1<<PA2))==0)
        {


            //PORTB &= ~(1<<PB7);
        }
        if (!(PINA & (1<<PA2))==0)
        {
            PORTB |= (1<<PB1);
            //PORTB |= (1<<PB7);
        }
        }
    }
    ;

    return 0;
}
