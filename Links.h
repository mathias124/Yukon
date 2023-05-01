//
// Created by Abdis on 5/1/2023.
//

#ifndef UNTITLED1_LINKS_H
#define UNTITLED1_LINKS_H

#include "card.h"




typedef struct Link {
    Card start;
    Card end;
    int Coloumn;
} Link;
typedef struct LinkedLists {
    Link *list[11];
} LinkedLists;

int SuperInsert(Card* card1, Card* card2,LinkedLists*lists);

int InsertAllowd(Card *card,Card *card2);
int charConverter(char c);
int insert(Card *card, Link *link);
int RemoveLastCard(Link * link);
Card getCard(char suit, char value, LinkedLists* lists);









//
// Created by Abdis on 5/1/2023.
//


// mangler nogen ting.Pototype.

int insert(Card *card, Link *link) {
    // Check if the card is already in the list
    if (card->column>0) {
        return 1;
    }

    // Add the card to the end of the list
    if (link->start.next == &(link->end)) { // List is empty
        card->prev = &(link->start);
        card->next = &(link->end);
        link->start.next = card;
        link->end.prev = card;
    } else { // List is non-empty
        card->prev = link->end.prev;
        card->next = &(link->end);
        link->end.prev->next = card;
        link->end.prev = card;
    }

    card->column = link->Coloumn;

    return 0;
}


int charConverter(char c) {
    if (c == 'A') {
        return 1;
    } else if (c == '2') {
        return 2;
    } else if (c == '3') {
        return 3;
    } else if (c == '4') {
        return 4;
    } else if (c == '5') {
        return 5;
    } else if (c == '6') {
        return 6;
    } else if (c == '7') {
        return 7;
    } else if (c == '8') {
        return 8;
    } else if (c == '9') {
        return 9;
    } else if (c == 'T') {
        return 10;
    } else if (c == 'J') {
        return 11;
    } else if (c == 'Q') {
        return 12;
    } else if (c == 'K') {
        return 13;
    } else {
        return -1; // invalid input
    }
}

int InsertAllowd(Card *card, Card *card2) {
    if (card->cardSuit == card2->cardSuit || card->column==card2->column||card->trueValue >=card2->trueValue ) {
        return 1;
    } else {
        return 0;
    }
}
int remove_last_card( Link *link) {
    Card *cur = link->end.prev;
    Card *prev = link->end.prev->prev;

    // If the list is empty or only has Done card, return an error
    if (cur == &(link->start)) {
        return 1;
    }

    // Remove the last card from the list
    prev->next = &(link->end);
    link->end.prev = prev;
    cur->next = &(link->end);

    return 0;
}
int SuperInsert(Card* card1, Card* card2, LinkedLists* lists) {
    Card end = lists->list[card1->column]->end;
    if (InsertAllowd(card1, card2)) {
        return 0;
    }

    // remove cards from the old list

    Card pre=*card1->prev;
   card1->prev=&end;
    pre.next=&end;
    end.prev=&pre;



    // insert cards into the new list
    Card next= *card2->next;
    Card cardOne=*card1;
    Card cardtwo=*card2;
    card2->next = &cardOne;
    card1->prev= &cardtwo;
    card1->next = &next;
    next.prev = &cardOne;


    // update the column of the moved cards
    Card* curr = card1;
    while (curr != NULL) {
        curr->column = card2->column;
        curr = curr->next;
    }

    return 1;
}

Card getCard(char suit, char value, LinkedLists* lists) {
    for (int i = 0; i < 7; i++) {
        Link* link = lists->list[i];
        Card* current = &(link->start);
        while (current != NULL) {
            if (current->cardSuit == suit && current->cardValue == value) {
                return *current;
            }
            if (current == &(link->end)) {
                break;
            }
            current = current->next;
        }
    }
    return lists->list[0]->start;
}






Link c1 = {
        .start = {'m', 0,0, 0,0, &c1.end, NULL},
        .end = {'n', 0, 0,0,0, NULL, &c1.start},
        .Coloumn=1

};
Link c2 = {
        .start = {'m', 0, 0,0,0, &c2.end, NULL},
        .end = {'n', 0, 0,0,0, NULL, &c2.start},
        .Coloumn=0
};
Link c3 = {
        .start = {'m', 0, 0,0,0, &c3.end, NULL},
        .end = {'n', 0, 0,0,0, NULL, &c3.start},
        .Coloumn=1
};
Link c4 = {
        .start = {'m', 0, 0,0,0, &c4.end, NULL},
        .end = {'n', 0, 0,0,0, NULL, &c4.start},
        .Coloumn=2
};
Link c5 = {
        .start = {'m', 0, 0,0,0, &c5.end, NULL},
        .end = {'n', 0, 0,0,0, NULL, &c5.start},
        .Coloumn=3
};
Link c6 = {
        .start = {'m', 0, 0,0,0, &c6.end, NULL},
        .end = {'n', 0, 0,0,0, NULL, &c6.start},
        .Coloumn=5
};
Link c7 = {
        .start = {'m', 0, 0,0,0, &c7.end, NULL},
        .end = {'n', 0, 0,0,0, NULL, &c7.start},
        .Coloumn=6
};
Link a1 = {
        .start = {'m', 0, 0,0,0, &a1.end, NULL},
        .end = {'n', 0, 0,0,0, NULL, &a1.start},
        .Coloumn=7
};
Link a2 = {
        .start = {'m', 0, 0,0,0, &a2.end, NULL},
        .end = {'n', 0, 0,0,0, NULL, &a2.start},
        .Coloumn=8
};Link a3 = {
        .start = {'m', 0, 0,0,0, &a3.end, NULL},
        .end = {'n', 0, 0,0,0, NULL, &a3.start},
        .Coloumn=9
};Link a4 = {
        .start = {'m', 0, 0,0,0, &a4.end, NULL},
        .end = {'n', 0, 0,0,0, NULL, &a4.start},
        .Coloumn=10
};


#endif //UNTITLED1_LINK_H
