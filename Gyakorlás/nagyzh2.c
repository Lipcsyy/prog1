#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool kisbetus(char c)
{
    return c == 'a' || 'e' || 'i' || 'o' || 'u';
}

void viragnyelv(char *eredmeny, char *forras)
{

    int i = 0;
    int j = 0;

    while (forras[i] != '\0')
    {
        eredmeny[j] = forras[i];
        if(kisbetus(forras[i]))
        {
            eredmeny[++j] = 'v';
            eredmeny[++j] = forras[i];
        }
        i++;
        j++;
    }

    eredmeny[j] = '\0';
    
}

typedef struct idoPont{
    int ora;
    int perc;
    int masodperc;
} idoPont;

idoPont atvalt(char *szoveg){

    idoPont p;

    if (sscanf(szoveg, "%d:%d:%d", &p.ora, &p.perc, &p.masodperc) == 3)
    {
        return p;
    }

    if (sscanf(szoveg, "%dh %dm %ds", &p.ora, &p.perc, &p.masodperc) == 3)
    {
        return p;
    }

    char c;

    if (sscanf(szoveg, "%d:%d %cM", &p.ora, &p.perc, c) == 3)
    {   
        p.masodperc = 0;

        if (c == 'P')
        {
            p.ora += 12; 
        }
        

        return p;
    }
    
}

typedef struct vendeg{
    char nev[51]; //zaro nulla beleferjen
    int szobaszam;
} vendeg;

int emelet(vendeg v){
    int emelet = v.szobaszam/100;
}

vendeg *ven(char *nev, vendeg *tomb)
{
    for (int i = 0; i < 50; i++)
    {
        if (strcmp(nev, tomb[i].nev) == 0)
        {
            return &tomb[i];
        }
        
    }
    
    return NULL;
}

//scanf("%s %d", uj.nev, &uj.szobaszam);
//erdemes a legelso scanf-t a cikluson kivul megtenni ott while felteleben checkolni, utana majd whileon belul megegyszer scanfelni

int main(void){
    vendeg vendegek[50];
}   