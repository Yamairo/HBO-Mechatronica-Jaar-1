#include <stdio.h>
#include <stdlib.h>

int getal(void)
{
    int getal;
    printf("Vul een getal in:\n");
    scanf("%d", &getal);
    if (getal < 0)
    {
        getal = getal * getal;
    }
    else {
        getal = getal * 2;
    }
    printf("De uitkomst is:\n%d", getal);
}
