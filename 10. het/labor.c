#include <stdio.h>
#include <stdlib.h>
 
typedef struct BiFa {
    int ertek;
    struct BiFa *bal, *jobb;
} BiFa;
 
BiFa *beszur(BiFa *gyoker, int ertek) {
    if (gyoker == NULL) {
        BiFa *uj = (BiFa*) malloc(sizeof(BiFa));
        uj->ertek = ertek;
        uj->bal = uj->jobb = NULL;
        return uj;
    }
    if (ertek < gyoker->ertek) {        /* balra szur */
        gyoker->bal = beszur(gyoker->bal, ertek);
    }
    else if (ertek > gyoker->ertek) {   /* jobbra szur */
        gyoker->jobb = beszur(gyoker->jobb, ertek);
    }
    else {
        /* mar benne van */
    }
    return gyoker;
}
 
void faBejar(BiFa *gyoker)
{
    if (gyoker == NULL)
    {
        return;
    } 

    faBejar(gyoker->bal);
    printf("%d ", gyoker->ertek);
    faBejar(gyoker->jobb);
}

void faTorles(BiFa *gyoker)
{
    if (gyoker == NULL)
    {
        return;
    } 

    faBejar(gyoker->bal);
    free(gyoker);
    faBejar(gyoker->jobb);
}

int faOsszeg(BiFa *gyoker)
{
    if (gyoker == NULL)
    {
        return 0;
    } 

    return gyoker->ertek + faOsszeg(gyoker->bal) + faOsszeg(gyoker->jobb);

}

int faElemek(BiFa *gyoker)
{
    if  (gyoker == NULL) return 0;
    return faElemek(gyoker->bal) + faElemek(gyoker->jobb) + 1;
}

BiFa* faKeres(BiFa* gyoker, int elem){

    if (gyoker == NULL || gyoker ->ertek == elem)
        return gyoker ;

    if (gyoker ->ertek > elem)
        return faKeres(gyoker->bal, elem);
    else
        return faKeres(gyoker->jobb, elem);
       
}
 
void negalas(BiFa* gyoker){

     if (gyoker == NULL)
    {
        return;
    } 

    faBejar(gyoker->bal);
    gyoker->ertek = (-1)*gyoker->ertek;
    faBejar(gyoker->jobb);

}

void csere(BiFa* gyoker)
{
    if (gyoker == NULL) return;

    csere(gyoker->bal);
    csere(gyoker->jobb);
    BiFa* temp = gyoker->bal;
    gyoker->bal = gyoker->jobb;
    gyoker->jobb = temp;
}

int main(void) {
    int minta[] = {15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0};
    BiFa *gyoker = NULL;
    for (int i = 0; minta[i] > 0; i++)
        gyoker = beszur(gyoker, minta[i]);
 
    /* Ide tedd be a kipróbálandó függvények hívásait! */

    int a = faOsszeg(gyoker);
    faBejar(gyoker);
    printf("\n%d \n", a); 

    printf("%d \n", faElemek(gyoker));

    printf("Megvan %p \n", faKeres(gyoker,96 ));
    
 
    return 0;
}