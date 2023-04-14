#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *file_ptr;

    char cwd[PATH_MAX];
    char *memoryBuff;
    long file_size;


    //char *FileName = "cmake-build-debug/DATA.txt";
    // Open the file
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
        exit(EXIT_FAILURE);
    }
       // printf("Current working directory: %s\n", cwd);
    char* file_name = "DATA.txt";
    char file_path[PATH_MAX];
    snprintf(file_path, sizeof(file_path), "%s/%s", cwd, file_name);

    printf("Current working directory: %s\n", cwd);
    printf("File path: %s\n", file_path);

        file_ptr = fopen(file_path, "r");
        //file_ptr = fopen(FileName, "r");
        // Get the file size
        fseek(file_ptr, 0, SEEK_END);
        file_size = ftell(file_ptr);
        rewind(file_ptr);

        // Allocate memory for the file buffer
        memoryBuff = (char *) malloc(file_size * sizeof(char));
        if (!memoryBuff) {
            printf("Error: Could not allocate memory for file buffer\n");
            fclose(file_ptr);
            return 1;
        }
        // Read the file into the buffer
        fread(memoryBuff, sizeof(char), file_size, file_ptr);
        // Close the file
        fclose(file_ptr);
        // Print the contents of the file
        printf("%s", memoryBuff);

        // Free the buffer memory
        free(memoryBuff);

        return 0;
    }

