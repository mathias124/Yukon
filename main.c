#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libc.h>
#include "card.h"
#include "readFile.h"
#include "Links.h"







int main() {
    LinkedLists AllList;
    AllList.list[0]=&c1;
    AllList.list[1]=&c2;
    AllList.list[2]=&c3;
    AllList.list[3]=&c4;
    AllList.list[4]=&c5;
    AllList.list[5]=&c6;
    AllList.list[6]=&c7;
    AllList.list[7]=&a1;
    AllList.list[8]=&a2;
    AllList.list[9]=&a3;
    AllList.list[10]=&a4;





    //char *FileName = "cmake-build-debug/DATA.txt";
    // Open the file, using CWD library to get a user's directory path to make it work.
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }



    snprintf(file_path, sizeof(file_path), "%s/%s", cwd, file_name);
    printf("File path: %s\n", file_path);
    file = fopen(file_path, "r");
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);// Get the file size
    rewind(file);


    // Allocate memory for the file buffer
    memoryBuff = (char *) malloc(file_size * sizeof(char));
    if (!memoryBuff) {
        printf("Error: Could not allocate memory for file buffer\n");
        fclose(file);
        return 1;
    }
    while (!feof(file)) {
        Card card;
        int res = fscanf(file, "%c%c\n", &tempCardValue, &tempCardSuit);
        if (res == 2) {
            card =  (Card){tempCardSuit, tempCardValue};
            cards[noCards] = card;
            //printf("specific; %c%c\n",card.cardValue,card.cardSuit);
            //printf("%c%c\r\n", cards[noCards].cardValue, cards[noCards].cardSuit);
            cards[noCards].next=NULL;
            cards[noCards].prev=NULL;
            cards[noCards].trueValue= charConverter(cards[noCards].cardValue);




            if(cards[noCards].cardSuit == 'S' || cards[noCards].cardSuit == 'H'){
                redCards[noRedCards] = cards[noCards];
                noRedCards++;
            }else{
                blackCards[noBlackCards] = cards[noCards];
                noBlackCards++;
            }
           //printf("Number of red cards : %d\r\n", noRedCards);
           // printf("Number of black cards : %d\r\n", noBlackCards);
            noCards++;

        }

    }
    // Initialize the deck
    Card* deck = NULL;

    for (int i = 0; i < 52; i++) {
        insert_card(&deck, cards[i].cardSuit, cards[i].cardValue);
    }
    Card* column[7] = {NULL};
    Card* foundation[4] = {NULL};
    for (int i = 0; i < 7; i++) {
        for (int j = i; j < 7; j++) {
            insert_card(&column[j], deck->cardSuit, deck->cardValue);
            deck = deck->next;
        }
    }
    for (int i = 0; i < 7; i++) {
            print_cards(column[i]);
            printf("\t");
            printf("\n");
        }

    // Print the cards in 7 columns
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", "C1", "C2", "C3", "C4","C5", "C6", "C7");
    printf("\n");
   /* for (int i = 0; i < noCards; i += 7) {
        printf("%c%c\t", cards[i].cardValue, cards[i].cardSuit);
        if (i + 1 < noCards) printf("%c%c\t", cards[i+1].cardValue, cards[i+1].cardSuit);
        if (i + 2 < noCards) printf("%c%c\t", cards[i+2].cardValue, cards[i+2].cardSuit);
        if (i + 3 < noCards) printf("%c%c\t", cards[i+3].cardValue, cards[i+3].cardSuit);
        if (i + 4 < noCards) printf("%c%c\t", cards[i+4].cardValue, cards[i+4].cardSuit);
        if (i + 5 < noCards) printf("%c%c\t", cards[i+5].cardValue, cards[i+5].cardSuit);
        if (i + 6 < noCards) printf("%c%c\n", cards[i+6].cardValue, cards[i+6].cardSuit);
        else printf("\n");
    }*/
    for (int i = 0; i < noCards; i += 7) {

        for (int j = 0; j < 7 && i+j < noCards; j++) {
            printf("%c%c\t", cards[i+j].cardValue, cards[i+j].cardSuit);
        }
        printf("\n");
    }
    // INITIAL VIEW
    printf("%s\n", "LAST Command:");
    // message
    printf("%s\n", "MESSAGE: ");
    // intput
    printf("%s\n", "INPUT > ");





    insert(&cards[2], &c1);
    cards[1].prev=&c1.start;
    cards[1].next=&c1.end;
    SuperInsert(&cards[1],&cards[2],&AllList);




    //remove_last_card(c1);
    //remove_last_card(c1);

  //  Card found=LAstCard(c1);


        printf("Next card after dummy: %c%c\n", c1.start.next->next->next->cardSuit, c1.start.next->next->next->cardValue);


  //  Card  th = *list->next;







    // Read the file into the buffer
    fread(memoryBuff, sizeof(char), file_size, file);
    // Close the file
    fclose(file);
    free(memoryBuff);







    return 0;
}
/*// placeholder shuffle method
void shuffleCards(Card *cards, int noCards){
    for(int  i = noCards -1; i > 0; i--){
        int j = rand() % (i + 1);
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }

}*/


