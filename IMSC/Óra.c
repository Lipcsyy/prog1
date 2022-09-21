#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265359

int writeLine(double x1, double y1, double x2, double y2,int strokeWidth,char strokeColor[], FILE *fptr, char *filename){
    

    fopen(filename, "a");
    fprintf(fptr,"\t<line  x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke-width: %d; stroke: %s;\" />\n", x1, y1, x2, y2,strokeWidth,strokeColor);
    fclose(fptr);

    return 0;

}

int writeCircle(int kpX, int kpY ,int r, char strokeColor[] , char fillColor[],int strokeWidth, char *filename, FILE *fptr, char mode)
{
    fopen(filename, "a");
    fprintf(fptr,"\t<circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"%s\" stroke-width=\"%d\" fill=\"%s\" />", kpX, kpY, r, strokeColor,strokeWidth ,fillColor);
    fclose(fptr);

    return 0;
}

int writeText(double X, double Y, int number, FILE *fptr, char *filename){

    fopen(filename, "a");
    fprintf(fptr,"<text x=\"%f\" y=\"%f\" style = \" font :  16px sans-serif \">%d</text>", X, Y ,number);
    fprintf(fptr,"<text x=\"%d\" y=\"%d\" fill=\"grey\" style = \" font :  12px sans-serif\">claude </text>", 260, 200);
    fprintf(fptr,"<text x=\"%d\" y=\"%d\" fill=\"grey\" style = \" font :  12px sans-serif \">bernard </text>", 304, 200);
    fclose(fptr);

    return 0;
}


int writeRect(double X, double Y, double width, double height, FILE *fptr, char *filename)
{
    fopen(filename, "a");
    fprintf(fptr,"<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" style=\"stroke:gold; fill : white ; stroke-width:1\" />", X,Y, width, height);
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
    secDeg = (-90 + (((double)sec/60)*360))* (PI/180);
    double secX = cos(secDeg);
    double secY = sin(secDeg);

    //perc mutato

    double minuteDeg;
    minuteDeg = (((double)(minute*60+sec))/(60*60))*360;
    minuteDeg = (-90 + (minuteDeg)) * (PI/180);
    double minuteX = cos(minuteDeg);
    double minuteY = sin(minuteDeg);

    //óra mutato

    hour = hour % 12;
    double hourDeg;
    hourDeg = ( -90 + (((double)(hour*3600+minute*60+sec))/(12*60*60))*360) * (PI/180) ;
    double hourX = cos(hourDeg);
    double hourY = sin(hourDeg);

    //--------------------------File létrehozása és svg inicializalasa

    char *filename = "ora.svg"; // nev magadasa
    FILE *fptr = fopen(filename, "w"); // itt megkapjuk a pointer, es meg is nyitjuk a filet iras modban ("w")
    
    fprintf(fptr, "<svg style=\"background-color:white\" width=\"800\" height=\"800\"  version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n");
    fclose(fptr); // bezarjuk a filet, előkészítjuk a kovetkezo irasra

    const int kp = 300;

    //--------------------------Kör rajzolása

    writeCircle(kp,kp,200,"gold", "whitesmoke",3,filename, fptr,'h');

    //--------------------------Beosztas megrajzolasa

    double beosztasDeg;

    for (int i = 0; i < 60; i++)
    {
        beosztasDeg = i * 6 * (PI/180);
        double beosztasX = 200*cos(beosztasDeg);
        double beosztasY = 200*sin(beosztasDeg);

        if(i % 5 == 0)
        {
            writeLine(kp + beosztasX - (30*cos(beosztasDeg)), kp + beosztasY - (30*sin(beosztasDeg)), kp + beosztasX - 5*cos(beosztasDeg), kp + beosztasY - 5*sin(beosztasDeg), 4, "gold",fptr, filename); //perc
        }
        else
        {
            writeLine(kp + beosztasX - (8*cos(beosztasDeg)), kp + beosztasY - (8*sin(beosztasDeg)), kp + beosztasX - 5*cos(beosztasDeg), kp + beosztasY - 5*sin(beosztasDeg), 1 , "grey",fptr, filename); 
        } 
    }

    //--------------------------mp kör és beosztasanak megrajzolasa

    writeCircle(kp, kp+100 , 30 , "gold" ,"#CFD2CF",1 ,filename , fptr ,'s');
    
    double msBeosztasDeg;

    for (int i = 0; i < 60; i++)
    {
        msBeosztasDeg = i * 6 * (PI/180);
        double msBeosztasX = 30*cos(msBeosztasDeg);
        double msBeosztasY = 30*sin(msBeosztasDeg);

        if(i % 10 == 0)
        {
            writeLine(kp + msBeosztasX - (6*cos(msBeosztasDeg)), kp + 100 + msBeosztasY - (6*sin(msBeosztasDeg)), kp + msBeosztasX, kp + 100 +  msBeosztasY, 2, "gold" ,fptr, filename);
        }else
        {
            writeLine(kp + msBeosztasX - (2*cos(msBeosztasDeg)), kp + 100 + msBeosztasY - (2*sin(msBeosztasDeg)), kp + msBeosztasX, kp + 100 +  msBeosztasY,1 , "gold",fptr, filename);
        }


    }
    
    
    //--------------------------Óramutatók rajzolása


    writeLine(kp,kp, kp + 160*hourX, kp + 160*hourY, 3, "gold", fptr, filename); //óra
    writeLine(kp,kp, kp + 180*minuteX, kp + 180*minuteY,1, "gold", fptr, filename); //perc
    writeLine(kp,kp+100, kp + 30*secX, kp + 100 + 30*secY, 1, "gold",fptr,filename); //s

    //--------------------------Datum mutato elkeszitese

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    writeRect(kp + 90, kp-24, 40,34, fptr, filename);
    writeText(kp + 100, kp, tm.tm_mday, fptr, filename);

    //--------------------------SVG file befejezese 

    writeCircle(kp,kp,6,"gold","gold",1,filename,fptr,'h');
    writeCircle(kp,kp,2,"grey","grey",1,filename,fptr,'h');
    writeCircle(kp,kp+100,2,"gold","gold",1,filename,fptr,'h');

    fopen(filename, "a");
    fprintf(fptr,"</svg>");
    fclose(fptr);

    return 0;
}
