#include <stdio.h>
#include <math.h>

int main(void) {
 
    double szam = 1;
    double tizedesjegy = 0.1;
    double pontossag;

    printf("Mekkora tizedesjegy pontossaggal szeretned tudni gyök2 értékét? \n");
    scanf("%lf",&pontossag);

    for (int i = 0; i < pontossag; i++)
    {   
        while (szam*szam < 2)
        {
           szam += tizedesjegy;
        }
        szam -= tizedesjegy;
        tizedesjegy = tizedesjegy/10;
    }

    printf("%f", szam);
    return 0;
}