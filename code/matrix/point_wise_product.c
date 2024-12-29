#include "point_wise_product.h"

int point_wise_product(int* A, int* B, int* C, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            C[i * cols + j] = A[i * cols + j] * B[i * cols + j];
        }
    }
    return 0;
}
