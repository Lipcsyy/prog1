#include <stdio.h>

int main(void)
{
    int szalag[32768] = {0};
    int szalagPointer = 0;

    char programkod[30];
    int i = 0;
    scanf("%s", programkod);

    while (programkod[i] != 0)
    {
        switch (programkod[i])
        {
        case '>':
            szalagPointer++;
            break;
        case '<':
            szalagPointer--;
            break;
        case '+':
            szalag[szalagPointer]++;
            break;
        case '-':
            szalag[szalagPointer]--;
            break;
        case '.':
            printf("Mutatott bájt kiírása \n");
            break;
        case ',' :
            printf("Bemenet beolvasása");
            break;
        case '[':
            printf("Elöltesztelő ciklus kezdete");
            break;
        case ']':
            printf("Ciklus vége");
            break;
        default:
            break;
        }

        szalagPointer++;
    }
    


}