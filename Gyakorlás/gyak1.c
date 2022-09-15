#include <stdio.h>
#include <math.h>

int main(void){
    
    int a;
    int oszto = 2;

    scanf("%d", &a);

    while (a != 1)
    {
        if (a % oszto == 0)
        {
            a = a / oszto;
            printf("%d  %d\n",a, oszto);
        }
        else if (a % oszto != 0){
            oszto++;
        }
    }
    
    return 0;
}