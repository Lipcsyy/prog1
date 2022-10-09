#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//legkevesebb fémdarabbal visszaadni

int bankautomata(void){
    int penzek[] = {5,10,20,50,100,200,500,1000,2000,5000,10000,20000};
    int osszeg;
    int count = 11;

    printf("Adj meg egy osszeget: ");
    scanf("%d", &osszeg);

    while (osszeg != 0)
    {
        if(osszeg - penzek[count] < 0 )
        {
            count--;
        }
        else
        {
            printf("%d ", penzek[count]);
            osszeg -= penzek[count];
        }
    }

    return 0;
}

int main(void)
{ 
    srand(time(NULL));
    int pixelek[800] = {0};
    int count[800] = {0};

    for (int i = 0; i < 800; i++)
    {
        int r = rand() %  832; 
        pixelek[i] = r;
    }

    for (int i = 0; i < 800; i++)
    {
        count[pixelek[i]]++; //megszamlalas
    }

    //atlag szamitas

    int osszeg = 0;
    
    for (int i = 0; i < 800; i++)
    {
        osszeg = osszeg + count[i];
    }
    
    double atlag = (double)osszeg / 800;
    
    for (int i = 0; i < 800; i++)
    {
        if(count[i] > atlag)
        {
            printf("%d pixel, %d felvillanas \n",i, count[i]);
        }
    }
    

    return 0;
}