#include <stdio.h>
#include <string.h>
#include "game.h"

#define BORDERLINE "-------------------------------------\n"
#define GAMELINE "- _ | _ | _ -\n"
#define GAMEMIDDLE "- --|---|-- -\n"
#define MENU "|   W                |  JOGADOR     |\n| A|S|D - Movimento  | Q - Confirma |\n-------------------------------------\n"
#define HEADERSIZE 37

void utils_printboard(GAME *games, char *cursor, char player);
void utils_printheader(char *message, char symbol);