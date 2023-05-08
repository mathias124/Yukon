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

int SuperInsert(Card** card1, Card** card2,LinkedLists*lists);


int charConverter(char c);
int insert(Card *card, Link *link);
int RemoveLastCard(Link * link);
Card *getCard(char suit, char value, LinkedLists* lists);
Card getLastCard(Link link1);









//
// Created by Abdis on 5/1/2023.
//


// mangler nogen ting.Pototype.

int insert(Card *card, Link *link) {


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




int remove_last_card( Link *link) {
    Card *cur = link->end.prev;
    Card *prev45 = link->end.prev->prev;



    // Remove the last card from the list
    prev45->next = &(link->end);
    link->end.prev = prev45;
    cur->next = &(link->end);

    return 0;
}
void removeHidden( LinkedLists* lists){
    Card *hid1 = lists->list[0]->end.prev;
    Card *hid2 =lists->list[1]->end.prev;
    Card *hid3 =lists->list[2]->end.prev;
    Card *hid4 = lists->list[3]->end.prev;
    Card *hid5 = lists->list[4]->end.prev;
    Card *hid6 =  lists->list[5]->end.prev;
    Card *hid7 =  lists->list[6]->end.prev;

    if(hid1->Hidden==1)
        hid1->Hidden=0;
    if(hid2->Hidden==1)
        hid2->Hidden=0;
    if(hid3->Hidden==1)
        hid3->Hidden=0;
    if(hid4->Hidden==1)
        hid4->Hidden=0;
    if(hid5->Hidden==1)
        hid5->Hidden=0;
    if(hid6->Hidden==1)
        hid6->Hidden=0;
    if(hid7->Hidden==1)
        hid7->Hidden=0;

}
/*void automaticAdditionToFoundation( LinkedLists* lists){
    Card *hid1 = lists->list[0]->end.prev;
    Card *hid2 =lists->list[1]->end.prev;
    Card *hid3 =lists->list[2]->end.prev;
    Card *hid4 = lists->list[3]->end.prev;
    Card *hid5 = lists->list[4]->end.prev;
    Card *hid6 =  lists->list[5]->end.prev;
    Card *hid7 =  lists->list[6]->end.prev;

    if(hid1->Hidden==1)
        hid1->Hidden=0;
    if(hid2->Hidden==1)
        hid2->Hidden=0;
    if(hid3->Hidden==1)
        hid3->Hidden=0;
    if(hid4->Hidden==1)
        hid4->Hidden=0;
    if(hid5->Hidden==1)
        hid5->Hidden=0;
    if(hid6->Hidden==1)
        hid6->Hidden=0;
    if(hid7->Hidden==1)
        hid7->Hidden=0;

}*/
int SuperInsert(Card** card1, Card** card2, LinkedLists* lists) {
    Card * card10 =*card1;
    Card * card20 =*card2;
    Card * pre =card10->prev;
    Card * ne=card20->next;
    Card * L=lists->list[card10->column]->end.prev;



// remove cards from the old list
   pre->next= &lists->list[card10->column]->end;
    lists->list[card10->column]->end.prev=card10->prev->next;
    lists->list[card10->column]->end.prev=pre;



// insert cards into the new list

 card10->prev=card20;
 card20->next=card10;
    ne->prev=L;
    L->next=ne;



 //update the column of the moved cards
Card* curr = card10;
while (curr->cardSuit!='n') {
curr->column = card20->column;
curr = curr->next;
}



return 1;

}

Card * getCard(char suit, char value, LinkedLists* lists) {
    for (int i = 0; i < 7; i++) {
        Link* link = lists->list[i];
        Card* current = &(link->start);
        while (current != NULL) {
            if (current->cardSuit == suit && current->cardValue == value) {
                return current;
            }
            if (current == &(link->end)) {
                break;
            }
            current = current->next;
        }
    }
    return NULL;
}






Link c1 = {
        .start = {'m', 0,0, 0,0, &c1.end, NULL},
        .end = {'n', 0, 0,0,0, NULL, &c1.start},
        .Coloumn=1

};
Link c2 = {
        .start = {'m', 0, 0,1,0, &c2.end, NULL},
        .end = {'n', 0, 0,1,0, NULL, &c2.start},
        .Coloumn=0
};
Link c3 = {
        .start = {'m', 0, 0,2,0, &c3.end, NULL},
        .end = {'n', 0, 0,2,0, NULL, &c3.start},
        .Coloumn=1
};
Link c4 = {
        .start = {'m', 0, 0,3,0, &c4.end, NULL},
        .end = {'n', 0, 0,3,0, NULL, &c4.start},
        .Coloumn=2
};
Link c5 = {
        .start = {'m', 0, 0,4,0, &c5.end, NULL},
        .end = {'n', 0, 0,4,0, NULL, &c5.start},
        .Coloumn=3
};
Link c6 = {
        .start = {'m', 0, 0,5,0, &c6.end, NULL},
        .end = {'n', 0, 0,5,0, NULL, &c6.start},
        .Coloumn=5
};
Link c7 = {
        .start = {'m', 0, 0,6,0, &c7.end, NULL},
        .end = {'n', 0, 0,6,0, NULL, &c7.start},
        .Coloumn=6
};
Link a1 = {
        .start = {'m', 0, 0,7,0, &a1.end, NULL},
        .end = {'n', 0, 0,7,0, NULL, &a1.start},
        .Coloumn=7
};
Link a2 = {
        .start = {'m', 0, 0,8,0, &a2.end, NULL},
        .end = {'n', 0, 0,8,0, NULL, &a2.start},
        .Coloumn=8
};Link a3 = {
        .start = {'m', 0, 0,9,0, &a3.end, NULL},
        .end = {'n', 0, 0,9,0, NULL, &a3.start},
        .Coloumn=9
};Link a4 = {
        .start = {'m', 0, 0,10,0, &a4.end, NULL},
        .end = {'n', 0, 0,10,0, NULL, &a4.start},
        .Coloumn=10
};



#endif //UNTITLED1_LINK_H
