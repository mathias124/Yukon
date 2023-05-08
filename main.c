#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libc.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "card.h"
#include "readFile.h"
#include "Prints.h"
#include "list.h"


//void getLastCardInDeck(Card *pCard, int cards);

int main() {
    //Start Condition to keep game open for commands & gamemovement later on.
    //bool GameOpen = true;
    //bool Undo = false;
    //char commandBuff[BUFSIZ];

    //char *FileName = "cmake-build-debug/DATA.txt";
    // Open the file, using CWD library to get a user's directory path to make it work.


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
    }
    fclose(save);*/

    // INITIAL VIEW
    printf("%s\n", "LAST Command:");
    // message
    printf("%s\n", "MESSAGE: ");
    // intput
    printf("%s\n", "INPUT > ");

    // Read the file into the buffer
    //fread(memoryBuff, sizeof(char), file_size, file);
    // Close the file
    //fclose(file);
    //free(memoryBuff);
    //This methods make the game in a while loop and makes the quit command to close game, furthermore commands.
    /*while (GameOpen) {

        fgets(commandBuff, BUFSIZ, stdin);
        if (strcmp(commandBuff, "QQ\n") == 0 || strcmp(commandBuff, "qq\n") == 0) {
            GameOpen = false;
        } else if (strcmp(commandBuff, "SR\n") == 0 || strcmp(commandBuff, "sr\n") == 0) {
            ////////// Experimental commands

            printf("Shuffled Cards:\n");
            for (int i = 0; i < noCards; i++) {
                printf("%c\n", cards[i].cardValue);
            }
            //GameOpen = false;
        }else if (strcmp(commandBuff, "sw\n") == 0 || strcmp(commandBuff, "SW\n") == 0) {
            Card* deck = NULL;
            SW(deck);
        }
            //Undo commando.
        else if (strcmp(commandBuff, "U\n") == 0 || strcmp(commandBuff, "u\n") == 0) {
            Undo = true;

        }
            ///Redo Command
        else if (strcmp(commandBuff, "R\n") == 0) {
            if (Undo == true) {
                //Needs to be undone, before redo is available.
            }
        } else {
            if (strcmp(commandBuff, "t\n") == 0) {

               Card *t= getCard('H','4',&AllList);
                Card *s= getCard('D','Q',&AllList);
                SuperInsert(&s,&t,&AllList);

            }
            CreateBoard();

        }




    }*/
    return 0;}
    // placeholder shuffle method
    void shuffleCards(Card *cards, int noCards) {
        //Created random seed for cards, so every start is random.
        srand(time(NULL));
        for (int i = noCards - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            Card temp = cards[i];
            cards[i] = cards[j];
            cards[j] =  temp;

        }

    }

