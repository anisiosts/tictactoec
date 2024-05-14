#include <stdio.h>
#include <stdlib.h>
#include "lib/utils.h"

#define PLAYER1 'X'
#define PLAYER2 'O'
#define clear() printf("\033[H\033[J")


int main(int argc, char *argv[]){

    // Inicializando jogos
    GAME game;
    game_init(&game);

    // Inicializando variaveis para jogo

    char player = PLAYER1;
    char *cursor = &game.board[0][0];
    char input = 0;
    char *msg = "Welcome to T(ic|ac|oe)";
    char symbol = '#';
    while(!game.isover){
        //clear();
        if (input){
            if (input == 'w' || input == 'a' || input == 's' || input == 'd' || input == 'q')
                game_move(&game, &cursor, input, player); 
        }
        
        if(input == 'q'){
            if (game_checkwin(&game) || !game_getnextvalue(&game)){
                game.isover = true;
                msg = "GAME OVER";
                symbol = '*';
            }
            player = player == PLAYER1 ? PLAYER2 : PLAYER1;
        }
        input = 0;
        utils_printheader(msg, symbol);
        utils_printboard(&game, cursor, player);
        printf(">>> ");
        scanf("%c", &input);
        printf("\n");
        
    }

    return 0;
}