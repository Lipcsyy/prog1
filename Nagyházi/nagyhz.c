#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "nagyhz.h"

//----------------------------------------------------------Elso inditas-------------------------------------------------------------

#define firstSzamla 200000

//------------------------------------------------------------Program----------------------------------------------------------------

int szamla = 0;
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
    time_t t = time(NULL);  //idő megadasa a fuggvenyeknek, mindig kell az aktualis futashoz
    int input; 
    
    //Szeretnénk megnézni, hogy valaha futott-e már a program, ha igen, akkor a számlán lévő összeg változott, ezt be szeretnénk olvasni az eltárolt "számla.txt" fileból

    if (fileExits("szamla.txt"))
    {
        FILE* fp = fopen("szamla.txt","r"); 
        int _szamla;
        fscanf(fp, "%d", &_szamla);
        fclose(fp);
        szamla = _szamla;
    }
    else
    {   
        szamlaWriter(firstSzamla);
        szamla = firstSzamla;
    }

    bevetel();
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

//----------------------------------------------------------Függvények-------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------


/// @brief Ez a függvény kezeli a kiadásokat, itt tudod megadni, milyen tételt és mennyiért vásároltál, illetve, hogy milyen kategóriába tartozik
/// @param t Ezt szükséges megadni a függvénynek, hogy tudhassa az aktuális időt, ami szerint válogatja szét külön fileokba a termékeket
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
        scanf("%s", kiadas.nev);
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
        canContinue = scanf(" %c", &input) == 1 && (input == 'i' || input == 'I');
        
    }
       
    int kiadasSum = 0;

    for (int i = 0; i < kiadasokCount; i++)
    {
        printf("Sikeres bevitel! A tetel:%s %d %s %02d %02d\n", kiadasok[i].nev, kiadasok[i].osszeg, tags[kiadasok[i].kategoria], kiadasok[i].datum.tm_year, kiadasok[i].datum.tm_mon + 1);
        kiadasSum += kiadasok[i].osszeg;
    }

    szamla -= kiadasSum; //a szamlabol kivonom az osszeget
    szamlaWriter(szamla); //eltarolom az uj egyenleget
}


/// @brief Bevétel megadása, ez a függvény fogja hozzáadni a pénzt a számládhoz.
void bevetel(){

    headerPrint("BEVETEL MEGADASA");

    int bev = 0;
    printf("Add meg, hogy mennyi penzt szeretnel feltolteni a szamlara!\n");
    scanf("%d", &bev);

    printf("\033[A\33[2K\033[A\33[2K");

    szamla += bev;
    szamlaWriter(szamla);
    printf("Az uj egyenleg: %d \n", szamla);

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


///@brief Ezzel függvénnyel tudjuk az egyes részek headerjét
///@param header Itt tudod megadni mi legyen a header-be írva
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


/// @brief Ez a fuggveny beleirja a szamlaba a megadott osszeget
/// @param osszeg Itt add meg, hogy mennyit szeretnel hozzadni a szamlahoz.
void szamlaWriter(int osszeg){
    FILE* fp;

    fp = fopen("szamla.txt","w");

    fprintf(fp,"%d", osszeg);

    fclose(fp);
}


/// @brief Ez a függvény leellenőrzi, hogy a megnyitni kívánt file létezik-e?
/// @param filename Paraméterként a megnyitni kívánt file nevét kell megadni
/// @return Visszadja, hogy létezik-e a file.
bool fileExits(char *filename)
{
    FILE* fp;
    fp = fopen(filename,"r");
    if (fp == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}
