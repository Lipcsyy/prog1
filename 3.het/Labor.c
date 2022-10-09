#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int tombokfrissito(void){

    typedef struct negativok{
        double szam;
        int index;
    } negativok;

    double szamok[10] = { 2.5, -69, 5.4, -8, -7.7, 6, 2.9, -10, -3, 9.8 };
    struct negativok negativSzamok[10] = {0,0}; 

    int count = 0;

    printf("Összesen 10 szám va\n");

    for (int i = 0; i < 10; i++)
    {
        printf("[%d]=%g ", i, szamok[i]);
        if(szamok[i] < 0)
        {
            negativSzamok[count].szam = szamok[i];
            negativSzamok[count].index = i;
            count++;
        }
    }

    printf("\nEbből %d negatív \n", count);

    for (int i = 0; i < count; i++)
    {
        printf("[%d]=%g ", negativSzamok[i].index, negativSzamok[i].szam);
    }
    

    
    printf("\n");


    return 0;
}

double kob(double szam);
double abszolut(double szam);

int fuggvenyek(void)
{
    for (double i = -1; i <= 1; i += 0.1)
    {
        printf("%.4f %.4f %.4f %.4f\n", i, kob(i), abszolut(i), sin(i) );
    }
    return 0;
}

double kob(double szam)
{
    return szam*szam*szam;
}

double abszolut(double szam)
{
    return szam < 0 ? -szam : szam;
}


//6. feladat

double hozzaAd(double a)
{
    return a = a+1;
}

double elojeletvalt(double a){
    return (-1)*a;
}

double szorozza_kettovel(double a){
    return a*2;
}

double visszaallit(void){
    return 1;
}

int menuvezerelt(void){

    double a = 1;
    int controll = 0;

    do
    {
        printf("Szam: %g \n", a);
        printf("0. Alapertek visszaallitasa (a = 1)\n"
        "1. Hozzaad 1-et\n"
        "2. Megforditja az elojelet\n"
        "3. Szorozza 2-vel\n"
        "9. Kilepes\n");
        
        scanf("%d", &controll);

        switch (controll)
        {
        case 0:
            a = visszaallit();
            break;
        case 1: 
            a = hozzaAd(a);
            break;
        case 2:
            a = elojeletvalt(a);
            break;
        case 3:
            a = szorozza_kettovel(a);
            break;
        default:
            break;
        }

    } while (controll != 9);
    

    return 0;
}

// 5. feladat

typedef struct Datum {
    int ev, ho, nap;
} Datum;
 
typedef struct Versenyzo {
    char nev[31];
    Datum szuletes;
    int helyezes;
} Versenyzo;
 
void datum_kiir(Datum d);
 
void versenyzo_kiir(Versenyzo v);

 
void datum_kiir(Datum d) {
    printf("%d %d %d \n" , d.ev, d.ho, d.nap);
}
 
void versenyzo_kiir(Versenyzo v) {
    printf("%s , %d %d %d %d \n", v.nev, v.szuletes.ev, v.szuletes.ho, v.szuletes.nap, v.helyezes );
}

int feladat_5(void){

    Versenyzo versenyzok[5] = {
    { "Am Erika", {1984, 5, 6}, 1 },
    { "Break Elek", {1982, 9, 30}, 3 },
    { "Dil Emma", {1988, 8, 25}, 2 },
    { "Kasza Blanka", {1979, 6, 10}, 5 },
    { "Reset Elek", {1992, 4, 5}, 4 },
};

    printf("%s\n", versenyzok[0].nev);
    printf("%d\n", versenyzok[2].helyezes);
    datum_kiir(versenyzok[4].szuletes);
    printf("%c\n", versenyzok[1].nev[0]);
    versenyzok[1].helyezes <= 3 ? printf("Igen\n") : printf("Nem\n");
    versenyzok[4].helyezes > versenyzok[3].helyezes ? printf("Gyorsabb\n") : printf("Nem gyorsabb\n");
    versenyzok[1].szuletes.ev == versenyzok[2].szuletes.ev ? printf("Ugyanabban az évben születtek\n") : printf("Nem ugyanabban az evben szulettek\n");
    versenyzo_kiir(versenyzok[1]);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", i+1);
        versenyzo_kiir(versenyzok[i]);
    }
    

    return 0;
}

//madarnyelv

bool maganhangzoe(char c){
    return (c == 'a' || c == 'e' || c == 'u' || c == 'o'); //amikor valami igaz else hamis van, akkor elég ezt csinálni
}

int csere(char c){

    if (maganhangzoe(c) || maganhangzoe(c+32)){ 

        if(c  < 'a') // nagybetus
        {
            printf("%cv%c", c, c+32);
        }
        else
        {
            printf("%cv%c", c, c);
        }
    }
    else{
        printf("%c", c);
    }
    
    return 0;
}

int kiiro(void)
{
    char szo[30];
    scanf("%s", szo);

    for (int i = 0; szo[i] != 0; i++) // a string vége mindig egy 0-ás
    {
        csere (szo[i]);
    }
    
    printf("\n");

    return 0;

}

int main(void){
   
    kiiro();

    return 0;
}