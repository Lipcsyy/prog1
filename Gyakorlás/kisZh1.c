#include <stdio.h>

int main (void) {

    int n;

    scanf("%d", &n);

    for (int sor = 1; sor <= n; sor++)
    {
        printf("|");

        for (int space = 1; space <= 2*(n-1); space++) //spacek
        {
            printf(" ");
        }

        printf("| \n");
        
    }

    for (int sor = 1; sor <= n; sor++)
    {
        for (int elsoSpace = 0; elsoSpace < sor-1; elsoSpace++)
        {
            printf(" ");
        }
        printf("\\");
        for (int masodikSpace = 2*(n-1) - (sor-1)*2; masodikSpace > 0; masodikSpace--)
        {
            printf(" ");
        }
        printf("/ \n");
        
    }
    
    

    return 0;
}