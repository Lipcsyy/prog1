#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//--------------------------------------------------------Kiirató függvények---------------------------------------------------------

void menuPrint();
void headerPrint(char* header);

//--------------------------------------------------------Rendes függvények----------------------------------------------------------

void kiadas(time_t t);
void bevetel();
void kiadasList();
void kiadasEdit();
void statistics();

//------------------------------------------------------------Program----------------------------------------------------------------

int szamla = 200000;
char* tags[] = {"vendeglatas","szepsegapolas","ruhazat", "szorakozas", "bevasarlas", "egyeb" };

typedef enum Kategoria
{
    vendeglatas,
    szepsegapolas,
    ruhazat,
    szorakozas,
    bevasarlas,
    egyeb

} Kategoria;

typedef struct Kiadas
{
    int osszeg;
    char nev[51];
    Kategoria kategoria;
    struct tm datum;

} Kiadas;

int main(void)
{
    time_t t = time(NULL); //idő
    int input; //a menu inputja

    kiadas(t);

    // menuPrint();

    // while (scanf("%d", &input) == 1 && input != 6)
    // {
    //     switch (input)
    //     {
    //     case 1:
    //         kiadas(&szamla);
    //         break;
    //     case 2:
    //         bevetel();
    //         break;
    //     case 3:
    //         kiadasList();
    //         break;
    //     case 4:
    //         kiadasEdit();
    //         break;
    //     case 5:
    //         statistics();
    //         break;

    //     default:
    //         break;
    //     }

    //     menuPrint();
    // }

    return 0;
}


void kiadas(time_t t)
{

    headerPrint("KIADAS BEVITELE");

    //mivan ha tobb kiadast szeretnek bevinni, ahhoz dinamikus listát kell használjak
    Kiadas* tetelek = (Kiadas*) malloc(1*sizeof(Kiadas)); //több tétel beviteléhez kell

    char moreAdd;
    int index = 0;

    do
    {   
    
        Kiadas kiadas = {.datum = *localtime(&t)}; //struct létrehozása

        if(index >= 1)
        {
            tetelek = (Kiadas*) realloc(tetelek, index+1);
        }

        printf("Add meg a tetel nevet!\n");
        scanf("%s", &kiadas.nev);

        printf("\033[A\33[2K\033[A\33[2K");

        printf("Add meg a tetel arat!\n");
        scanf("%d", &kiadas.osszeg);

        printf("\033[A\33[2K\033[A\33[2K");

        printf("Add meg a kategoriajat!\n");

        while (scanf("%d", &kiadas.kategoria) == 1 && (kiadas.kategoria > 6 || kiadas.kategoria < 0 ))
        {
            printf("Add meg a kategoriajat!\n");
            printf("\033[A\33[2K\033[A\33[2K");
        }   

        printf("\033[A\33[2K\033[A\33[2K");

        printf("Sikeres bevitel! A tetel:%s %d %s %02d %02d\n", kiadas.nev, kiadas.osszeg, tags[kiadas.kategoria], kiadas.datum.tm_year + 1900, kiadas.datum.tm_mon + 1);
        
        printf("Szeretned folytatni? (I) Igen (N) Nem : ");
        index++;
    }
    while (scanf(" %c", &moreAdd) == 1 && moreAdd != 'N');

    
}

void bevetel(){
    printf("Bevetel\n");
}

void kiadasList(){
    printf("KiadasList\n");
}

void kiadasEdit(){
    printf("KiadasEdit\n");
}

void statistics(){
    printf("Statistics\n");
}


void menuPrint(){
    printf("Szamlan levo osszeg: %d HUF \n", szamla);

    printf("(1) - Uj kiadas bevitele\n");
    printf("(2) - Uj bevetel bevitele\n");
    printf("(3) - Kiadasok listazasa \n");
    printf("(4) - Kiadasok szerkesztese\n");
    printf("(5) - Statisztikak\n");
    printf("(6) - Kilepes\n");
}

void headerPrint(char* header)
{


    for (int i = 0; i < 30; i++)
    {
        printf("-");
    }

    printf("%s", header);

    for (int i = 0; i < 30; i++)
    {
        printf("-");
    }

    printf("\n\n");

    // for (int i = 0; i < 8; i++)
    // {
    //     printf("\033[A\33[2K");
    // }
}