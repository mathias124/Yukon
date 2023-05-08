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
void printBoard(Board* board) {
    printf("Deck:\n");
    for (int i = 0; i < 52; i++) {
        printf("%c%C ", board->deck[i].cardValue, board->deck[i].cardSuit);
    }
    printf("\n\nColumns:\n");
    for (int i = 0; i < 7; i++) {
        printf("Column %d: ", i+1);
        Node* current = board->columns[i].head;
        while (current != NULL) {
            printf("%c%C ", current->card.cardValue, current->card.cardSuit);
            current = current->next;
        }
        printf("\n");
    }
    printf("\nFoundations:\n");
    for (int i = 0; i < 4; i++) {
        printf("Foundation %d: ", i+1);
        Node* current = board->foundations[i].head;
        while (current != NULL) {
            printf("%c%C ", current->card.cardValue, current->card.cardSuit);
            current = current->next;
        }
        printf("\n");
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
    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\t\tA\tF\n");
    printf("==========================\n");
    int maxRowCount = getMaxRowCount(board);
    for (int i = 0; i < maxRowCount; i++) {
        for (int j = 0; j < 7; j++) {
            if (i < getListSize(&(board->columns[j]))) {
                Card card = getCardAt(&(board->columns[j]), i);
                printf("%c%c\t ", card.cardValue, card.cardSuit);
            } else {
                printf("   ");
            }
        }
        printf(" ");
        if (i < getListSize(&(board->foundations[0]))) {
            for (int j = 0; j < 4; j++) {
                Card card = getCardAt(&(board->foundations[j]), i);
                printf("[%c%d] ", 'A' + j, card.cardValue - 1);
            }
        }
        printf("\n");
    }
}