#include <stdio.h>
#include <stdlib.h>

int grijswaarde(void)
{
    int grijswaarde_percentage;
    int grijswaarde_8_bit;
    printf("Wat is de grijswaarde als percentage?\n(0 - 100) geen procentteken invullen\n");
    scanf("%d", &grijswaarde_percentage);
    grijswaarde_8_bit = (grijswaarde_percentage * 255) / 100;
    printf("de grijswaarde als 8 bit getal is %d", grijswaarde_8_bit);
}
