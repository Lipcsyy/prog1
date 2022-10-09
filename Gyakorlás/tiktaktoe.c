#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

int main(void) {

    int table[3][3] = {0}; //creating the table

    int x_Index[5] = {10}; //itt tarolom x mezoinek indexet
    int o_Index[5] = {10}; //itt tarolom o mezoinek indexet
    int turnCountX = 0;
    int turnCountO = 0;


    char turn = 'x'; // x == 1 || o == 2

    while(true)
    {
        //eloszor lassuk a tablat

        printf("\n");
        int sor;
        int oszlop;

        for (int sor = 0; sor < 3; sor++)
        {
            for (int oszlop = 0; oszlop < 3; oszlop++)
            {
                printf("%d ", table[sor][oszlop]);
            }
            printf("\n");
        }
        
        printf("\nSor: ");
        scanf("%d", &sor);

        printf("Oszlop: ");
        scanf("%d", &oszlop);

        table[sor-1][oszlop-1] = turn == 'x' ? 1 : 2 ;

        //tároljuk el az indexeket

        if(turn == 'x'){
            x_Index[turnCountX] = 3*(sor-1) + oszlop;
            turnCountX++;
        }
        else
        {
            o_Index[turnCountO] = 3*(sor-1) + oszlop;
            turnCountO++;
        }

        turn = turn == 'x' ? 'o' : 'x';

    }


    return 0;
}

bool hasWon(int player_index[]) {
    
}