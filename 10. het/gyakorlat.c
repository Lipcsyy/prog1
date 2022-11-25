#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Halmaz{
    int meret;
    double* elemek;
} Halmaz;

void* halmazBaRak(Halmaz* halmaz, double input){

    if (benneVan(halmaz, input))
    {
        printf("Mar benne van");
    }
    else
    {
        // double* ujElemek = realloc(ujElemek,halmaz->meret + 1);

        // int i =0;

        // for ( i; i < halmaz->meret; i++)
        // {
        //     ujElemek[i] = halmaz->elemek[i];
        // }

        // ujElemek[i] = input;

        // return halmazBaRak;

        halmaz->elemek = (double*) realloc(halmaz->elemek, (halmaz->meret + 1) * sizeof(double)); //itt is kell a kasztolas és itt is kell sizeof(double)
        halmaz->elemek[halmaz->meret] = input;
    }

}

bool benneVan(Halmaz* halmaz, double input)
{
    for (int i = 0; i < halmaz->meret; i++)
    {
        if (halmaz->elemek[i] == input) return true;
    }

    return false;
    
}

void kivesz(Halmaz* halmaz, double input){

    // double* uj = (double*) malloc(sizeof(double)*halmaz->meret-1);

    // int j = 0;;
    // for (int i = 0; i < halmaz->meret; i++)
    // {
    //     if (halmaz->elemek[i] != input)
    //     {
    //         uj[j] = halmaz->elemek[i];
    //         j++;         
    //     }
    // }
    // free(halmaz->elemek);
    // halmaz->elemek = uj;
    
    double temp = halmaz->elemek[halmaz->meret];

    halmaz->elemek = (double*) realloc(halmaz->elemek, sizeof(double) * (halmaz->meret-1));
    halmaz->meret--;

    for (int i = 0; i < halmaz->meret; i++)
    {
        if (halmaz->elemek[i] == input)
        {
            halmaz->elemek[i] = temp;
        }
    }
    

}

void halmazInit(Halmaz* halmaz) //itt a mainben levot valtoztatjuk meg
{
    halmaz->meret = 0;
    halmaz->elemek = NULL;
}

void halmazInit(Halmaz* halmaz){
    free(halmaz->elemek); //itt azt kell freelni amit lefoglaltunk
}


int main(void){
    
    //halmaz létrehoz
    Halmaz halmaz;
    halmazInit(&halmaz);


    return 0;
}