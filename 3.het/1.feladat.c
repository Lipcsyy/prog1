#include <stdio.h>
#include <stdbool.h>

#define MAX 999

int hónapNap(){

    int tömb[12] = {31,30,31,30,31,30,31,31,30,31,30,31}; 
    int szam;
    scanf("%d", &szam);

    return(tömb[szam-1]);

}

int hónap2()
{
    int év, hónap, nap;
    scanf("%d", &év);
    scanf("%d", &hónap);
    scanf("%d", &nap);
    int tömb[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 

    if((év % 4 == 0 && év % 100 != 0) || év % 400 == 0){

        tömb[1] = 29;
    }

    int összeg = 0;
    for (int i = 0; i < hónap -1; i++)
    {
       összeg += tömb[i];
    }

    összeg += nap;

    return összeg;

}

int statiszikaSzamokrol()
{
    int stat[10] = {0};

    int szam;

    while(scanf("%d", &szam) > 0)
    {
        if(szam < 11 && szam > 0)
        {
            stat[szam-1]++; 
        }
    } 

    for (int i = 0; i < 10; i++)
    {
        printf("%d db : %d \n", i+1 , stat[i]);
    }

    return 0;
}

int erasztoteneszSzitaja()
{
    int szam;
    scanf("%d", &szam);

    bool prim[MAX] = {false};

    for (int i = 2; i < MAX/2; i++)
    {
        if (prim[i] == false) // ki van húzva? -- nincs
        {
            for (int j = i*2; j < MAX; j += i) // mindig i-vesével növelem, pl 2-sével, vagy 3-sával
            {
                prim[j] = true;
            }
            
        }
    
    }
    
    for (int i = 0; i < MAX; i++)
    {
        if (prim[i] == false && i>1)
        {
            printf("%d \n",i);
        }
        
    }
    
    return 0;

}

int main(void) {


    erasztoteneszSzitaja();
   

    return 0;
}