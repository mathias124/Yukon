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
    char VariableT[2];
    char VariableC[2];
    int DiamondArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    char ColorSize[13];
    char Array[0];


     struct CardType {
        char name[2];
        struct CardType *prev;
        struct CardType*next;

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
int noCards=0;
    struct CardType *er = NULL;
    while (!feof(file)) {
        int res = fscanf(file, "%c%c", &VariableC, &VariableT);
        if (res == 2) {
            cards[noCards].name[0]=*VariableC;

            cards[noCards].name[1]=*VariableT;
            cards[noCards].prev=er;
            er =& cards[noCards];



            printf("VariableChar : %c\r\n", cards[noCards].name[0]);
            printf("VariableT : %c\r\n", cards[noCards].name[1]);
            noCards++;
        }
    }
    struct CardType mt = *cards[51].prev;
    printf("Teste : %c\r\n",mt.name[0]);


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