#include "utils.h"

void utils_printheader(char *message, char symbol){
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

void utils_printboard(GAME *games, char *cursor, char player){
    printf(BORDERLINE);
    for(int y = 0; y < 3; y++){
        char line[sizeof(GAMELINE)];
        for (int i = 0; i < sizeof(GAMELINE); i++){
            line[i] = GAMELINE[i];
        }
        
        for (int i = 0; i < 3; i++)
            line[i * 4 + 2] = cursor != &(games->board[y][i]) ? games->board[y][i] : '?';
        
        printf("%s", line);
        if(y != 2)
            printf(GAMEMIDDLE);
    }
    printf(BORDERLINE);
    char line[sizeof(MENU)];
    for (int i = 0; i < sizeof(MENU); i++){
        line[i] = MENU[i];
    }
    line[34] = player;
    printf("%s", line);
}