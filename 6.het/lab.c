#include <stdio.h>

int fibonacci(int n)
{   
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2); 
}

void sztringet_kiir_2(char *szoveg) {
     if (szoveg[0] == '\0')
     {
        return;
     }
    putchar(szoveg[0]);
    sztringet_kiir_2(szoveg + 1); /* ! */
}

int tombeloreIterativ(int *tomb, int meret)
{
    for (int i = 0; i < meret; i++)
    {
        printf("%d ", tomb[i]);   
    }
    
    printf("\n");

    for (int i = meret-1; i >= 0; i--)
    {
        printf("%d ", tomb[i]);   
    }
    
}

void tombeloreRekurziv(int *tomb, int i)
{   
    if(i == 10)
    {
        return;
    }
    printf("%d ", tomb[0]);
    i++;
    tombeloreRekurziv(tomb + 1, i);
}

void tombhatraRekurziv(int *tomb, int i){ 

    if (i < 0)
    {
        return;
    }

    printf("%d ", tomb[i]);
    i--;
    tombhatraRekurziv(tomb , i); 
}

void szamrendszervalto(int szam, int szamrendszer)
{
    if(szam == 0)
    {
        return;
    }
    int temp = szam;
    szam = szam / szamrendszer;
    szamrendszervalto(szam, szamrendszer);
    printf("%c", temp % szamrendszer + '0');
}

void haromszamjegy(int szam)
{
    if(szam == 0)
        return;

    haromszamjegy(szam / 1000);
    printf("%d ", szam % 1000);
}

int main()
{
    printf("%d \n",fibonacci(5));
    sztringet_kiir_2("alma \n");
    
    int tomb[] = {0,1,2,3,4,5,6,7,8,9};

    tombeloreIterativ(tomb, 10);
    printf("\n");
    tombeloreRekurziv(tomb, 0);
    printf("\n");
    tombhatraRekurziv(tomb, 9);

    printf("\nSzamrendszervalto \n");

    szamrendszervalto(123,10);

    printf("\nHáromszámjegy \n");

    haromszamjegy(1234567);

    return 0;
}