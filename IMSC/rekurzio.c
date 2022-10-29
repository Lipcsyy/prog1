#include <stdio.h>

//mi kene? 
//rekurzivan megcsinalni azt, hogy mindig beolvasok egy karaktert, ameddig nem erem az end of file karaktert vagy egy enter
//es returnnolni a legvegen hogy hany karatkert olvastam be

int karakterek(char *c, int index)
{
    int count = 0;

    if (c[index] == '\n'  || c[index] == EOF)
    {
        return 1;
    }

    return karakterek(c, index + 1);
    
}

int main(void) {

    char bemenet[] = "fasz";

    int a = karakterek(bemenet, 0);

    printf("%d", a);

    return 0;
}