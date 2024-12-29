#include <stdio.h>
#include <stdlib.h>
#include "../include/array_ops.h"

#define MAX_SIZE 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }

    int arr[MAX_SIZE];
    int size = 0;
    int num;

    while (fscanf(fp, "%d", &num) == 1 && size < MAX_SIZE) {
        arr[size++] = num;
    }
    fclose(fp);

    // Print original array
    printf("Original array:");
    for (int i = 0; i < size; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    // Sort array
    int sorted[MAX_SIZE];
    for (int i = 0; i < size; i++) sorted[i] = arr[i];
    sort_array(sorted, size);
    printf("Sorted array:");
    for (int i = 0; i < size; i++) {
        printf(" %d", sorted[i]);
    }
    printf("\n");

    // Reverse array
    int reversed[MAX_SIZE];
    for (int i = 0; i < size; i++) reversed[i] = arr[i];
    reverse_array(reversed, size);
    printf("Reversed array:");
    for (int i = 0; i < size; i++) {
        printf(" %d", reversed[i]);
    }
    printf("\n");

    // Find max
    int max = find_max(arr, size);
    printf("Max value: %d\n", max);

    return 0;
}
