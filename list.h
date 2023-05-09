//
// Created by Felix Schmidt on 08/05/2023.
//

#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H

#include "card.h"

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
void addCardEnd(List* list,Card card);
void removeCard(List* list, Card card);
void removeCardAt(List* list, int index);
void addCardAt(List* list, int index, Card card);
int  getIndexOf(List* list, Card card);
int getIndexOfCard(List* list, char cardSuit, char cardValue);
Card getCardAt(List* list, int index);
Card popCardAt(List* list, int index);
void print_list(List* list);
int getListSize(List* list);
int isListEmpty(List* list);
int getCardHiddenStatusAt(List* list, int index);

#endif //UNTITLED1_LIST_H
