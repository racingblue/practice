#include <stdio.h>
#include <stdlib.h>

void read_matrix(int **matrix, int rows, int cols) {
   // printf("Enter values for %d x %d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

  //  printf("Enter number of rows : ");
    scanf("%d", &rowsA);
    //printf("Enter number of columns : ");
    scanf("%d", &colsA);

    int **A = (int **)malloc(rowsA * sizeof(int *));
    for (int i = 0; i < rowsA; i++) {
        A[i] = (int *)malloc(colsA * sizeof(int));
    }
    read_matrix(A, rowsA, colsA);

    //printf("Enter number of rows : ");
    scanf("%d", &rowsB);
    //printf("Enter number of columns : ");
    scanf("%d", &colsB);

    if (colsA != rowsB) {
        printf("Matrix multiplication is not possible\n");
        for (int i = 0; i < rowsA; i++) {
            free(A[i]);
        }
        free(A);
        return 1;
    }

    int **B = (int **)malloc(rowsB * sizeof(int *));
    for (int i = 0; i < rowsB; i++) {
        B[i] = (int *)malloc(colsB * sizeof(int));
    }
    read_matrix(B, rowsB, colsB);

    int **R = (int **)malloc(rowsA * sizeof(int *));
    for (int i = 0; i < rowsA; i++) {
        R[i] = (int *)malloc(colsB * sizeof(int));
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            R[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Product of two matrix :\n");
    print_matrix(R, rowsA, colsB);

    for (int i = 0; i < rowsA; i++) {
        free(A[i]);
        free(R[i]);
    }
    for (int i = 0; i < rowsB; i++) {
        free(B[i]);
    }
    free(A);
    free(B);
    free(R);

    return 0;
}

