#include "gameboard.h"
#include "list.h"



Board* createBoard(Card* deck) {
    Board* board = malloc(sizeof (Board));
    // size of column, foundation and deck is already allocated
    for (int i = 0; i < 7; i++) {
        board->columns[i] = *makeList();
    }
    for (int i = 0; i < 4; ++i) {
        board->foundations[i] = *makeList();
    }
    for (int i = 0; i < 52; ++i) {
        board->deck[i] = deck[i];
    }
    return board;
}
void makeShowCaseMode(Board* board) {
    // Implementation of makeShowCaseMode function
    for (int i = 0; i < 52; i++){
        addCard(&board->columns[i % 7],board->deck[i]);
    }
}

void makePlayMode(Board* board) {
    // Implementation of makePlayMode function
}

void moveColumnToFoundation(Board* board, int columnIndex, int foundationIndex) {
    // Implementation of moveColumnToFoundation function
    Card card = popCardAt(&board->columns[columnIndex],columnIndex);
    addCard(&board->foundations[foundationIndex], card);

}

void moveFoundationToColumn(Board* board, int foundationIndex, int columnIndex) {
    // Implementation of moveFoundationToColumn function
}

void moveColumnToColumn(Board* board, int fromColumnIndex, int toColumnIndex) {
    // Implementation of moveColumnToColumn function
}
