#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListaElem{
    int ertek;
    struct ListaElem* next;
} ListaElem;

void listaElemOsszeFuz(ListaElem** eleje, int _ertek)
{
    ListaElem* uj = (ListaElem*) malloc(sizeof(ListaElem));

    uj->ertek = _ertek;
    uj->next = NULL;
    
    if(*eleje == NULL)
    {
        *eleje = uj;
    }
    else
    {
        ListaElem* head = *eleje;

        while(head->next != NULL)
        {
            head = head->next;
        }

        head->next = uj;
    }

}

void listaElemKiir(ListaElem* eleje)
{
    ListaElem* head = eleje;

    while (head != NULL)
    {
        printf("%d\n", head->ertek);
        head = head->next;
    }
}

void listaMax(ListaElem* eleje, int* max, int* index, int* hossz)
{
    ListaElem* head = eleje;

    *max = 0;
    *index = 0;

    int _index = 0;


    while (head != NULL && _index <= *hossz)
    {
        if (head->ertek > *max)
        {
            *max = head->ertek;
            *index = _index;
        }

        head = head->next;

        _index++;
    }
}

bool isInOrder(ListaElem* eleje){

    ListaElem* head = eleje;

    while (head->next != NULL)
    {
        ListaElem* next = head->next;

        if (head->ertek > next->ertek) return false;
        head = head->next;
    }
    
    return true;
}

void listaMegforditIndexig(ListaElem** eleje, int kulsoindex, int hossz)
{
    ListaElem* head = *eleje;
    ListaElem* temp = NULL;

    int _index = 0;

    if(kulsoindex == 6)
    {   
        ListaElem* lemarado = NULL;

        while (head->next != NULL)
        {
            temp = head->next;
            head->next = lemarado;
            lemarado = head;
            head = temp;
            _index++;
        }

        head->next = lemarado;
        *eleje = head; 
    }
    else
    {   
        ListaElem* lemarado = *eleje;
        ListaElem* tempEleje = lemarado;

        head = head->next;

        while (head->next != NULL && _index != kulsoindex)
        {
            temp = head->next;
            head->next = lemarado;
            lemarado = head;
            head = temp;
            _index++;
        }

        tempEleje->next = head;
        *eleje = lemarado;
    }
}

void listaFree(ListaElem* eleje){
    ListaElem* head = eleje;

    while (head != NULL)
    {   
        ListaElem* temp = head->next;
        free(head);
        head = temp;
    }
}

int main(void)
{

    ListaElem* eleje = NULL;

    listaElemOsszeFuz(&eleje, 3);
    listaElemOsszeFuz(&eleje, 1);
    listaElemOsszeFuz(&eleje, 2);
    listaElemOsszeFuz(&eleje, 4);
    listaElemOsszeFuz(&eleje, 6);
    listaElemOsszeFuz(&eleje, 7);
    listaElemOsszeFuz(&eleje, 5);

    listaElemKiir(eleje);

    int index = 0;
    int max = 0;
    int hossz = 6;


    while (!isInOrder(eleje))
    {   

        listaMax(eleje, &max, &index, &hossz);

        if(hossz != index)
        {
            listaMegforditIndexig(&eleje, index, hossz);
            listaMegforditIndexig(&eleje, hossz, hossz);
        }

        hossz--;
    }
    printf("Rendezett\n");

    listaElemKiir(eleje);

    listaFree(eleje);

    return 0;
}