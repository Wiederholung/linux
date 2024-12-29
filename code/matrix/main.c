#include <stdio.h>
#include <stdlib.h>
#include "point_wise_product.h"
#include "matrix_product.h"

void print_matrix(int* matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    char choice;
    while(1) {
        printf("Enter '0' for Point-wise Product, '1' for Matrix Product, or 'q' to quit: ");
        scanf(" %c", &choice);

        if(choice == 'q') {
            printf("program ended.\n");
            break;
        }

        if(choice == '0') {
            int rows, cols;
            printf("Enter number of rows and columns: ");
            if(scanf("%d %d", &rows, &cols) != 2) {
                printf("Invalid input!\n");
                continue;
            }

            int *A = (int*)malloc(rows * cols * sizeof(int));
            int *B = (int*)malloc(rows * cols * sizeof(int));
            int *C = (int*)malloc(rows * cols * sizeof(int));

            printf("Enter elements of the first matrix:\n");
            for(int i = 0; i < rows * cols; i++)
                scanf("%d", &A[i]);

            printf("Enter elements of the second matrix:\n");
            for(int i = 0; i < rows * cols; i++)
                scanf("%d", &B[i]);

            point_wise_product(A, B, C, rows, cols);

            printf("Point-wise product result is:\n");
            print_matrix(C, rows, cols);

            free(A);
            free(B);
            free(C);
        }
        else if(choice == '1') {
            int rows1, cols1, rows2, cols2;
            printf("Enter number of rows and columns for the first matrix: ");
            scanf("%d %d", &rows1, &cols1);
            printf("Enter number of rows and columns for the second matrix: ");
            scanf("%d %d", &rows2, &cols2);

            if(cols1 != rows2) {
                printf("Error: Matrix dimensions don't match for matrix multiplication!\n");
                continue;
            }

            int *A = (int*)malloc(rows1 * cols1 * sizeof(int));
            int *B = (int*)malloc(rows2 * cols2 * sizeof(int));
            int *C = (int*)malloc(rows1 * cols2 * sizeof(int));

            printf("Enter elements of the first matrix:\n");
            for(int i = 0; i < rows1 * cols1; i++)
                scanf("%d", &A[i]);

            printf("Enter elements of the second matrix:\n");
            for(int i = 0; i < rows2 * cols2; i++)
                scanf("%d", &B[i]);

            matrix_product(A, B, C, rows1, cols1, cols2);

            printf("Matrix product result is:\n");
            print_matrix(C, rows1, cols2);

            free(A);
            free(B);
            free(C);
        }
    }
    return 0;
}
