#include <stdio.h>
#include <stdlib.h>

int groter(void)
{
    int getal_1;
    int getal_2;
    printf("Wat is de waarde van de eerste getal?\n");
    scanf("%d", &getal_1);
    printf("Wat is de waarde van de tweede getal?\n");
    scanf("%d", &getal_2);
    if(getal_1 > getal_2){
        if (getal_1 > getal_2 * 2){
            printf("Getal 1 is veel groter dan getal 2");
        }
        else{
            printf("Getal 1 is groter dan getal 2");
        }
    }
}
