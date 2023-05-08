#include "list.h"
#include "gameboard.h"
#include "card.h"


int main2(){
    Card* deck = makeDeck();
    Board* board = createBoard(deck);
    makeShowCaseMode(board);
    return 0;
}
