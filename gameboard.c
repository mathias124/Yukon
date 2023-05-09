#include <stdlib.h>
#include <stdio.h>
#include "gameboard.h"
#include "list.h"



Board* createBoard(List* deck) {
    Board* board = malloc(sizeof (Board));
    // size of column, foundation and deck is already allocated
    for (int i = 0; i < 7; i++) {
        board->columns[i] = *makeList();
    }
    for (int i = 0; i < 4; ++i) {
        board->foundations[i] = *makeList();
    }
    for (int i = 0; i < 52; ++i) {
        Card cardToBe = getCardAt(deck,i);
        board->deck[i] = cardToBe;

    }
    return board;
}

void makeShowCaseMode(Board* board) {
    for (int i = 0; i < 52; i++){
        addCardEnd(&board->columns[i % 7],board->deck[i]);
    }
}


void makePlayMode(Board* board) {
    board->deck[6].Hidden=1;
    board->deck[12].Hidden=1;
    board->deck[13].Hidden=1;
    board->deck[19].Hidden=1;
    board->deck[20].Hidden=1;
    board->deck[21].Hidden=1;
    board->deck[27].Hidden=1;
    board->deck[28].Hidden=1;
    board->deck[29].Hidden=1;
    board->deck[30].Hidden=1;
    board->deck[36].Hidden=1;
    board->deck[37].Hidden=1;
    board->deck[38].Hidden=1;
    board->deck[39].Hidden=1;
    board->deck[40].Hidden=1;
    board->deck[46].Hidden=1;
    board->deck[47].Hidden=1;
    board->deck[48].Hidden=1;
    board->deck[49].Hidden=1;
    board->deck[50].Hidden=1;
    board->deck[51].Hidden=1;


    // Deal 1 card in first column
    addCard(&(board->columns[0]), board->deck[0]);

    // Deal 6 cards in second column
    for (int i = 1; i <= 6; i++) {
        addCard(&(board->columns[1]), board->deck[i]);
    }

    // Deal 7 cards in third column
    for (int i = 7; i <= 13; i++) {
        addCard(&(board->columns[2]), board->deck[i]);

    }

    // Deal 8 cards in fourth column
    for (int i = 14; i <= 21; i++) {
        addCard(&(board->columns[3]), board->deck[i]);
    }

    // Deal 9 cards in fifth column
    for (int i = 22; i <= 30; i++) {
        addCard(&(board->columns[4]), board->deck[i]);

    }

    // Deal 10 cards in sixth column
    for (int i = 31; i <= 40; i++) {
        addCard(&(board->columns[5]), board->deck[i]);

    }

    // Deal 11 cards in seventh column
    for (int i = 41; i <= 51; i++) {
        addCard(&(board->columns[6]), board->deck[i]);
    }
}


void moveColumnToFoundation(Board* board, int columnIndex, int foundationIndex) {
    if(board->columns[columnIndex].size > 0 && board->foundations[foundationIndex].size < 13){
    Card card = popCardAt(&board->columns[columnIndex],board->columns[columnIndex].size-1);
    addCard(&board->foundations[foundationIndex], card);
    }
}

void moveFoundationToColumn(Board* board, int foundationIndex, int columnIndex) {
    if (board->foundations[foundationIndex].size > 0) {
        Card card = popCardAt(&board->foundations[foundationIndex], 0);
        addCardEnd(&board->columns[columnIndex], card);
    }
}
void moveColumnToColumn(Board* board, int fromColumnIndex, int toColumnIndex) {
    if (board->columns[fromColumnIndex].size > 0) {
        Card card = popCardAt(&board->columns[fromColumnIndex], board->columns[fromColumnIndex].size-1);
        addCardEnd(&board->columns[toColumnIndex], card);
    }
}
void moveCardsFromColumnToColumn(Board* board, int fromColumnIndex, int fromCardIndex, int toColumnIndex) {
    while (board->columns[fromColumnIndex].size > fromCardIndex) {
        Card card = popCardAt(&board->columns[fromColumnIndex], fromCardIndex);
        addCardEnd(&board->columns[toColumnIndex], card);
    }
}
int getMaxRowCount(Board* board) {
    int maxRowCount = 0;
    for (int i = 0; i < 7; i++) {
        int rowCount = board->columns[i].size;
        if (rowCount > maxRowCount) {
            maxRowCount = rowCount;
        }
    }
    return maxRowCount;
}
void printShowCase(Board* board) {
    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\t\t\n");
    printf("===================================\n");
    int maxRowCount = getMaxRowCount(board);
    for (int i = 0; i < maxRowCount; i++) {
        for (int j = 0; j < 7; j++) {
            if (i < getListSize(&(board->columns[j]))) {
                Card card = getCardAt(&(board->columns[j]), i);
                if(card.Hidden==0){
                    printf("%c%c\t", card.cardValue, card.cardSuit);
                }
                else
                    printf("[]\t");
            } else {
                printf("  \t");
            }
        }
//
        if (i == 0) {
            printf("  [%c%c] F1 ", isListEmpty(&(board->foundations[0].head)) ? ' ' : board->foundations[0].head->card.cardValue,
                                isListEmpty(&(board->foundations[0].head)) ? ' ' : board->foundations[0].head->card.cardSuit);
        }else if(i == 1){
            printf("  [%c%c] F2", isListEmpty(&(board->foundations[1].head)) ? ' ' : board->foundations[1].head->card.cardValue,
                                isListEmpty(&(board->foundations[1].head)) ? ' ' : board->foundations[1].head->card.cardSuit);
        }else if(i == 2){
            printf("  [%c%c] F3", isListEmpty(&(board->foundations[2].head)) ? ' ' : board->foundations[2].head->card.cardValue,
                                isListEmpty(&(board->foundations[2].head)) ? ' ' : board->foundations[2].head->card.cardSuit);
        }else if(i == 3){
            printf("  [%c%c] F4 ", isListEmpty(&(board->foundations[3].head)) ? ' ' : board->foundations[3].head->card.cardValue,
                                isListEmpty(&(board->foundations[3].head)) ? ' ' : board->foundations[3].head->card.cardSuit);

        }
    //
        printf("\n");
    }
}

void printTUI(){
    printf("%s%s\n", "LAST Command:",commandBuff);
    printf("%s\n", "INPUT > ");
}
