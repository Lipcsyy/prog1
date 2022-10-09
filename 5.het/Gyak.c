#include <stdio.h>
#include <ctype.h>

int nagybetu(){
    char betuBe, betuKi;

    while(scanf("%c", &betuBe) == 1)
    {
        if (betuBe >= 'a' && betuBe <= 'z')
        {
            //betuKi = betuBe - 'a' + 'A';
            betuKi = toupper(betuBe);
        }
        else
        {
            betuKi = betuBe;
        }
        printf("%c", betuKi);

    }

    return 0;
}

int atvaltas(){

    printf("Milyen számrendszerben fogsz adni számot? ");
    int szamrendszer;
    scanf("%d", &szamrendszer);
    printf("Írd be a szamot! \n");

    char szam;
    int eredmeny = 0;
    //7-'0' vagy tolower(cbe) - 'a' + 10

    scanf(" ");

    while(scanf("%c", &szam) == 1 && !isspace(szam))
    {
        int ertek;

        if(isdigit(szam))
        {   
            ertek = szam - '0';
        }
        if(isalpha(szam))
        {
            ertek = szam - 'a' + 10;
        }

        eredmeny = eredmeny * szamrendszer + ertek;

    }

    
    printf("Eredmeny %d", eredmeny);

    return 0;

}

int visszavaltas(){

    char jegyek[32] = {0};
    int szam;
    int szamrendszer;

    printf("Adj meg egy szamot! ");
    scanf("%d", &szam);


    printf("Hanyas szamrendszerben szeretned? ");
    scanf("%d", &szamrendszer);

    int i = 0;

    while (szam != 0)
    {
        jegyek[i] = szam % szamrendszer + '0';
        szam = szam / szamrendszer;
        i++;
    }

    for (int j = i -1; j >= 0; j--)
    {
        printf("%c \n", jegyek[j]);
    }

    return 0;

}

int mashogy(){
    int szam;
    int szamrendszer;

    printf("Adj meg egy szamot! ");
    scanf("%d", &szam);


    printf("Hanyas szamrendszerben szeretned? ");
    scanf("%d", &szamrendszer);

    int kitevo = 1;

    while(kitevo < szam)
    {
        kitevo *= szamrendszer; 
        kitevo /= szamrendszer; //egyel kisebb legyen mert tulmennenk
    }

    while (szam > 0)
    {
        printf("%d", szam/kitevo);
        szam %= kitevo;
        kitevo /= szamrendszer;
    }
    
}

int main(void){

    visszavaltas();

    return 0;
}
