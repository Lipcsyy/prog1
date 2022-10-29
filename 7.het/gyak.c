#include <stdio.h>

int jarda(int hossz)
{
    //leallas

    if (hossz == 1)
    {
        return 1;
    }
    if (hossz == 2)
    {
        return 2;
    }
    
    

    //ket lehetoseg van

    return jarda(hossz-1) + jarda(hossz-2);
}

void kiir(int *t,int hossz){
    for (int i = 0; i < hossz; i++)
    {
        printf("%d", t[i]);
    }
    printf("\n");
}   

void cserescucc(int *t, int a, int b){
    int temp = t[a];
    t[a] = t[b];
    t[b] = temp;
}

void piffpaff(int *t, int hossz, int start){

    //leallas

    if (start == hossz -1)
    {
        kiir(t, hossz);
    }

    else
    {
        piffpaff(t, hossz, start +1);
    
        for (int i = start + 1; i < hossz; i++)
        {
            cserescucc(t, start, i);
            piffpaff(t, hossz,start +1);
            cserescucc(t,i,start);
        }
    
    }
    

}

int main(void){

    return 0;
}