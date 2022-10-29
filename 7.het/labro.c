#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void szamokvisszafele()
{
    int n;
    printf("Hány számot olvassunk be?\n");

    scanf("%d", &n);

    double *tomb;
    tomb = (double*) malloc(n * sizeof(double));

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &tomb[i]);
    }

    for (int i = n-1; i >= 0; i--)
    {
        printf("%g \n", tomb[i]);
    }

    free(tomb);
    
    
}

typedef struct DinTomb{
    double *adat;
    int meret;
} DinTomb;

void dtfoglal(DinTomb *dt, int meret) // a structot pointerkent tudjuk csak atadni ezert kell ez a mutogatos tema
{
    dt->meret = meret;
    dt->adat = (double*) malloc(meret * sizeof(double));
}

void dtatmeretez(DinTomb *dt, int ujmeret)
{

    double *ujadat = (double*) malloc(ujmeret * sizeof(double)); // itt egy teljesen uj memoriateruletre mutatok, ahova atmasolom majd a dolgokat

    int min = ujmeret < (dt->meret) ? ujmeret : (dt->meret); // megnezem meddig kell atmasolnom

    for (int i = 0; i < min; i++)
    {
        ujadat[i] = dt->adat[i]; //atmasolas
    }

    free(dt->adat); // a regi memoriateruletet felszabaditom az mar nem kell

    dt->adat = ujadat; //elmentem a structba a pointert és méretet
    dt->meret = ujmeret;
}

void kiirat(DinTomb *dt){
    for (int i = 0; i < dt->meret; i++)
    {
        printf("%lf \n", dt->adat[i]);
    }
}

void szamokvisszafelemaskeppen()
{
    DinTomb dt;
    dtfoglal(&dt, 5);

    int i = 0;
    int a;
    scanf("%d", &a);

    while (a != -1)
    {
        dt.adat[i] = a;
        i++;
        scanf("%d", &a);

        if (i == dt.meret && a != -1)
        {
            dtatmeretez(&dt, dt.meret + 5);
        }
    }


    printf("Kiiras\n");

    kiirat(&dt);
    
}

typedef struct charDinTomb{
    char *adat;
    int meret;
} charDinTomb;

void hosszusor(){

    charDinTomb dt;
    dtfoglal(&dt, 1);

    int i = 0;
    char a;
    scanf("%c", a);

    while (a != '\n')
    {
        dt.adat[i] = a;
        i++;
        scanf("%c", a);

        if (i == dt.meret)
        {
            dtatmeretez(&dt, dt.meret + 1);
        }
    }

    dt.adat[i] = '\0';

    printf("Kiiras\n");

    kiirat(&dt);
}


int main(void)
{   
    hosszusor();
}