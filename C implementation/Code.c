#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Comb Sort function
void combSort(int arr[], int n) {
    int gap = n;
    float shrink = 1.3;
    int swapped = 1;

    while (gap > 1 || swapped) {
        gap = (int)(gap / shrink);
        if (gap < 1)
            gap = 1;

        swapped = 0;

        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(&arr[i], &arr[i + gap]);
                swapped = 1;
            }
        }
    }
}

// Function to print an array to a file
void printArrayToFile(int arr[], int size, const char *filename) {
    FILE *outFile = fopen(filename, "a");

    if (!outFile) {
        printf("Error: Unable to open the file %s\n", filename);
        return;
    }

    for (int i = 0; i < size; i++)
        fprintf(outFile, "%d ", arr[i]);
    fprintf(outFile, "\n");
    fclose(outFile);
}

int main() {
    FILE *inFile = fopen("input.txt", "r");
    if (!inFile) {
        printf("Error: Unable to open the file input.txt\n");
        return 1;
    }

    int n;
    while (fscanf(inFile, "%d", &n) != EOF) {
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            fscanf(inFile, "%d", &arr[i]);
        }
        combSort(arr, n);
        printArrayToFile(arr, n, "output.txt");
        free(arr);
    }
    fclose(inFile);
    return 0;
}
