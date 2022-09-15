#include <stdio.h>

int main(void) {
    int magas;
    printf("Add meg a haromszog magassagat \n");
    scanf("%d", &magas);
    
    for (int i = 0; i < magas; i++)
    {
        
        //space - kiírunk a magassagnal 1-el kevesebb spacet
        for (int j = 0; j < magas-i+1; j++)
        {
            printf(" ");
        }

        //karika - kiírunk a sor-szor ketto plusz egy karikat
        for (int karika = 0; karika < 1+(2*i); karika++)
        {
            printf("0");
        }

        printf("\n");
    }
    

    return 0;
}

