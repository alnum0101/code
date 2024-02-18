#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a file entry
struct File {
    char filename[30];
    int size;
};

// Structure for a directory entry
struct Directory {
    char dirname[30];
    int num_files;
    struct File files[10];
};

// Function to display the contents of a single-level directory
void displaySingleLevelDirectory(struct Directory directory) {
    printf("\nSingle-Level Directory:\n");
    printf("Directory Name: %s\n", directory.dirname);
    printf("Number of Files: %d\n", directory.num_files);
    printf("Files:\n");

    for (int i = 0; i < directory.num_files; i++) {
        printf("File Name: %s, Size: %d\n", directory.files[i].filename, directory.files[i].size);
    }
}

// Function to display the contents of a two-level directory
void displayTwoLevelDirectory(struct Directory directories[], int num_directories) {
    printf("\nTwo-Level Directory:\n");

    for (int i = 0; i < num_directories; i++) {
        printf("Directory Name: %s\n", directories[i].dirname);
        printf("Number of Files: %d\n", directories[i].num_files);
        printf("Files:\n");

        for (int j = 0; j < directories[i].num_files; j++) {
            printf("File Name: %s, Size: %d\n", directories[i].files[j].filename, directories[i].files[j].size);
        }

        printf("\n");
    }
}

int main() {
    // Single-Level Directory
    struct Directory singleLevelDirectory;

    strcpy(singleLevelDirectory.dirname, "root");
    singleLevelDirectory.num_files = 3;

    strcpy(singleLevelDirectory.files[0].filename, "file1.txt");
    singleLevelDirectory.files[0].size = 100;

    strcpy(singleLevelDirectory.files[1].filename, "file2.txt");
    singleLevelDirectory.files[1].size = 150;

    strcpy(singleLevelDirectory.files[2].filename, "file3.txt");
    singleLevelDirectory.files[2].size = 200;

    displaySingleLevelDirectory(singleLevelDirectory);

    // Two-Level Directory
    struct Directory twoLevelDirectories[2];

    twoLevelDirectories[0].num_files = 2;
    strcpy(twoLevelDirectories[0].dirname, "user1");

    strcpy(twoLevelDirectories[0].files[0].filename, "file1.txt");
    twoLevelDirectories[0].files[0].size = 120;

    strcpy(twoLevelDirectories[0].files[1].filename, "file2.txt");
    twoLevelDirectories[0].files[1].size = 180;

    twoLevelDirectories[1].num_files = 1;
    strcpy(twoLevelDirectories[1].dirname, "user2");

    strcpy(twoLevelDirectories[1].files[0].filename, "file3.txt");
    twoLevelDirectories[1].files[0].size = 220;

    displayTwoLevelDirectory(twoLevelDirectories, 2);

    return 0;
}
