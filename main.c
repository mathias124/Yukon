#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {

    FILE *file;

    char cwd[1024];
    char *memoryBuff;
    long file_size;
    int SizeOfCards = 13;
    //char c = (char) "c";
    char clubs['C'];
    char Hearts['H'];
    char Diamonds['D'];
    char Spades['S'];
    int count = 0;
    char cardColor[2];
    char cardValue[2];
    int DiamondArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    char ColorSize[13];
    char Array[0];


    struct CardType {
        char name[2];
        struct CardType *next;
        //Max 2

    };

    struct CardType cards[52];

    //char *FileName = "cmake-build-debug/DATA.txt";
    // Open the file, using CWD library to get a user's directory path to make it work.
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }
    char *file_name = "DATA.txt";
    char file_path[1024];
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
    struct CardType blackCards[26];
    int noBlackCards = 0;
    struct CardType redCards[26];
    int noRedCards = 0;

    int noCards=0;
    while (!feof(file)) {
        int res = fscanf(file, "%c%c", &cardValue, &cardColor);
        if (res == 2) {
            cards[noCards].name[0]=*cardValue;
            cards[noCards].name[1]=*cardColor;


            printf("%c%c\r\n", cards[noCards].name[0], cards[noCards].name[1]);
            if(cards[noCards].name[1] == 'S' || cards[noCards].name[1] == 'H'){
                redCards[noRedCards] = cards[noCards];
                noRedCards++;
            }else{
                blackCards[noBlackCards] = cards[noCards];
                noBlackCards++;
            }
            printf("Number of red cards : %d\r\n", noRedCards);
            printf("Number of black cards : %d\r\n", noBlackCards);
            noCards++;
        }
    }




    // Read the file into the buffer
    fread(memoryBuff, sizeof(char), file_size, file);
    // Close the file
    fclose(file);
    // Print the contents of the file
    //for (int i = 0; i < file_size; i += 2) {
    //printf("%c", memoryBuff[i]);
    // Free the buffer memory
    free(memoryBuff);
    return 0;
}