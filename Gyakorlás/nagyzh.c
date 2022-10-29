#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool kismaganhangzo(char betu){
    return betu == 'a' || 'e' || 'i' || 'o' || 'o';
}

void viragnyelv(char *uj, char *szoveg){

    int i = 0;
    int j = 0;
    
    while (szoveg[i] != '\0')
    {   
        if(kismaganhangzo(szoveg[i]))
        {
            uj[j] = szoveg[i];
            uj[++j] = 'v';
            uj[++j] = szoveg[i];
        }
        else
        {
            uj[j] = szoveg[i];
        }

        i++;
        j++;
    }

    uj[j] = '\0';
    
}   

int main(void){

    char uj[50] = {0};
    
    viragnyelv(uj, "viragnyelven");

    printf("%s", uj);

    return 0;   
}