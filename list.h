#include "card.h"

#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H

#endif //UNTITLED1_LIST_H
typedef struct Node {
    Card card;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    int size;
} List;
List* makeList();
void insertCard(List* list, Card card, int index);
void addCard(List* list,Card card);
void removeCard(List* list, Card card);
void removeCardAt(List* list, int index);
int  getIndexOf(List* list, Card card);
Card getCardAt(List* list, int index);
Card popCardAt(List* list, int index);

