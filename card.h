#ifndef CARD_H
// Prevent multiple inclusion of header file
#define CARD_H
// Standard library header for memory allocation and deallocation
#include <stdlib.h>
// Structs to represent a card and a deck of 52 cards
typedef struct Card{
    char cardSuit;
    char cardValue;
    int trueValue;
    int column;
    int Hidden;
    struct Card * next;
    struct Card * prev;

}Card;

typedef struct {
    Card cards[52];
}Deck;

// Function declarations
void shuffleCards(Card *cards, int noCards);

Deck makeDeck();

// End conditional compilation
#endif

