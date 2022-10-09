#include <stdio.h>

#define meret 32765


int main(void)
{
    char szalag[meret] = {0};
    int szalagPointer = 0;

    char programkod[]="[ThisprogramprintsSierpinskitriangleon80-columndisplay.]>++++[<++++++++>-]>++++++++[>++++<-]>>++>>>+>>>+<<<<<<<<<<[-[->+<]>[-<+>>>.<<]>>>[[->++++++++[>++++<-]>.<<[->+<]+>[->++++++++++<<+>]>.[-]>]]+<<<[-[->+<]+>[-<+>>>-[->+<]++>[-<->]<<<]<<<<]++++++++++.+++.[-]<]+++++*****Made*By:*NYYRIKKI*2002*****";
    //char programkod[] = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
    int i = 0; //léptető

    int depth = 0;

    //scanf("%s", programkod);

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
            printf("%c", szalag[szalagPointer]);
            break;
        case ',' :
            scanf("%c", &szalag[szalagPointer]);
            break;
        case '[':
            if(szalag[szalagPointer] == 0)
            {
                depth++;
                
                while (programkod[i] != ']' || depth != 0)
                {
                    i++;

                    if (programkod[i] == '[')
                    {
                        depth++;
                    }
                    else if (programkod[i] == ']')
                    {
                        depth--;
                    }
                }
            }
            break;
            
        case ']':
        
            if(szalag[szalagPointer] != 0)
            {
                depth++;
                while (programkod[i] != '[' || depth != 0) //akar csinaljuk meg megint amig el nem erunk a legelso '['-hez, mert lehet hogy tobb van
                {
                    i--;

                    if(programkod[i] == ']')
                    {
                        depth++;
                    }
                    else if(programkod[i] == '[')
                    {
                        depth--;
                    }
                }
            }
            break;

        default:
            break;
        }
        i++;
    }
    



}
