#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct Kor {
    double x;
    double y;
    double r;
} Kor;

bool atfed(Kor k1, Kor k2){

    return sqrt(pow(k1.x - k2.x,2) + pow(k1.y - k2.y,2)) < k1.r + k2.r;

}

Kor beolvas(void){

    Kor k;

    scanf("%lf", &k.x);
    scanf("%lf", &k.y);
    scanf("%lf", &k.r);

    return k;
}

int main(void){

    Kor k1 = beolvas();
    Kor k2 = beolvas();

    printf(atfed(k1,k2) ? "True" : "False");

    return 0;
}