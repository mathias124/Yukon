#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_ptr;

    char *buffer;
    long file_size;
    // Open the file
    file_ptr = fopen("C:\\Users\\Mathias\\CLionProjects\\untitled1\\DATA.txt", "r");

    // Get the file size
    fseek(file_ptr, 0, SEEK_END);
    file_size = ftell(file_ptr);
    rewind(file_ptr);

    // Allocate memory for the file buffer
    buffer = (char*) malloc(file_size * sizeof(char));
    if (!buffer) {
        printf("Error: Could not allocate memory for file buffer\n");
        fclose(file_ptr);
        return 1;
    }

    // Read the file into the buffer
    fread(buffer, sizeof(char), file_size, file_ptr);

    // Close the file
    fclose(file_ptr);

    // Print the contents of the file
    printf("%s", buffer);

    // Free the buffer memory
    free(buffer);

    return 0;
}
