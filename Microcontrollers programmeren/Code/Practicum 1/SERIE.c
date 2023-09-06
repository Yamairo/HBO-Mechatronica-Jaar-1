#include <stdio.h>
#include <stdlib.h>

int serie(void)
{
    int weerstand_1;
    int weerstand_2;
    int totale_weerstand;
    printf("Wat is de waarde van de eerste weerstand?\n");
    scanf("%d", &weerstand_1);
    printf("Wat is de waarde van de tweede weerstand?\n");
    scanf("%d", &weerstand_2);
    totale_weerstand = weerstand_1 + weerstand_2;
    printf("de totale weerstand is %d", totale_weerstand);
}
