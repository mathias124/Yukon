//
// Created by Abdis on 4/28/2023.
//

#ifndef UNTITLED1_LINKEDLIST_H
#define UNTITLED1_LINKEDLIST_H
#include "card.h"
#include <stdio.h>
#include <stdbool.h>
typedef struct Node {
    char name;
    struct node* next;
}Node;

void insert(Node** node,int val);



void remove(Node** node, int val);



#endif //UNTITLED1_LINKEDLIST_H
