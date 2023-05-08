#ifndef UNTITLED1_GAMEBOARD_H
#define UNTITLED1_GAMEBOARD_H

#include "list.h"

typedef struct Board{
    List columns[7];
    List foundations[4];
    Card deck[52];
}Board;

Board* createBoard(Card* deck);
void makeShowCaseMode(Board* board);
void makePlayMode(Board* board);

void moveColumnToFoundation(Board* board, int columnIndex, int foundationIndex);
void moveFoundationToColumn(Board* board, int foundationIndex, int columnIndex);
void moveColumnToColumn(Board* board, int fromColumnIndex, int toColumnIndex);

#endif //UNTITLED1_GAMEBOARD_H
