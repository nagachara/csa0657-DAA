#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int** allocateMatrix(int size) {
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
    }
    return matrix;
}

// Function to free the allocated memory for a matrix
void freeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to add two matrices
void addMatrix(int** A, int** B, int** C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subMatrix(int** A, int** B, int** C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to perform Strassen's Matrix Multiplication
void strassen(int** A, int** B, int** C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int** A11 = allocateMatrix(newSize);
    int** A12 = allocateMatrix(newSize);
    int** A21 = allocateMatrix(newSize);
    int** A22 = allocateMatrix(newSize);
    int** B11 = allocateMatrix(newSize);
    int** B12 = allocateMatrix(newSize);
    int** B21 = allocateMatrix(newSize);
    int** B22 = allocateMatrix(newSize);
    int** C11 = allocateMatrix(newSize);
    int** C12 = allocateMatrix(newSize);
    int** C21 = allocateMatrix(newSize);
    int** C22 = allocateMatrix(newSize);
    int** M1 = allocateMatrix(newSize);
    int** M2 = allocateMatrix(newSize);
    int** M3 = allocateMatrix(newSize);
    int** M4 = allocateMatrix(newSize);
    int** M5 = allocateMatrix(newSize);
    int** M6 = allocateMatrix(newSize);
    int** M7 = allocateMatrix(newSize);
    int** tempA = allocateMatrix(newSize);
    int** tempB = allocateMatrix(newSize);

    // Dividing the matrices into sub-matrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculating M1 to M7
    addMatrix(A11, A22, tempA, newSize);
    addMatrix(B11, B22, tempB, newSize);
    strassen(tempA, tempB, M1, newSize);

    addMatrix(A21, A22, tempA, newSize);
    strassen(tempA, B11, M2, newSize);

    subMatrix(B12, B22, tempB, newSize);
    strassen(A11, tempB, M3, newSize);

    subMatrix(B21, B11, tempB, newSize);
    strassen(A22, tempB, M4, newSize);

    addMatrix(A11, A12, tempA, newSize);
    strassen(tempA, B22, M5, newSize);

    subMatrix(A21, A11, tempA, newSize);
    addMatrix(B11, B12, tempB, newSize);
    strassen(tempA, tempB, M6, newSize);

    subMatrix(A12, A22, tempA, newSize);
    addMatrix(B21, B22, tempB, newSize);
    strassen(tempA, tempB, M7, newSize);

    // Calculating C11, C12, C21, C22
    addMatrix(M1, M4, tempA, newSize);
    subMatrix(tempA, M5, tempB, newSize);
    addMatrix(tempB, M7, C11, newSize);

    addMatrix(M3, M5, C12, newSize);

    addMatrix(M2, M4, C21, newSize);

    addMatrix(M1, M3, tempA, newSize);
    subMatrix(tempA, M2, tempB, newSize);
    addMatrix(tempB, M6, C22, newSize);

    // Combining sub-matrices into the result matrix C
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    // Freeing the allocated memory
    freeMatrix(A11, newSize);
    freeMatrix(A12, newSize);
    freeMatrix(A21, newSize);
    freeMatrix(A22, newSize);
    freeMatrix(B11, newSize);
    freeMatrix(B12, newSize);
    freeMatrix(B21, newSize);
    freeMatrix(B22, newSize);
    freeMatrix(C11, newSize);
    freeMatrix(C12, newSize);
    freeMatrix(C21, newSize);
    freeMatrix(C22, newSize);
    freeMatrix(M1, newSize);
    freeMatrix(M2, newSize);
    freeMatrix(M3, newSize);
    freeMatrix(M4, newSize);
    freeMatrix(M5, newSize);
    freeMatrix(M6, newSize);
    freeMatrix(M7, newSize);
    freeMatrix(tempA, newSize);
    freeMatrix(tempB, newSize);
}

// Function to print a matrix
void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size;

    printf("Enter the size of the matrix (must be a power of 2): ");
    scanf("%d", &size);

    int** A = allocateMatrix(size);
    int** B = allocateMatrix(size);
    int** C = allocateMatrix(size);

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(A, B, C, size);

    printf("Resultant matrix:\n");
    printMatrix(C, size);

    freeMatrix(A, size);
    freeMatrix(B, size);
    freeMatrix(C, size);

    return 0;
}
