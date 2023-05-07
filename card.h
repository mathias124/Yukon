#ifndef CARD_H
#define CARD_H
#include <stdlib.h>
#include "stdbool.h"
typedef struct Card{
    char cardSuit;
    char cardValue;
    bool isVisible;

}Card;

char* cardToString(Card card);
Card* makeDeck();

#endif

