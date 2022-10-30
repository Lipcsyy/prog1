#include <stdio.h>
#include <stdlib.h>

void save (int index, char** out_valueptr){

    int c = getchar();

    if (c == '\n' || c == EOF)
    {
       (*out_valueptr) = (char*) malloc((index + 1) * sizeof(char)); 
       (*out_valueptr)[index] = '\0';
    }
    else
    {
        save(index + 1, out_valueptr);
        (*out_valueptr)[index] = (char)c;
    }

}

int main(void){

    char* value;

    save(0, &value);
    
    printf("%s\n", value);

    free(value);

    return 0;
}