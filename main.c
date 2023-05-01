#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "card.h"
#include "readFile.h"




int main() {
    //Start Condition to keep game open for commands & gamemovement later on.
    bool GameOpen = true;
    bool Undo = false;
    char commandBuff[BUFSIZ];

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
        Card card;
        int res = fscanf(file, "%c%c\n", &tempCardValue, &tempCardSuit);
        if (res == 2) {
            card = (Card) {tempCardSuit, tempCardValue};
            cards[noCards] = card;
            printf("specific; %c%c\n", card.cardValue, card.cardSuit);
            printf("%c%c\r\n", cards[noCards].cardValue, cards[noCards].cardSuit);

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
    shuffleCards(cards, noCards);
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
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", "C1", "C2", "C3", "C4", "C5", "C6", "C7");
    printf("\n");
    for (int i = 0; i < noCards; i += 7) {
        printf("%c%c\t", cards[i].cardValue, cards[i].cardSuit);
        if (i + 1 < noCards) printf("%c%c\t", cards[i + 1].cardValue, cards[i + 1].cardSuit);
        if (i + 2 < noCards) printf("%c%c\t", cards[i + 2].cardValue, cards[i + 2].cardSuit);
        if (i + 3 < noCards) printf("%c%c\t", cards[i + 3].cardValue, cards[i + 3].cardSuit);
        if (i + 4 < noCards) printf("%c%c\t", cards[i + 4].cardValue, cards[i + 4].cardSuit);
        if (i + 5 < noCards) printf("%c%c\t", cards[i + 5].cardValue, cards[i + 5].cardSuit);
        if (i + 6 < noCards) printf("%c%c\n", cards[i + 6].cardValue, cards[i + 6].cardSuit);
        else printf("\n");
    }
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
            if (strcmp(commandBuff, "QQ\n") == 0||strcmp(commandBuff, "qq\n") == 0){
                GameOpen = false;
            }

        if(strcmp(commandBuff,"SR\n") ==0||strcmp(commandBuff,"sr\n") ==0) {
            ////////// Experimental commands
            shuffleCards(cards, noCards);
        }
        //Undo commando.
        if(strcmp(commandBuff,"U\n") ==0 || strcmp(commandBuff,"u\n") ==0){}
        Undo = true;

    }
    ///Redo Command
    if(strcmp(commandBuff,"R\n") ==0) {
        if (Undo == true) {
            //Needs to be undone, before redo is available.
        }
    }
        return 0;
}
// placeholder shuffle method
    void shuffleCards(Card *cards, int noCards) {
        for (int i = noCards - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            Card temp = cards[i];
            cards[i] = cards[j];
            cards[j] = temp;
        }
    }

