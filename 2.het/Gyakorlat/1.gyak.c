#include <stdio.h>
#include <stdbool.h> 

int harmadik(void){

    int szam = 1;

    for (int i = 1; i <= 8; i++)
    {
        szam *= i;
    }

    printf("%d\n", szam);
    

    return 0;
}

int harmadik_2(void){

    int szam = 1;
    int n = 1;

    while(n <= 8){
        szam *= n;
        n++;
    }

    printf("%d\n",szam);

    return 0;
}

int eukledeszi(int a, int b){

    int maradek = 1;

    while(maradek > 0){
        maradek = a%b;
        a = b;
        b = maradek;

        printf("a: %d \n", a);
        printf("b: %d \n", b);
        printf("maradek: %d \n",maradek);

    }

    printf("%d",a);
    return 0;
}

int karakterkodok(void){

    int szam = 1;
    char betu;

    betu = szam;

    printf("%c \n",betu);

    // while(scanf("%c", &betu) == 1){
    //     printf("betu = %c, betu = %d \n", betu, betu); // az end of file character a ctrl-d-vel tudom beadni neki
    // }

    
    return 0;
}

int legkisebb(void){

    int tomb [10] = {30,42,56,3,675,4,75,42,31,32};
    int i = 0;

    printf("\nLegkisebb kereses \n");

    int min = tomb[0];
    int minIndex = 0;

    for (int i = 0; i < sizeof tomb / sizeof tomb[0] - 1; i++)
    {
        if(min > tomb[i+1]){
            min = tomb[i+1];
            minIndex = i+1;
        }
    }

    printf("Lekisebb szam : %d \n", min);
    printf("Legkisebb indexe: %d \n", minIndex);
    
    while (true)
    {   
        if (i == minIndex)
        {
            printf("[MIN] %d ",tomb[i]);
        }
        else{
            printf("%d ",tomb[i]);
        }
        

        i++;
        
        if (i == 10)
        {
            break;
        }
        
    }
    

    return 0;
}

int pitagorasz(void){

    char tomb[10] = "PITAGORASZ";
    int leptetes = 1;


    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; i < 10; i++)
        {
            printf("%c", tomb[i+j]); // mindig leptetem az i-t, ezért nem az elsotol kezdi, hanem a másodiktol, majd a harmadiktol stb 

            if(i + j > 10){
                printf("%c", tomb[i+j - 10]); //viszont amikor az i = 1 a j = 10, akkor tulleptunk, ami azt jelenti hogy az elso betut a vegere kene rakni, azt ugy teszem meg, hogy csak kivonok belole tizet
            }
        }
    }

    


    

    return 0;
}

int main(void){
 

    return 0;
}