#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "card.h"
#include "readFile.h"
#include "Links.h"
#include "Prints.h"
#include "validateMove.h"






int main() {
    //Start Condition to keep game open for commands & gamemovement later on.
    bool GameOpen = true;
    bool Undo = false;
    char commandBuff[20];
    LinkedLists AllList;
    char  message [8];
    AllList.list[0] = &c1;
    AllList.list[1] = &c2;
    AllList.list[2] = &c3;
    AllList.list[3] = &c4;
    AllList.list[4] = &c5;
    AllList.list[5] = &c6;
    AllList.list[6] = &c7;
    AllList.list[7] = &a1;
    AllList.list[8] = &a2;
    AllList.list[9] = &a3;
    AllList.list[10] = &a4;
    int mode=0;
    int line;
    





    //char *FileName = "cmake-build-debug/DATA.txt";
    // Open the file, using CWD library to get a user's directory path to make it work.
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }

    //Filepath for DATA.txt
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

        int res = fscanf(file, "%c%c\n", &tempCardValue, &tempCardSuit);
        if (res == 2) {
            if(!validate(&tempCardSuit, &tempCardValue)){

              line=noCards+1;
                printf("Invalid input at line %d\n", line);
                exit(0);
            }
                Card card;
                card = (Card) {tempCardSuit, tempCardValue};
                cards[noCards] = card;
                printf("specific; %c%c\n", card.cardValue, card.cardSuit);
                printf("%c%c\r\n", cards[noCards].cardValue, cards[noCards].cardSuit);
                cards[noCards].next = NULL;
                cards[noCards].prev = NULL;
                cards[noCards].trueValue = charConverter(cards[noCards].cardValue);


                if (cards[noCards].cardSuit == 'S' || cards[noCards].cardSuit == 'H') {
                    redCards[noRedCards] = cards[noCards];
                    noRedCards++;
                } else {
                    blackCards[noBlackCards] = cards[noCards];
                    noBlackCards++;
                }
                printf("Number of red cards : %d\r\n", noRedCards);
                printf("Number of black cards : %d\r\n", noBlackCards);
                if(noCards<1){
                    insert(&cards[noCards], &c1);
                    cards[noCards].column=0;
                }
                else if(noCards<7){
                    insert(&cards[noCards], &c2);
                    cards[noCards].column=1;
                    if(noCards<2)
                    cards[noCards].Hidden=1;
                }
                else if(noCards<14){
                    insert(&cards[noCards], &c3);
                    cards[noCards].column=2;
                    if(noCards<9)
                        cards[noCards].Hidden=1;
                }
                else if(noCards<22){
                    insert(&cards[noCards], &c4);
                    cards[noCards].column=3;
                    if(noCards<17)
                        cards[noCards].Hidden=1;
                }
                else if(noCards<31){
                    insert(&cards[noCards], &c5);
                    cards[noCards].column=4;
                    if(noCards<26)
                        cards[noCards].Hidden=1;
                }
                else if(noCards<41){
                    insert(&cards[noCards], &c6);
                    cards[noCards].column=5;
                    if(noCards<36)
                        cards[noCards].Hidden=1;
                } else{
                    insert(&cards[noCards], &c7);
                    cards[noCards].column=6;
                    if(noCards<47)
                        cards[noCards].Hidden=1;
                }

                noCards++;
            }
        }

    if(noCards!=52){
        printf("Too few cards.\n" );
        exit(0);
    }

    //This method below is creating a txt file called shuffled_cards.txt and "w" writes it.
    //The next 40 lines are for creating and shuffeling cards and saving it.
    //shuffleCards(cards, noCards);
  /* FILE *save;
    save = fopen("shuffled_cards.txt", "w");
    if (save == NULL) {
        perror("Error could not create savefile");
        return 1;
    }
    for (int i = 0; i < noCards; ++i) {
        fprintf(save, "%c%c\n", cards[i].cardValue, cards[i].cardSuit);
    }*/
    fclose(file);
    free(memoryBuff);



    // Print the cards in 7 columns
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "A", "F");
    printf("\n");
    for (int i = 0; i < noCards; i += 7) {
        printf("%c%c\t", cards[i].cardValue, cards[i].cardSuit);

        if (i + 1 < noCards) {
            printf("%c%c\t", cards[i + 1].cardValue, cards[i + 1].cardSuit);

        }
        if (i + 2 < noCards) {
            printf("%c%c\t", cards[i + 2].cardValue, cards[i + 2].cardSuit);

        }
        if (i + 3 < noCards) {
            printf("%c%c\t", cards[i + 3].cardValue, cards[i + 3].cardSuit);

        }
        if (i + 4 < noCards) {
            printf("%c%c\t", cards[i + 4].cardValue, cards[i + 4].cardSuit);

        }
        if (i + 5 < noCards) {
            printf("%c%c\t", cards[i + 5].cardValue, cards[i + 5].cardSuit);

        }
        if (i + 6 < noCards) {
            //Makes a tab after line C7 and using the for loop to count A foundations.

            if (i / 7 + 1 <= 4) {
                printf("%c%c\t", cards[i + 6].cardValue, cards[i + 6].cardSuit);
                printf("[A%d]\t", i / 7 + 1);
            } else {
                printf("%c%c\t", cards[i + 6].cardValue, cards[i + 6].cardSuit);
                //   insert(&cards[i+6],&c7);
            }
        } else {
            // printf("[ ]\t[ ]\t");
        }//This is for line F/9, so it only contains 4 rows.
        if (i / 7 + 1 <= 4) printf("F%d", i / 7 + 1);


        printf("\n");
    }
    printf("\n");
    // INITIAL VIEW
    printf("%s\n", "LAST Command:");
    // message
    printf("%s\n", "MESSAGE: ");
    // intput
    printf("%s\n", "INPUT > ");




    //This methods make the game in a while loop and makes the quit command to close game, furthermore commands.
    while (GameOpen) {
        fgets(commandBuff, 20, stdin);
        if (strcmp(commandBuff, "QQ\n") == 0 || strcmp(commandBuff, "qq\n") == 0) {
            GameOpen = false;
        } else if (strcmp(commandBuff, "SR\n") == 0 || strcmp(commandBuff, "sr\n") == 0) {
            ////////// Experimental commands

            printf("Shuffled Cards:\n");
            for (int i = 0; i < noCards; i++) {
                printf("%c\n", cards[i].cardValue);
            }
            //GameOpen = false;
        }
            //Undo commando.
        else if (strcmp(commandBuff, "U\n") == 0 || strcmp(commandBuff, "u\n") == 0) {
            Undo = true;

        }
        else if (strcmp(commandBuff, "p\n") == 0 || strcmp(commandBuff, "P\n") == 0) {
            mode=1;
        }
            ///Redo Command
        else if (strcmp(commandBuff, "R\n") == 0) {
            if (Undo == true) {
                //Needs to be undone, before redo is available.
            }
        } else  {
               Card *t= getCard(commandBuff[4],commandBuff[3],&AllList);
                Card *s= getCard(commandBuff[1],commandBuff[0],&AllList);
                if(s!=NULL && t!=NULL ) {
                  //  if ( s->trueValue<t->trueValue && s->cardSuit!=t->cardSuit && t->column!=s->column &&t->next->cardSuit=='n') {
                        SuperInsert(&s, &t, &AllList);
                        strcpy(message,"ok     ");
                   // } else
                  //  strcpy(message,"Invalid");
                } else
                    strcpy(message,"Invalid");
            removeHidden(&AllList);
            CreateBoard(message,commandBuff);
            printf("%d%c",c2.end.prev->Hidden,c2.end.prev->cardSuit);

        }




    }

    return 0;}


