#ifndef CARD_H
#define CARD_H
#include <stdlib.h>
typedef struct Card{
    char cardSuit;
    char cardValue;
    int Hidden;

}Card;

typedef struct {
    Card cards[52];
}Deck;

void shuffleCards(Card *cards, int noCards);

void setHidden(Card* card);

#endif

