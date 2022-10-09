#include <stdio.h>

int negyesindex(int *tomb, int meret)
{
    printf("Pointer : %d \n", *tomb);

    for (int i = 0; i < 10; i++)
    {
        printf("%d \n", *tomb);
        tomb++;
    }

    tomb--;
    
    printf("Pointer : %d \n", *tomb);

    return 0;

}

int main(void)
{

    int tomb[10] = {0,1,2,3,4,5,6,7,8,10}; //a tomb nev mar magaban egy pointer a nulladik elemre mutat

    negyesindex(tomb, 10);

    return 0;
}