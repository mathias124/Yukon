#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "card.h"
#include "readFile.h"
#include "list.h"
#include "gameboard.h"
#include "moveValidation.h"

void getLastCardInDeck(Card *pCard, int cards);

int main() {
    //Start Condition to keep game open for commands & gamemovement later on.
    bool startMeny = true;
    bool GameOpen = true;
    bool load = false;
    Board *playBoard;
    List *deckList = makeList();
    //char *FileName = "cmake-build-debug/DATA.txt";
    // Open the file, using CWD library to get a user's directory path to make it work.
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }
//Startmenu screen(input to choose filepath and continue or not.
    while (startMeny == true && load == false) {
        char userinput[50];
        printf("Enter 'Y' to conitnue with a new game  or 'LD' to load previous savefile:");
        printf("\n");
        fgets(userinput, 50, stdin);
        if (strcmp(userinput, "Y\n") == 0) {
            startMeny = false;
            load = false;
            snprintf(file_path, sizeof(file_path), "%s/%s", cwd, file_name);
        } else if (strcmp(userinput, "LD\n") == 0) {
            //Load Save.
            printf("loading your save...\n");
            load = true;
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
    int noCards = 0;
    Card checkingCard;
    Card hiddenCard;
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
    while (!feof(file) && startMeny == false) {
        Card card;
        int res;
        res = fscanf(file, "%c%c\n", &tempCardValue, &tempCardSuit);
        if (res == 2) {
            card = (Card) {tempCardSuit, tempCardValue};
            cards[noCards] = card; // To be deleted
            addCard(deckList, card);

        }
        noCards++;
    }
    //This method below is creating a txt file called shuffled_cards.txt and "w" writes it.
    //The next 40 lines are for creating and shuffeling cards and saving it.
    if (load == false) {
        shuffleCards(cards, noCards);
    }

    FILE *save;
    save = fopen("shuffled_cards.txt", "w");
    if (save == NULL) {
        perror("Error could not create savefile");
        return 1;
    }
    for (int i = 0; i < 52; ++i) {
        fprintf(save, "%c%c\n", cards[i].cardValue, cards[i].cardSuit);
    }
    fclose(save);


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
            FILE *save;
            save = fopen("shuffled_cards.txt", "w");
            if (save == NULL) {
                perror("Error could not create savefile");
                return 1;
            }
            for (int i = 0; i < 52; ++i) {
                fprintf(save, "%c%c\n", cards[i].cardValue, cards[i].cardSuit);
            }
            fclose(save);
        } else if (strcmp(commandBuff, "SR\n") == 0 || strcmp(commandBuff, "sr\n") == 0) {
            ////////// Experimental commands

            printf("Shuffled Cards:\n");
            for (int i = 0; i < noCards; i++) {
                printf("%c\n", cards[i].cardValue);
            }
            //GameOpen = false;
        } else if (strcmp(commandBuff, "SW\n") == 0 || strcmp(commandBuff, "sw\n") == 0) {
            playBoard = createBoard(deckList);
            makeShowCaseMode(playBoard);
            printShowCase(playBoard);
            printf("%s%s\n", "LAST Command: ",commandBuff);

        } else if (strcmp(commandBuff, "P\n") == 0 || strcmp(commandBuff, "p\n") == 0) {
            playBoard = createBoard(deckList);
            makePlayMode(playBoard);
            printShowCase(playBoard);
            printf("%s%s\n", "LAST Command: ",commandBuff);

        } else if (strcmp(commandBuff, "U\n") == 0 || strcmp(commandBuff, "u\n") == 0) {
            printShowCase(playBoard);
            printf("%s%s\n", "LAST Command: ",commandBuff);

        }

        // TO:FROM command
        else if (strlen(commandBuff) > 1 && strlen(commandBuff) < 7) {
            char from[3], to[3];
            sscanf(commandBuff, "%2s:%2s", from, to);
            // Move from column to foundation
            if (from[0] == 'C' && to[0] == 'F') {
                int fromColumnIndex = atoi(&from[1]) - 1;
                int foundationIndex = atoi(&to[1]) - 1;
                List *columnList;
                columnList = &playBoard->columns[fromColumnIndex];
                checkingCard = getCardAt(columnList, columnList->size - 1);
                int verifcation = moveToFoundation(checkingCard, &playBoard->foundations[foundationIndex]);
                if (verifcation == 1) {
                    moveColumnToFoundation(playBoard, fromColumnIndex, foundationIndex);
                }
                printShowCase(playBoard);
                printf("%s%s\n", "LAST Command: ",commandBuff);
                printf("%s\n", "INPUT > ");


            }

            // Move from foundation to column
            else if (from[0] == 'F' && to[0] == 'C') {
                int foundationIndex = atoi(&from[1]) - 1;
                int toColumnIndex = atoi(&to[1]) - 1;
                List *foundationList;
                foundationList = &playBoard->foundations[foundationIndex];
                checkingCard = getCardAt(foundationList, 0);
                int verification = getColumnToColumnVerification(checkingCard, &playBoard->columns[toColumnIndex]);
                if (verification == 1) {
                    moveFoundationToColumn(playBoard, foundationIndex, toColumnIndex);
                }
                printShowCase(playBoard);
                printf("%s%s\n", "LAST Command: ",commandBuff);
                printf("%s\n", "INPUT > ");
            }
                // Move from column to column
            else if (from[0] == 'C' && to[0] == 'C') {
                int fromColumnIndex = atoi(&from[1]) - 1;
                int toColumnIndex = atoi(&to[1]) - 1;
                List *columnList;
                columnList = &playBoard->columns[fromColumnIndex];
                checkingCard = getCardAt(columnList, columnList->size - 1);
                int verification = getColumnToColumnVerification(checkingCard, &playBoard->columns[toColumnIndex]);
                if (verification == 1) {
                    moveColumnToColumn(playBoard, fromColumnIndex, toColumnIndex);
                    hiddenCard = getCardAt(columnList,columnList->size - 1);
                }

                if (hiddenCard.Hidden == 1) {
                    hiddenCard = popCardAt(columnList, columnList->size - 1);
                    setHidden(&hiddenCard);
                    addCardAt(columnList, columnList->size, hiddenCard);
                }

            } else {
                //incase of invalid comments
                printf("Invalid command\n");
            }
            printShowCase(playBoard);
            printf("%s%s\n", "LAST Command: ",commandBuff);
            printf("%s\n", "INPUT > ");
        }

    //TO:CARD:FROM
    // If command length is greater than 6, it's a 'FROM:CARD:TO' command
    else if (strlen(commandBuff)>6){
            // Parse command into 'FROM', 'CARD', and 'TO' variables
        char from[3],card[3],to[3];
        sscanf(commandBuff,"%2s:%2s:%2s",from,card,to);

            // Check if 'FROM' and 'TO' are columns
        if(from[0] == 'C' && to[0] == 'C'){
            // Get column index, card value, card suit, and card index of the card being moved
            int fromColumnIndex = atoi(&from[1])-1;
            char fromCardValue = card[0];
            char fromCardSuit = card[1];
            int fromCardIndex = getIndexOfCard(&playBoard->columns[fromColumnIndex],fromCardSuit,fromCardValue);

            // Get hidden status of the card being moved and verification status of the move
            int toColumnIndex = atoi(&to[1])-1;
            List* columnList;
            columnList = &playBoard->columns[fromColumnIndex];
            int fromHidden = getCardHiddenStatusAt(&playBoard->columns[fromColumnIndex],fromCardIndex);
            int fromVerification = getColumnVerification(fromCardValue,fromCardSuit,&playBoard->columns[toColumnIndex]);

            // If card is not hidden and move is valid, move card(s) from one column to another
            if(fromHidden == 0 && fromVerification  == 1){
                moveCardsFromColumnToColumn(playBoard,fromColumnIndex,fromCardIndex,toColumnIndex);
                hiddenCard = getCardAt(columnList,columnList->size - 1);
            }
            if(hiddenCard.Hidden == 1){
                hiddenCard = popCardAt(&playBoard->columns[fromColumnIndex], columnList->size-1);
                setHidden(&hiddenCard);
                addCardAt(&playBoard->columns[fromColumnIndex], columnList->size,hiddenCard);
            }

        } else{
            //incase of invalid comments
            printf("Invalid command\n");
        }

    printShowCase(playBoard);
    printf("%s%s\n", "LAST Command: ",commandBuff);
    printf("%s\n", "INPUT > ");
    }else if(getListSize(&playBoard->foundations[0])// If all cards are on the foundations, end the game
             +getListSize(&playBoard->foundations[1])
             +getListSize(&playBoard->foundations[2])
             +getListSize(&playBoard->foundations[3]) == 52){
            GameOpen = false;
    }


}


    return 0;
}
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