#include "game.h"


bool game_checkwin(GAME *g){
    
    for (stPath *pptr = paths; pptr->valid; pptr++)
    {
        int a = g->board[pptr->rowA][pptr->colA];
        int b = g->board[pptr->rowB][pptr->colB];
        int c = g->board[pptr->rowC][pptr->colC];
        
        if (a == b && b == c && a != '_')
            return true;
    }
    return false;
}

void game_init(GAME *g){
    for (int i = 0; i < 3; i++)
        memset(g->board[i], '_', sizeof(char) * 3);
        
    g->isover = false;
}

char* game_getnextvalue(GAME *g){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(g->board[i][j] == '_'){
                return &(g->board[i][j]);
            }
        }
    } 
    return NULL;
}

void game_move(GAME *g, char **cursor, char mov, char player){
    bool found = false;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (&g->board[i][j] == *cursor && !found){
                found = true;
                switch(mov){
                    case 'w':
                        if (!(i == 0))
                            if (g->board[i-1][j] == '_')
                                *cursor = &(g->board[i-1][j]);
                        break;
                    case 'a':
                        if (!(j == 0))
                            if (g->board[i][j-1] == '_')
                                *cursor = &(g->board[i][j-1]);
                        break;
                    case 's':
                        if (!(i == 2))
                            if (g->board[i+1][j] == '_')
                                *cursor = &(g->board[i+1][j]);
                            
                        break;
                    case 'd':
                        if (!(j == 2))
                            if (g->board[i][j+1] == '_')
                                *cursor = &(g->board[i][j+1]);
                        break;
                    case 'q':
                        g->board[i][j] = player;
                        *cursor = game_getnextvalue(g);
                        break;
                }   
            }
        }
    }
}