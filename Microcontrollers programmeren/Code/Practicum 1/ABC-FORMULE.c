#include <stdio.h>
#include <stdlib.h>

int abc_formule(void)
{
    int a;
    int b;
    int c;
    printf("Wat is a?:\n");
    scanf("%d", &a);
    printf("Wat is b?:\n");
    scanf("%d", &b);
    printf("Wat is c?:\n");
    scanf("%d", &c);
    int discriminant = (b * b) - (4 * a * c);
    if(discriminant >= 0)
    {
        if(discriminant > 0)
        {
            printf("De abc formule heeft 2 oplossingen");
        }
        else
        {
            printf("De abc formule heeft 1 oplossing");
        }
    }
    else
    {
        printf("De abc formule heeft 0 oplossingen");
    }
}
