#include <stdio.h>

void kiadas(int *szamla){

    // for (int i = 0; i < 8; i++)
    // {
    //     printf("\033[A\33[2K");
    // }

    for (int i = 0; i < 30; i++)
    {
        printf("-");
    }
    printf("KIADAS");
    for (int i = 0; i < 30; i++)
    {
        printf("-");
    }
    printf("\n");

    printf("Szamlan levo osszeg: %d \n", *szamla);

}

void bevetel(){
    printf("Bevetel\n");
}

void kiadasList(){
    printf("KiadasList\n");
}

void kiadasEdit(){
    printf("KiadasEdit\n");
}

void statistics(){
    printf("Statistics\n");
}

void menuPrint(){
    printf("(1) - Uj kiadas bevitele\n");
    printf("(2) - Uj bevetel bevitele\n");
    printf("(3) - Kiadasok listazasa \n");
    printf("(4) - Kiadasok szerkesztese\n");
    printf("(5) - Statisztikak\n");
    printf("(6) - Kilepes\n");
}

int main(void)
{   

    int szamla = 200000;


    int input; //a menu inputja
    menuPrint();

    while (scanf("%d", &input) == 1 && input != 6)
    {
        switch (input)
        {
        case 1:
            kiadas(&szamla);
            break;
        case 2:
            bevetel();
            break;
        case 3:
            kiadasList();
            break;
        case 4:
            kiadasEdit();
            break;
        case 5:
            statistics();
            break;
        
        default:
            break;
        }

        menuPrint();
    }
    

    return 0;
}