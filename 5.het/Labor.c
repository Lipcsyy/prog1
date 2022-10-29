#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int elso(void){
    double d = 3.14;
    double *p2, *p1;

    p1 = &d; //p1 pointernek megadom a d doublnek a memoriacimet

    printf("%p A pointerbol \n", p1);
    printf("%p Nem a pointerbol", &d);
    return 0;
}

int masodik(void){
   
    double i1  = 2;
    double *p1, *p2;

    p1 = &i1; //itt a memoriacimet adom meg neki, ez jelen esetben 2 lesz

    printf("%f \n", *p1);

    *p1 = 10;

    printf("%f \n", *p1);

    i1 = 20;

    printf("%f\n", *p1);

    p2 = p1;

    printf("%f", *p2);

    return 0;
}

int harmadik(double *oldal, double *terfogat, double *felulet){

    *terfogat = pow(*oldal,3);
    *felulet = pow(*oldal, 2)* 6;
    
    return 0;
    
}

int otos(void){

    char nev[50];
    int i = 0;

    scanf("%s", nev);

    // itt belerakom a lezarokaraktert, mert ezzel tudom hogy vege van

    i = 0;

    while(nev[i] != 0)
    {
        printf("%c \n", nev[i]);
        i++;
    }


    return 0;
}

int keres(int *tomb,int meret, int keres)
{

    int i = 0;

    while(i < 10)
    {
        if (tomb[i] == keres)
        {
            return i;
        }
        i++;
    }

    return -1;
}

int trimmer(char mondat[50])
{
    int i = 0;
    int j = 0;

    char szokoznelkul[50];


    while(mondat[i] != 0)
    {
        if(mondat[i] !=  ' '){
            szokoznelkul[j] = mondat[i];
            j++;
        }
        i++;
    }

    szokoznelkul[j] = '\0';

    printf("%s \n", szokoznelkul);
    
    return 0;

}

int main(void){

    double oldal = 2;
    double terfogat;
    double felulet;

    //harmadik(&oldal, &terfogat, &felulet);


    // int tomb[] = {0,1,2,3,4,5,6,7,8,9};

    // printf("%d \n", keres(tomb, 10,3)); // eleg a tomb nem kell a nulladik elem, mert a tomb egy pointer ami a nulladik elemre mutat

    // trimmer("Szia Uram! Hogy s mint?");

    otos();

    return 0;
}