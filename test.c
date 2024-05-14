#include <stdio.h>
#include <string.h>

#define HEADERSIZE 37

void printHeader(char message[], char symbol){
    int place;
    place = (HEADERSIZE - strlen(message) - 2) / 2;

    char fullstring[HEADERSIZE];
    memset(fullstring, symbol, sizeof(char) * HEADERSIZE);

    fullstring[place] = ' ';

    for(int i = 0; i < strlen(message); i++)
        fullstring[place+i+1] = message[i];

    fullstring[place+strlen(message)+1] = ' ';

    printf("%s\n", fullstring);
}

int main(int argc, char *argv[]){
    char teste2 = "qeqw";
    char teste[] = "#####"teste2"asdas";
    printf("%s",teste);
    printHeader("asds", '!');
    printHeader("Este e um header legal", '#');
    printHeader("Escolha o seu movimento", '#');
    return 0;
}