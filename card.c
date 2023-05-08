//
// Created by Felix Schmidt on 08/05/2023.
//

#include <unistd.h>
#include "card.h"
#include "readFile.h"
#include "list.h"

Card* makeDeck() {
    Card* deck;
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
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
        fclose(file);
    }

    while (!feof(file)) {
        char tempCardValue;
        char tempCardSuit;
        Card card;
        int res = fscanf(file, "%c%c\n", &tempCardValue, &tempCardSuit);
        if (res == 2) {
            card = (Card) {tempCardSuit, tempCardValue};
            addCard(deck,card);
        }
    }
    return deck;
}