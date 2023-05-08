//
// Created by Felix Schmidt on 08/05/2023.
//

#include <stdlib.h>
#include <printf.h>
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
    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\t\tA\tF\n");
    printf("==========================\n");
    int maxRowCount = getMaxRowCount(board);
    for (int i = 0; i < maxRowCount; i++) {
        for (int j = 0; j < 7; j++) {
            if (i < getListSize(&(board->columns[j]))) {
                Card card = getCardAt(&(board->columns[j]), i);
                printf("%c%c\t ", card.cardValue, card.cardSuit);
            } else {
                printf("[]  ");
            }
        }

        if (i == 0) {
            printf("  [%c%c] ", isListEmpty(&(board->foundations[0].head)) ? ' ' : board->foundations[0].head->card.cardValue,
                                isListEmpty(&(board->foundations[0].head)) ? ' ' : board->foundations[0].head->card.cardSuit);
        }else if(i == 1){
            printf("  [%c%c] ", isListEmpty(&(board->foundations[1].head)) ? ' ' : board->foundations[1].head->card.cardValue,
                                isListEmpty(&(board->foundations[1].head)) ? ' ' : board->foundations[1].head->card.cardSuit);
        }else if(i == 2){
            printf("  [%c%c] ", isListEmpty(&(board->foundations[2].head)) ? ' ' : board->foundations[2].head->card.cardValue,
                                isListEmpty(&(board->foundations[2].head)) ? ' ' : board->foundations[2].head->card.cardSuit);
        }else if(i == 3){
            printf("  [%c%c] ", isListEmpty(&(board->foundations[3].head)) ? ' ' : board->foundations[3].head->card.cardValue,
                                isListEmpty(&(board->foundations[3].head)) ? ' ' : board->foundations[3].head->card.cardSuit);
        }
        printf("\n");
    }
}
void printShowcaseF(Board* board) {
    printf("   C1  C2  C3  C4  C5  C6  C7   A       F\n");
    printf("===========================================\n");

    // get the maximum row count across all columns
    int maxRowCount = getMaxRowCount(board);

    // print each row
    for (int i = 0; i < maxRowCount; i++) {
        printf("%c  ", 'A' + i);

        // print each column for the current row
        for (int j = 0; j < 7; j++) {
            List *column = &(board->columns[j]);
            int columnSize = getListSize(column);

            // print the card value and suit if it exists in the current column and row
            if (columnSize > i) {
                Card card = getCardAt(column, i);
                printf("%c%c ", card.cardValue, card.cardSuit);
            } else {
                printf("   ");
            }
        }

        // print the foundations for the current row
        if (i == 0) {
            printf("  [%c1] ", isListEmpty(&(board->foundations[0])) ? ' ' : 'A');
        }else if(i == 1){
            printf("  [%c2] ", isListEmpty(&(board->foundations[1])) ? ' ' : 'B');
        }else if(i == 2){
            printf("  [%c2] ", isListEmpty(&(board->foundations[1])) ? ' ' : 'B');
        }else if(i == 3){
            printf("  [%c3] ", isListEmpty(&(board->foundations[2])) ? ' ' : 'C');
        }
        printf("\n");
    }
}