#include <stdio.h>
#include <string.h>

void elso(int a, int b, int *osszeg, int *szorzat)
{
    *osszeg = a + b;
    *szorzat = a*b;
}

void masodik(int *tomb, int meret ,int *paros, int *paratlan)
{
    int k = 0;
    int j = 0;

    for (int i = 0; i < meret; i++)
    {
        if(tomb[i] % 2 == 0)
        {
            paros[k] = tomb[i];
            k++;
        }
        else
        {
            paratlan[j] = tomb[i];
            j++;
        }
    }
    

}

void tombkiir(char *tomb, int db)
{
    for (int i = 0; i < db; i++)
    {
        printf("%c", tomb[i]);
    }
}

void megfordit(char *tomb, char *forditott){

    int meret = strlen(tomb);

    for (int i = 0; i < meret-1; i++)
    {
        forditott[i] = tomb[meret-1-i];
    }

    forditott[meret] = '\0';
    
    
}

void mashogy(char *tomb)
{
    int hossz = strlen(tomb);
    for (int i = 0; i < hossz/2; i++)
    {
        char temp = tomb[i];
        tomb[i] = tomb[hossz - 1 -i];
        tomb[hossz - 1 -i] = temp;
    }
    
}

void spacetelenit(char *szoveg)
{

    int i = 0;
    int hova = 0;

    while (szoveg[i] != '\0')
    {
        if (szoveg[i] != ' ')
        {
            szoveg[hova++] = szoveg[i];
        }
        i++;
        
    }

    
    szoveg[hova] = '\0';
    
}

int main(void){

    // int szorzat, osszeg;
    // elso(5,6, &osszeg, &szorzat);

    // int tomb[] = {0,1,2,3,4,5,6,7,8,9};
    // int paros[10];
    // int paratlan[10];
    // masodik(tomb, 10, paros, paratlan);

    char alap[] = "hello";
    char megforditTomb[10]; 

    megfordit(alap, megforditTomb);
    tombkiir(megforditTomb, 10);

    return 0;
}