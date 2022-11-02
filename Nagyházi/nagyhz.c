#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "nagyhz.h"

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
    char nev[50];
    Kategoria kategoria;
    struct tm datum;

} Kiadas;

int main(void)
{
    time_t t = time(NULL); //idő
    int input; //a menu inputja

    szamlaWriter(szamla);

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

    Kiadas* kiadasok = (Kiadas*) malloc(1*sizeof(Kiadas)); //több tétel beviteléhez kell -- 1-nél valamiért rossz

    char input;
    bool canContinue = true;

    int kiadasokCount = 0;
    int kiadasokHossz = 1;

    while (canContinue)
    {
        Kiadas kiadas = {.datum = *localtime(&t)};
        kiadas.datum.tm_year += 1900;

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

        if(kiadasokCount >= kiadasokHossz)
        {   
            kiadasokHossz *= 2;    
            kiadasok = (Kiadas*) realloc(kiadasok, sizeof(Kiadas)*(kiadasokHossz));
            for (int i = 0; i < kiadasokCount; i++)
            {
                printf("Sikeres bevitel! A tetel: %s %d %s %02d %02d\n", kiadasok[i].nev, kiadasok[i].osszeg, tags[kiadasok[i].kategoria], kiadasok[i].datum.tm_year, kiadasok[i].datum.tm_mon + 1);
            }
        }

        kiadasok[kiadasokCount] = kiadas;
        
        printf("Szeretned folytatni? (I) Igen (N) Nem : ");

        kiadasokCount++;
        canContinue = scanf(" %c\n", &input) == 1 && tolower(input) == 'i';
        
    }
       

    for (int i = 0; i < kiadasokCount; i++)
    {
        printf("Sikeres bevitel! A tetel:%s %d %s %02d %02d\n", kiadasok[i].nev, kiadasok[i].osszeg, tags[kiadasok[i].kategoria], kiadasok[i].datum.tm_year, kiadasok[i].datum.tm_mon + 1);
    }
    
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


void szamlaWriter(int osszeg){
    FILE* fp;

    fp = fopen("szamla.txt","w");

    fprintf(fp,"%d", osszeg);
    fclose(fp);
}