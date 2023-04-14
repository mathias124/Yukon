#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
    FILE *file;

    char cwd[1024];
    char *memoryBuff;
    long file_size;

    //char *FileName = "cmake-build-debug/DATA.txt";
    // Open the file, using CWD library to get a user's directory path to make it work.
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }
    char* file_name = "DATA.txt";
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
        fclose(file);
        // Print the contents of the file
        printf("%s", memoryBuff);

        // Free the buffer memory
        free(memoryBuff);

        return 0;
    }

