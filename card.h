#ifndef CARD_H
#define CARD_H
#include <stdlib.h>
typedef struct Card{
    char cardSuit;
    char cardValue;
    char cardLocation;
    char cardColumn;

}Card;

typedef struct {
    Card cards[52];
}Deck;
// CARD DECK  FOR NOW
struct Card cards[52];
struct Card foundation [3];
struct Card blackCards[26];
struct Card redCards[26];
// CARD TYPES
char tempCardSuit;
char tempCardValue;

int noBlackCards = 0;
int noRedCards = 0;
int noCards=0;

void shuffleCards(Card *cards, int noCards);

Deck makeDeck();


#endif

