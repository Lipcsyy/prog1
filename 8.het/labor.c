#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* masolat(char* bemenet){
    char* kimenet = (char*) malloc(sizeof(char)* (strlen(bemenet)+1));
    strcpy(kimenet, bemenet);
    return kimenet;
}

char* hozzafuz(char* x, char* y){
    char* kimenet = (char*) malloc(sizeof(char)* (strlen(x) + strlen(y) + 1 ));
    kimenet = masolat(x);
    strcat(kimenet,y);
    return kimenet;
}

char* kivag(char* bemenet, int kezdo, int vegso)
{   
    int length = strlen(bemenet); //hossz

    //feltetelek
    if (kezdo < 0) kezdo = 0;
    if (vegso > strlen(bemenet)) vegso = length;

    int between = vegso-kezdo; //megnezem mekkora helyet kell mallocolnom
    
    char* kimenet = (char*) malloc(sizeof(char)*(between + 1));

    int index = 0;

    for (int i = kezdo; i < vegso; i++, index++)
    {
        kimenet[index] = bemenet[i];
    }

    kimenet[index] = '\0';

    return kimenet;
}

char* kivagforditva(char* bemenet, int kezdo, int vegso)
{   
    int length = strlen(bemenet); //hossz

    //feltetelek
    if (kezdo < 0) kezdo = 0;
    if (vegso > strlen(bemenet)) vegso = length;

    int between = vegso-kezdo; //megnezem mekkora helyet kell mallocolnom
    
    char* kimenet = (char*) malloc(sizeof(char)*(strlen(bemenet) - between + 1));

    int beIndex = 0;
    int kiIndex = 0;

    while (bemenet[beIndex] != 0)
    {
        if (beIndex < kezdo || beIndex > vegso)
        {
            kimenet[kiIndex] = bemenet[beIndex];
            kiIndex++;
        }
        beIndex++;
    }
    

    kimenet[kiIndex] = '\0';

    return kimenet;
}

char* beszur(char* bemenet, int hova, char* mit){
    int hossz = strlen(bemenet) + strlen(mit) + 1;
    char* kimenet = (char*) malloc(sizeof(char)*hossz);

    strncpy(kimenet, bemenet, hova);
    strcat(kimenet, mit);
    strcat(kimenet, bemenet+hova);
    
    return kimenet;
}

int main(void)
{

    char* ptr = masolat("szia");

    printf("%s\n", ptr);

    ptr = hozzafuz(ptr, " ocsemn");
    printf("%s\n", ptr);
    free(ptr);

    char* kivagptr = kivag("sziahelomizu", 0,8);
    printf("%s\n", kivagptr);
    free(kivagptr);

    char* kivagmasptr = kivagforditva("sziahelomizu", 3,6); 
    printf("%s\n", kivagmasptr);
    free(kivagmasptr);

    char* beszurptr = beszur("hello!", 5, ", vilag");
    printf("%s\n", beszurptr);

    return 0;
}