#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 20;
    int cols = 30;
    int **p; // Declaration of a double pointer for 2D array

    // Allocate memory for 20 rows of integer pointers
    p = (int**) malloc(rows * sizeof(int*));
    if(p == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Allocate memory for each row
    for(int i = 0; i < rows; i++) {
        p[i] = (int*) malloc(cols * sizeof(int));
        if(p[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            // Free already allocated memory before returning
            for(int j = 0; j < i; j++) {
                free(p[j]);
            }
            free(p);
            return 1;
        }
    }

    // Fill the array as per the requirement
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            p[i][j] = i + j; // Assign value according to given pattern
        }
    }

    // Print the array in grid format
    printf("Hello world! I have created a dynamic 2D-array of 20x30 integers!\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%2d ", p[i][j]); // Adjust the spacing if needed
        }
        printf("\n");
    }

    // Free the allocated memory
    for(int i = 0; i < rows; i++) {
        free(p[i]); // Free each row
    }
    free(p); // Free the row pointers array

    return 0;
}
