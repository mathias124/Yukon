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
    int DiamondArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    char suit [52];
    char value[52];


    typedef struct CardType {
        char name[2];
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
    // Read the file into the buffer
    fread(memoryBuff, sizeof(char), file_size, file);
    // Close the file
   // fclose(file);
    // Print the contents of the file
    int sw = 0;
    int j = 0;



 /*   for (int i = 0; i < file_size; i++) {
        if (memoryBuff[i] != '\n' && memoryBuff[i] != '\r') {
            if (sw == 0) {
                cards[j].name[0] = memoryBuff[i];
                sw=1;
            } else if (sw==1) {
                cards[j].name[1] = memoryBuff[i];
                sw = 0;
                j++;
            }



        }
        if(j==52)
            break;
    }
    */
    while (1)
    {
        // Read an integer and a string from the file
        int res =   fscanf(file,"%s %s",&suit,value);

        // Check whether fscanf was successful
        if (res == -1)
        {
            printf("ID: %s\n", suit);
            printf("Name: %s\n", value);
        }
        else
        {
            printf("Error reading input from file.\n");
            break;
        }
    }

    // Close the file
    fclose(file);




    // Free the buffer memory
    free(memoryBuff);

 /*   for (int q = 0; q < 13; q++)
        printf("%c\n", cards[q].name[0]);
    printf("%d\n",j);
    */

    return 0;

}
