#include <stdlib.h>
#include <stdio.h> 

typedef struct ListaElem {
    int adat;
    struct ListaElem *kov;
} ListaElem;
 
 
/* létrehoz egy listát, benne egy csomó számmal, a végéről építjük fel a listát */
ListaElem *lista_letrehoz(void) {
    int szamok[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2,
                     15, 9, 10, 6, 22, 4, 7, 18, 27, -1 };
    ListaElem *lis = NULL;
 
    for (int i = 0; szamok[i] != -1; ++i) {
        ListaElem *u;
        u = (ListaElem*) malloc(sizeof(ListaElem));
        u->kov = lis;
        u->adat = szamok[i];
        lis = u;
    }
    return lis;
}
 
void kiirat(ListaElem * eleje){
    ListaElem* mozgo = eleje;

    while(mozgo != NULL){
        printf("%d ", mozgo->adat);
        mozgo = mozgo->kov;
    }

}

int hossz (ListaElem * eleje)
{   

    ListaElem* mozgo = eleje;

    int length = 0;

    while (mozgo->kov != NULL)
    {
        mozgo = mozgo->kov;
        length++;
    }

    return length + 1;

}   

void listaFelszabadit(ListaElem * eleje){

    ListaElem* mozgo = eleje;
    ListaElem* temp;

    while (mozgo != NULL )
    {
        temp = mozgo;
        mozgo = mozgo->kov;
        free(temp);
    }
}

void beszurEleje(ListaElem** eleje, int szam){
    ListaElem* uj = (ListaElem*) malloc(sizeof(ListaElem*));

    uj->adat = szam;
    uj->kov = eleje;
    *eleje = uj;
}

void beszurVege(ListaElem* eleje, int szam)
{

    ListaElem* uj = (ListaElem*) malloc(sizeof(ListaElem*));

    uj->adat = szam;
    uj->kov = NULL;
    printf("\nBAJ\n");

    ListaElem* mozgo = eleje;

    while(mozgo->kov != NULL){
        mozgo = mozgo->kov;  
    }

    mozgo->kov = uj;
}

ListaElem* kereses (ListaElem* eleje, int szam){

    ListaElem* mozgo = eleje;

    while (mozgo != NULL) { 
        if (mozgo->adat == szam) return mozgo;
        mozgo = mozgo->kov;
    }
    
    return NULL;

}

int main(void) {
    ListaElem *eleje;
    
    eleje = lista_letrehoz();
    
    int _hossz = hossz(eleje);
    ListaElem* p = kereses(eleje,13);
    
    printf("A lista hossza %d\n", _hossz);

    printf("Benne van %d \n",p->adat);

    beszurVege(eleje,30);

    kiirat(eleje);

    return 0;   
}