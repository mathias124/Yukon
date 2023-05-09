
#include "card.h"
#include "list.h"

#ifndef UNTITLED1_MOVEVALIDATION_H
#define UNTITLED1_MOVEVALIDATION_H

int getColumnVerification(char cardValue,char cardSuit, List* column);
int getColumnToColumnVerification(Card card, List* column);
int moveToFoundation(Card, List* foundation);

#endif //UNTITLED1_MOVEVALIDATION_H
