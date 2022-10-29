#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int *rendezett(int *tomb, int meret)
{

    bool asc = tomb[0] < tomb[1]; 
    bool rendezett = true;

    for (int i = 0; i < meret-1; i++)
    {
        if (asc && rendezett) // ascending eset
        {
            if (tomb[i] > tomb[i+1])
            {
                rendezett = false;
                return &tomb[i];
            }
            
        }
        else if(!asc && rendezett) // descending eset
        {
            if(tomb[i] < tomb[i+1])
            {   
                rendezett = false;
                return &tomb[i];
            }
        }
    }
    return NULL; 

}

int legkisebblegnagyobb(int *tomb, int meret, int *max, int *min)
{   

    // max = &tomb[0] ez azert nem mukodik mert a max egy int valtozo nem egy pointer, es mivel itt megkapom a max 
    // intre mutato pointert, ha ezt a pointert megvaltoztatom, attol meg abba a pointerbe ami a max intre mutat, nem irodik be az ertek
    //  

    //most megvan a max int valtozoba mutato pointer, es annak az erteket felul tudjuk irni, bele tudunk irni a pointerbe, amihez a valtozo tartozik

    *max = tomb[0]; 
    *min = tomb[0];


    for (int i = 0; i < meret-1; i++)
    {
        if (*max < tomb[i+1])
        {

            *max = tomb[i+1]; 

        }
        else if(tomb[i+1] < *min)
        {

            *min = tomb[i+1];

        }
    }
    
    printf("%p \n", max);

    return 0;

}

char *rendezettseg(char *novekvo, char *csokkeno, char *osszevissza, double *tomb, int meret)
{

    bool order = true;
    bool asc = true;

    for (int i = 0; i < meret-1; i++)
    {
        if(tomb[i] > tomb[i+1] && order)
        {
            asc = false;
        }
        else if(tomb[i] < tomb[i+1] && !asc)
        {
            order = false;
        }
    }

    if(!order)
    {
        return osszevissza;
    }
    else if(asc)
    { 
        return novekvo;
    }
    else
    {
        return csokkeno;
    }

    
}

int main(void){

    //rendezett
    //int tomb[10] = {1,0,2,3,4,6,5,7,8,9};
    // int *rossz = rendezett(tomb, 10);
    // printf("%p", rossz); // a 6os elem rontja el
    
    // double tomb[10] = {0,1,2,3,4,5, 6,16,19,20};
    // // int max = 0;
    // // int min = 0;
    // // legkisebblegnagyobb(tomb, 10, &max, &min);

    // char novekvo[] = "novekvo";
    // char csokkeno[] = "csokkeno";
    // char osszevissza[] = "osszevissza";

    // char *inOrder = rendezettseg(novekvo, csokkeno, osszevissza, tomb, 10);

    // printf("%s", inOrder);
     

    //string.h-ban
    char eredeti[] = "Gipsz Jakab fasz";
    char forditott[20];
    
    char vezeteknev[20], keresztnev[20], fasz[20];
    sscanf(eredeti, "%s %s %s", vezeteknev, keresztnev, fasz);
    sprintf(forditott, "%s %s", keresztnev, vezeteknev);

    char kuki[50];

    scanf("%s", kuki);
    printf("%s\n", kuki);

    printf("%s", forditott);


    return 0;
}