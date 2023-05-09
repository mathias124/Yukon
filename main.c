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
#include "list.h"
#include "gameboard.h"

void getLastCardInDeck(Card *pCard, int cards);

int main() {
    //Start Condition to keep game open for commands & gamemovement later on.
    bool startMeny = true;
    bool GameOpen = true;
    bool Undo = false;
    bool load=false;
    Board *board;
    Board *playBoard;
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
    List* deckList = makeList();
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
            //load = true;
            startMeny = false;
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


    struct Card cards[52];
    struct Card blackCards[26];
    struct Card redCards[26];
    int noBlackCards = 0;
    int noRedCards = 0;
    int noCards=0;
// CARD TYPES
    char tempCardSuit;
    char tempCardValue;

    // Allocate memory for the file buffer
    memoryBuff = (char *) malloc(file_size * sizeof(char));
    if (!memoryBuff) {
        printf("Error: Could not allocate memory for file buffer\n");
        fclose(file);
        return 1;
    }
  while (!feof(file) && startMeny ==false) {
        Card card;
       int res;
            res = fscanf(file, "%c%c\n", &tempCardValue, &tempCardSuit);
        if (res == 2) {
            card = (Card) {tempCardSuit, tempCardValue};
            cards[noCards] = card; // To be deleted
            addCard(deckList,card);

        }
        noCards++;
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
    //for (int i = 0; i < 52; ++i) {
    //        fprintf(save, "%c%c\n", cards[i].cardValue, cards[i].cardSuit);
    //}
    fclose(save);
    // making a board

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
        } else if (strcmp(commandBuff, "SW\n") == 0 || strcmp(commandBuff, "sw\n") == 0) {
            board = createBoard(deckList);
            //free(board);
            makeShowCaseMode(board);
            printShowCase(board);
        } else if (strcmp(commandBuff, "P\n") == 0 || strcmp(commandBuff, "p\n") == 0) {
            playBoard = createBoard(deckList);
            //free(playBoard);
            //test
            makePlayMode(playBoard);
            printShowCase(playBoard);
        } else if (strcmp(commandBuff, "U\n") == 0 || strcmp(commandBuff, "u\n") == 0) {

            printShowCase(board);
        } else if (strcmp(commandBuff, "p\n") == 0 || strcmp(commandBuff, "P\n") == 0) {
            mode = 1;
        }
            ///Redo Command
        else if (strcmp(commandBuff, "R\n") == 0) {
            if (Undo == true) {
                //Needs to be undone, before redo is available.
            }
        }// TO:FROM command
        else if (strlen(commandBuff) > 1) {
            char from[3], to[3];
            sscanf(commandBuff, "%2s:%2s", from, to);
            // Move from column to foundation
            if (from[0] == 'C' && to[0] == 'F') {
                int fromColumnIndex = atoi(&from[1]) - 1;
                int foundationIndex = atoi(&to[1]) - 1;
                moveColumnToFoundation(board, fromColumnIndex, foundationIndex);
            }

                // Move from foundation to column
            else if (from[0] == 'F' && to[0] == 'C') {
                int foundationIndex = atoi(&from[1]) - 1;
                int toColumnIndex = atoi(&to[1]) - 1;
                moveFoundationToColumn(board, foundationIndex, toColumnIndex);
            }

                // Move from column to column
            else if (from[0] == 'C' && to[0] == 'C') {
                int fromColumnIndex = atoi(&from[1]) - 1;
                int toColumnIndex = atoi(&to[1]) - 1;
                if (strlen(from) == 3 && from[2] != '\0' && from[2] >= '1' && from[2] <= '7') {
                    int numCards = from[2] - '0';
                    moveCardsFromColumnToColumn(board, fromColumnIndex, toColumnIndex, numCards);
                } else {
                    moveColumnToColumn(board, fromColumnIndex, toColumnIndex);
                }
            }

                // Invalid command
            else {
                printf("Invalid command\n");
            }
        printShowCase(board);
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
