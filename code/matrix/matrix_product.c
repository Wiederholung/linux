#include "matrix_product.h"

int matrix_product(int* A, int* B, int* C, int rows1, int cols1, int cols2) {
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            C[i * cols2 + j] = 0;
            for(int k = 0; k < cols1; k++) {
                C[i * cols2 + j] += A[i * cols1 + k] * B[k * cols2 + j];
            }
        }
    }
    return 0;
}
