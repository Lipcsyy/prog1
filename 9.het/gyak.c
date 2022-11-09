#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

char* mindentegybeve(char* bemenet){

    int length =  strlen(bemenet);

    int spaceCount = 0;

    for (int i = 0; i < length; i++)
    {
        if (isspace(bemenet[i])) spaceCount++;
    }

    char* p = (char*) malloc(sizeof(char)*length-spaceCount+1);
    
    if (p == NULL) return NULL;

    int j = 0;

    for (int i = 0 ; i < length; i++)
    {
        if (!isspace(bemenet[i]))
        {   
            p[j++] = bemenet[i];
        }    
    }

    return p;

}

bool atlagnalkisebb(double *t, int meret, double **ujtomb, int* ujmeret){


    double atlag = 0;
    for (int i = 0; i < meret; i++)
    {
        atlag += t[i];
    }
    atlag = atlag / meret;

    int atlagAlatti = 0;

    for (int i = 0; i < meret; i++)
    {
        if (t[i] < atlag)
        {
            atlagAlatti++;
        }
    }

    *ujtomb = (double*) malloc(sizeof(double)*atlagAlatti);
    
    int j = 0;

    for (int i = 0; i < atlagAlatti; i++)
    {
        if (t[i] < atlag)
        {
            *ujtomb[j] = t[i];
        }
    }

    *ujmeret = j;

}

int main(void)
{
    char* p = mindentegybeve("szia helo mizu");

    printf("%s\n",p);

    free(p);

    double t[8] = {1,2,3,4,5,6,7,8};

    double* ujtomb; //erre szeretnenk ramutatni majd amikor meghivjuk
    int ujmeret;

    //atlagnalkisebb(t,8,&ujtomb,&ujmeret); //kell a cimmegadas, mert a pointerre mutatot pointert keri a fuggveny parameterlistaja
}