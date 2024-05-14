#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int valid;
    int rowA, colA;
    int rowB, colB;
    int rowC, colC;
}
    stPath;

static stPath paths[] =
{
    { true,   0, 0,   0, 1,   0, 2 },   // top row
    { true,   1, 0,   1, 1,   1, 2 },   // middle row
    { true,   2, 0,   2, 1,   2, 2 },   // bottom row
    
    { true,   0, 0,   1, 0,   2, 0 },   // left column
    { true,   0, 1,   1, 1,   2, 1 },   // middle column
    { true,   0, 2,   1, 2,   2, 2 },   // right column
    
    { true,   0, 0,   1, 1,   2, 2 },   // TL to BR diagonal
    { true,   0, 2,   1, 1,   2, 0 },   // TR to BL diagonal
    
    { false,  0, 0,   0, 0,   0, 0 }    // end of list
};

typedef struct {
    char board[3][3];
    bool isover;
    bool choose;
} GAME;

bool game_checkwin(GAME *g);
void game_init(GAME *g);
char* game_getnextvalue(GAME *g);
void game_move(GAME *g, char **cursor, char mov, char player);