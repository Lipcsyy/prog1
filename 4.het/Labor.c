#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct Pont
{
    double x;
    double y;
} Pont;

//function declaratino

Pont beolvas();
double tav(Pont p1, Pont p2);
bool egyenlo(Pont p1, Pont p2);

//Main 

int main(void){

    Pont kezdo = beolvas();
    Pont p2 = beolvas();
    Pont pontok[2]; // a 0. elem mindig az elozo, az 1. elem mindig a kovetkezo

    double tavolsag = 0;

    pontok[0] = kezdo;
    pontok[1] = p2;

    while (egyenlo(kezdo, pontok[1]) != true)
    {
        tavolsag += tav(pontok[0], pontok[1]);
        pontok[0] = pontok[1];
        pontok[1] = beolvas();
    }

    tavolsag += tav(kezdo, pontok[0]);

    printf("%f", tavolsag);

    return 0;
}

double tav(Pont p1, Pont p2)
{
    double tav;

    tav = sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));

    return tav;
}

bool egyenlo(Pont p1, Pont p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

Pont beolvas()
{
    double x;
    double y;

    printf("Adj meg egy x koordinátát: ");
    scanf("%lf", &x);
    printf("Adj megy egy y koordinátát");
    scanf("%lf", &y);
    
    Pont pont = {x,y};

    return pont;
}