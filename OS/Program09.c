#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a file block
struct FileBlock {
    int block_number;
    struct FileBlock* next_block;
};

// Structure for a file entry
struct File {
    char filename[30];
    struct FileBlock* first_block;
};

// Function to create a new file block
struct FileBlock* createFileBlock(int block_number) {
    struct FileBlock* new_block = (struct FileBlock*)malloc(sizeof(struct FileBlock));
    new_block->block_number = block_number;
    new_block->next_block = NULL;
    return new_block;
}

// Function to display the blocks of a file
void displayFileBlocks(struct File* file) {
    printf("File Name: %s\n", file->filename);
    printf("File Blocks: ");
    
    struct FileBlock* current_block = file->first_block;
    while (current_block != NULL) {
        printf("%d ", current_block->block_number);
        current_block = current_block->next_block;
    }
    printf("\n\n");
}

// Function to add a new block to a file
void addFileBlock(struct File* file, int block_number) {
    struct FileBlock* new_block = createFileBlock(block_number);
    if (file->first_block == NULL) {
        file->first_block = new_block;
    } else {
        struct FileBlock* current_block = file->first_block;
        while (current_block->next_block != NULL) {
            current_block = current_block->next_block;
        }
        current_block->next_block = new_block;
    }
}

int main() {
    // Create files with linked blocks
    struct File file1, file2, file3;
    strcpy(file1.filename, "file1.txt");
    file1.first_block = NULL;
    addFileBlock(&file1, 1);
    addFileBlock(&file1, 2);
    addFileBlock(&file1, 3);

    strcpy(file2.filename, "file2.txt");
    file2.first_block = NULL;
    addFileBlock(&file2, 4);
    addFileBlock(&file2, 5);

    strcpy(file3.filename, "file3.txt");
    file3.first_block = NULL;
    addFileBlock(&file3, 6);

    // Display file blocks
    displayFileBlocks(&file1);
    displayFileBlocks(&file2);
    displayFileBlocks(&file3);

    // Free allocated memory for file blocks
    struct FileBlock* current_block;

    while (file1.first_block != NULL) {
        current_block = file1.first_block;
        file1.first_block = file1.first_block->next_block;
        free(current_block);
    }

    while (file2.first_block != NULL) {
        current_block = file2.first_block;
        file2.first_block = file2.first_block->next_block;
        free(current_block);
    }

    while (file3.first_block != NULL) {
        current_block = file3.first_block;
        file3.first_block = file3.first_block->next_block;
        free(current_block);
    }

    return 0;
}
