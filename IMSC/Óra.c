#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int writeLine(double x1, double y1, double x2, double y2, FILE *fptr, char *filename){
    
    fopen(filename, "a");
    fprintf(fptr,"\t<line  x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"black\" />\n", x1, y1, x2, y2);
    fclose(fptr);

    return 0;

}

int main (void) {

    int hour,minute,sec;

    scanf("%d", &hour);
    scanf("%d", &minute);
    scanf("%d", &sec);

    //másodperc mutato
    double secDeg;
    secDeg = (-90 + (((double)sec/60)*360))* (M_PI/180);

    printf("szög: %f\n",secDeg / (M_PI/180));

    double secX = cos(secDeg);
    double secY = sin(secDeg);

    //perc mutato
    double minuteDeg;
    minuteDeg = (((double)(minute*60+sec))/(60*60))*360;
    minuteDeg = ((minuteDeg) - 90) * (M_PI/180);

    double minuteX = cos(minuteDeg);
    double minuteY = sin(minuteDeg);

    printf("%f\n", secX);
    printf("%f\n", secY);

    //óra mutato

    hour = hour % 12;

    double hourDeg;
    hourDeg = ((((double)(hour*3600+minute*60+sec))/(12*60*60))*360-90) * (M_PI/180) ;

    double hourX = cos(hourDeg);
    double hourY = sin(hourDeg);

    //--------------------------File létrehozása és svg inicializalasa

    char *filename = "ora.svg"; // nev magadasa
    FILE *fptr = fopen(filename, "w"); // itt megkapjuk a pointer, es meg is nyitjuk a filet iras modban ("w")
    
    fprintf(fptr, "<svg style=\"background-color:green\" width=\"500\" height=\"500\"  version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n");
    fclose(fptr); // bezarjuk a filet, előkészítjuk a kovetkezo irasra

    //--------------------------Óramutatók rajzolása

    int kp = 100;

    writeLine(kp,kp, kp + 100*hourX, kp + 100*hourY, fptr, filename); //óra
    writeLine(kp,kp, kp + 200*minuteX, kp + 200*minuteY, fptr, filename); //perc
    writeLine(kp,kp, kp + 50*secX, kp + 50*secY, fptr,filename); //ms


    //--------------------------SVG file befejezese 

    fopen(filename, "a");
    fprintf(fptr,"</svg>");
    fclose(fptr);

    return 0;
}
