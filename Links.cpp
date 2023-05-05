//
// Created by Abdis on 5/1/2023.
//

#include "Links.h"
// mangler nogen ting.Pototype.
/*
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
*/
/*
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
    int cardVal1 = charConverter(card->cardValue);
    int cardVal2 = charConverter(card2->cardValue);
    if (card->cardSuit == card2->cardSuit ||cardVal1<=cardVal2) {
        return 0;
    } else {
        return 1;
    }
}
int remove_last_card( Link *link) {
    Card *cur = link->end.prev;
    Card *prev = link->end.prev->prev;

    // If the list is empty or only has Done card, return an error
    if (prev == &(link->start)) {
        return 1;
    }

    // Remove the last card from the list
    prev->next = &(link->end);
    link->end.prev = prev;
    cur->next = &(link->end);

    return 0;
}

*/