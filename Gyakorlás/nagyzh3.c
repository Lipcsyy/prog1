#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double emeletestort()
{
    double eredmeny = (4 + 2 - (3 - (6 + ((double)4 / (double)5)))) / (3 * ((2 - 7)));
    return eredmeny;
}

void bitkiiras()
{
    unsigned long int a = 145;

    int count = 0;

    for (int i = 0; i < 32; i++)
    {
        if(a % 2 == 1)
            printf("2^%d*1 ", count);
        
        count++;
        a = a >> 1;
    }
}

//printf-be kell u-t irni ha unsignedot szeretnenk

void bitkiirasmasik()
{
    unsigned  long int a = 145;

    unsigned long szamok[9] = { 0U, 1931988508U, 581177634U, 581374240U,581177632U, 581177634U, 1919159836U, 0U };

    int count = 0;

    for (int i = 0; i < 32; i++)
    {
        int szam = ((szamok[3] ^ 65535) >> (31-i)) % 2;
        szam == 1 ? printf("1") : printf("0");
        count++;
    }
}

void rajz()
{
    unsigned long int tabla[24] = {0};

    int x, y;

    while(scanf("%d %d", &x, &y) == 2)
    {
        for (int i = 0; i < 24; i++)
        {
            if(i == y)
            {
                tabla[y] += 1;
                tabla[y] = tabla[y] << (x);
            }  
        }
    }

    //kiiras
    for (int j = 0; j < 24; j++)
    {   
        for (int i = 0; i < 32; i++)
        {
            int szam = ((tabla[j]) >> (31-i)) % 2;
            szam == 1 ? printf("#") : printf("0");
        }
        printf("\n");
    }
 
}

int main(void)
{

    rajz();

    return 0;
}
