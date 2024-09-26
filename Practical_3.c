#include <stdio.h>
#include <stdlib.h>

void input_matrix(int **matrix, int size) {
    printf("Enter elements of the %dx%d matrix:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int **matrix, int size) {
    printf("Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **allocate_matrix(int size) {
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }
    return matrix;
}


void free_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void multiply_matrices(int **A, int **B, int **C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int size = 3;

    int **A = allocate_matrix(size);
    int **B = allocate_matrix(size);
    int **C = allocate_matrix(size);

    printf("Matrix A:\n");
    input_matrix(A, size);

    printf("\nMatrix B:\n");
    input_matrix(B, size);

    multiply_matrices(A, B, C, size);

    printf("\nMatrix A:\n");
    print_matrix(A, size);

    printf("\nMatrix B:\n");
    print_matrix(B, size);

    printf("\nResultant Matrix C (A * B):\n");
    print_matrix(C, size);

    free_matrix(A, size);
    free_matrix(B, size);
    free_matrix(C, size);

    return 0;
}
