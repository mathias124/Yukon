//
// Created by Abdis on 5/5/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>


#include "Links.h"


#ifndef UNTITLED1_PRINTS_H
#define UNTITLED1_PRINTS_H



void CreateBoard();

void CreateBoard(){
Card *curr1 = c1.start.next;
Card *curr2 = c2.start.next;
Card *curr3 = c3.start.next;
Card *curr4 = c4.start.next;
Card *curr5 = c5.start.next;
Card *curr6 = c6.start.next;
Card *curr7 = c7.start.next;
Card *f1 = a1.start.next;
Card *f2 = a2.start.next;
Card *f3 = a3.start.next;
Card *f4 = a4.start.next;

printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "A", "F");
printf("\n");
int i=0;
int tru=1;
while(tru){
i++;
if(curr1->cardSuit!='n'&& curr1->cardSuit!=NULL){
printf("%c%c\t", curr1->cardValue, curr1->cardSuit);
curr1 = curr1->next;
}
if(curr2->cardSuit!='n'&& curr2->cardSuit!=NULL){
printf("%c%c\t", curr2->cardValue, curr2->cardSuit);
curr2 = curr2->next;
}


if(curr3->cardSuit!='n'&& curr3->cardSuit!=NULL){
printf("%c%c\t", curr3->cardValue, curr3->cardSuit);
curr3 = curr3->next;
}

if(curr4->cardSuit!='n'&& curr4->cardSuit!=NULL){
printf("%c%c\t", curr4->cardValue, curr4->cardSuit);
curr4 = curr4->next;

}
if(curr5->cardSuit!='n'&& curr5->cardSuit!=NULL){
printf("%c%c\t", curr5->cardValue, curr5->cardSuit);
curr5 = curr5->next;
}

if(curr6->cardSuit!='n'&& curr6->cardSuit!=NULL){
printf("%c%c\t", curr6->cardValue, curr6->cardSuit);
curr6 = curr6->next;
}

if(curr7->cardSuit!='n'&& curr7->cardSuit!=NULL){
printf("%c%c\t", curr7->cardValue, curr7->cardSuit);
curr7 = curr7->next;
}


if(i==1) {
printf("%c%c\t", f1->cardValue, f1->cardSuit);
printf("F1");
}
if(i==2) {
printf("%c%c\t", f2->cardValue, f2->cardSuit);
printf("F2");
}
if(i==3) {
printf("%c%c\t", f3->cardValue, f3->cardSuit);
printf("F3");
}
if(i==4) {
printf("%c%c\t", f4->cardValue, f4->cardSuit);
printf("F4");
}



printf("\n");



if(i>13)
tru=0;


}
printf("\n");
// INITIAL VIEW
printf("%s\n", "LAST Command:");
// message
printf("%s\n", "MESSAGE: ");
// intput
printf("%s\n", "INPUT > ");





}

#endif //UNTITLED1_PRINTS_H
/*
Card * card10 =*card1;
Card * card20 =*card2;
Card end = lists->list[card10->column]->end;
Card end2 = lists->list[card20->column]->end;



// remove cards from the old list
card10->prev->next= &lists->list[card10->column]->end;
lists->list[card10->column]->end.prev=card10->prev->next;
card10->prev=NULL;



// insert cards into the new list
/* card20->next->prev=card10;
 card10->next=card20->next->prev;
 card20->next=card10;*/

// update the column of the moved cards
//Card* curr = card10;
//while (curr->cardSuit!='n') {
//curr->column = card20->column;
//curr = curr->next;
//}
//curr->next=&end2;


//return 1;
