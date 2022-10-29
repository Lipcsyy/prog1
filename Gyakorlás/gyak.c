#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

void szorzotabla_rajzol(void) {
    for (int y = 1; y <= 10; y += 1) {
        for (int x = 1; x <= 10; x += 1)
            printf("%5d", x*y);
        printf("\n");
    }
}
 
void sort(int *tomb, int meret){

    for (int i = 0; i < meret-1; i++)
    {
        for (int j = 0; j < meret-i-1; j++)
        {
            //csere

            if (tomb[i] > tomb[i+1])
            {
                int temp = tomb[i+1];
                tomb[i+1] = tomb[i];
                tomb[i] = temp;
            }

        }
        
    }
    

}

typedef enum{
    csokkeno,
    noveko,
    osszevissza
} rendezettseg;

rendezettseg sort2(double *t, int meret){

    rendezettseg r = t[0] < t[1] ? noveko : csokkeno;

    for (int i = 0; i < meret-1; i++)
    {
        if ((t[i] > t[i+1] && r == noveko) || (t[i] < t[i+1] && r == csokkeno))
        {
            return osszevissza;
        }
        
    }
    return r;
}


void forditva(int szam)
{
    //hossz
    int hossz = 0;
    int eredeti = szam;

    while (eredeti != 0)
    {
        hossz++;
        eredeti /= 10;
    }

    //csere

    int uj = 0;
    int i = 0;

    while (szam != 0)
    {
        int maradek = szam % 10;
        uj = uj + maradek*(pow(10, hossz-i));
        i++;
        szam /= 10;
    }
    
    printf("\n%d \n", uj);

}

void concat(char *forras, char *cel, int celhossz)
{
    //forras hossz

    int celmennyi = 0;

    while (forras[celmennyi] != '\0')
    {
        celmennyi++;
    }

    int j = 0;
    int mennyi = celhossz - celmennyi;

    for (int i = celmennyi; i < celhossz - 1 ; i++)
    {
        cel[i] = forras[j];
        j++;
    }
    
    cel[celhossz-1] = '\0';
    
    printf("\n%s\n", cel);

}

char *keres(char *forras, char *keres){
    return strstr(forras, keres);
}

void evszam(){

    int ev;
    int honap;
    int nap;
    char ap = ' ';

    char bemenet[20];

    scanf("%s", bemenet);

    if(sscanf(bemenet,"'%d.%d.%d",&ev, &honap,&nap ) == 3)
    {
        if (ev > 50)
        {
            ev += 1900;
        }

        printf("%d.%d.%d", ev,honap,nap);
        
    }

    if (sscanf(bemenet,"%2d.%2d.%4d",&nap, &honap,&ev ) == 3)
    {
        printf("%d.%d.%d", ev,honap,nap);
    }
    
   

}

typedef struct Könyv{
    char szerzo[31];
    char cim[51];
    int db;
    int ev;
    int id;
} Könyv;

typedef struct Szerzo {
    char nev[31];
    int count : 1;
} Szerzo;

bool kisbetus(char c)
{
    return c == 'a' || 'e' || 'i' || 'o' || 'u';
}

void virag(char *cel, char *forras) {
    int iforr = 0, icel = 0;
    while (forras[iforr] != '\0') {
        cel[icel++] = forras[iforr];
        if (kisbetus(forras[iforr])) {
            cel[icel++] = 'v';
            cel[icel++] = forras[iforr];
        }
        iforr++;
    }
    cel[icel] = '\0';
}

int main(void) {
    
    char forras[] = "faszom";
    char cel[10] = "kukika";

    concat(forras,cel,10);

    printf("%c \n", *keres("faszomgecifasz", "gec"));

    printf("\n%d\n", strcmp("fabz", "faaz"));

    evszam();



    char uj[50];
     
    virag(uj, "viragnyelven");
    printf("\n%s", uj);

    return 0;
}
