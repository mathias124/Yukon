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

void getLastCardInDeck(Card *pCard, int cards);

int main() {
    //Start Condition to keep game open for commands & gamemovement later on.
    bool startMeny = true;
    bool GameOpen = true;
    bool Undo = false;
    bool load=false;
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

    //char *FileName = "cmake-build-debug/DATA.txt";
    // Open the file, using CWD library to get a user's directory path to make it work.
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }
//Startmenu screen(input to choose filepath and continue or not.
    while(startMeny ==true && load==false ){
        char userinput[50];
        printf("Enter 'Y' to conitnue with a new game  or 'LD' to load previous savefile:");
        printf("\n");
        fgets(userinput,50,stdin);
        if(strcmp(userinput,"Y\n") ==0) {
            startMeny = false;
            snprintf(file_path, sizeof(file_path), "%s/%s", cwd, file_name);
        }else if (strcmp(userinput,"LD\n") ==0) {
            //Load Save.
            printf("loading your save...\n");
            load = true;
            snprintf(file_path, sizeof(file_path), "%s/%s", cwd, file_save);
        } else {
            printf("Invalid command, please enter either Y or LD to continue");
        }
        printf("File path: %s\n", file_path);
        file = fopen(file_path, "r");
        fseek(file, 0, SEEK_END);
        file_size = ftell(file);// Get the file size
        rewind(file);
    }

    // Allocate memory for the file buffer
    memoryBuff = (char *) malloc(file_size * sizeof(char));
    if (!memoryBuff) {
        printf("Error: Could not allocate memory for file buffer\n");
        fclose(file);
        return 1;
    }
          while (!feof(file) && startMeny ==false || load ==true) {
        Card card;
       int res;
            res = fscanf(file, "%c%c\n", &tempCardValue, &tempCardSuit);
        if (res == 2) {
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
            noCards++;
        }
    }
    //This method below is creating a txt file called shuffled_cards.txt and "w" writes it.
    //The next 40 lines are for creating and shuffeling cards and saving it.
    //shuffleCards(cards, noCards);
    FILE *save;
    save = fopen("shuffled_cards.txt", "w");
    if (save == NULL) {
        perror("Error could not create savefile");
        return 1;
    }
    for (int i = 0; i < noCards; ++i) {
        fprintf(save, "%c%c\n", cards[i].cardValue, cards[i].cardSuit);
    }
    fclose(save);

    // Print the cards in 7 columns
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "A", "F");
    printf("\n");
    for (int i = 0; i < noCards; i += 7) {
        printf("%c%c\t", cards[i].cardValue, cards[i].cardSuit);
        insert(&cards[i], &c1);
        cards[i].column=0;
        //cards[i].Hidden=1;
        if (i + 1 < noCards) {
            printf("%c%c\t", cards[i + 1].cardValue, cards[i + 1].cardSuit);
            insert(&cards[i + 1], &c2);
            cards[i+1].column=1;
        }
        if (i + 2 < noCards) {
            printf("%c%c\t", cards[i + 2].cardValue, cards[i + 2].cardSuit);
            insert(&cards[i + 2], &c3);
            cards[i+2].column=2;
        }
        if (i + 3 < noCards) {
            printf("%c%c\t", cards[i + 3].cardValue, cards[i + 3].cardSuit);
            insert(&cards[i + 3], &c4);
            cards[i+3].column=3;
        }
        if (i + 4 < noCards) {
            printf("%c%c\t", cards[i + 4].cardValue, cards[i + 4].cardSuit);
            insert(&cards[i + 4], &c5);
            cards[i+4].column=4;
        }
        if (i + 5 < noCards) {
            printf("%c%c\t", cards[i + 5].cardValue, cards[i + 5].cardSuit);
            insert(&cards[i + 5], &c6);
            cards[i+5].column=5;
        }
        if (i + 6 < noCards) {
            //Makes a tab after line C7 and using the for loop to count A foundations.
            insert(&cards[i + 6], &c7);
            //cards[i+6].column=6;
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

    // Read the file into the buffer
    fread(memoryBuff, sizeof(char), file_size, file);
    // Close the file
    fclose(file);
    free(memoryBuff);
    //This methods make the game in a while loop and makes the quit command to close game, furthermore commands.
    while (GameOpen) {

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
                    if ( s->trueValue<t->trueValue && s->cardSuit!=t->cardSuit && t->column!=s->column) {
                        SuperInsert(&s, &t, &AllList);
                        strcpy(message,"ok     ");
                    } else
                    strcpy(message,"Invalid");
                } else
                    strcpy(message,"Invalid");

            CreateBoard(message,commandBuff);
        }

    }
    return 0;}
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
// placeholder shuffle method
