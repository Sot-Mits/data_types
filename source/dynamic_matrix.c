#include <stdlib.h>

typedef struct {
    void ***data;  // Pointer to a 2D array of void pointers
    size_t rows;
    size_t cols;
} DynamicMatrix;

DynamicMatrix* CreateDynamicMatrix(size_t rows, size_t cols) {
    DynamicMatrix *matrix = malloc(sizeof(DynamicMatrix));
    if (matrix) {
        matrix->rows = rows;
        matrix->cols = cols;

        // Allocate memory for the 2D array
        matrix->data = malloc(rows * sizeof(void**));
        for (size_t i = 0; i < rows; i++) {
            matrix->data[i] = malloc(cols * sizeof(void*));
        }

        // Initialize matrix elements to NULL
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                matrix->data[i][j] = NULL;
            }
        }
    }
    return matrix;
}

void DestroyDynamicMatrix(DynamicMatrix *matrix) {
    // Free memory for each row
    for (size_t i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }

    // Free memory for the array of rows
    free(matrix->data);

    // Free memory for the matrix structure
    free(matrix);
}

void SetElement(DynamicMatrix *matrix, void *data, size_t row, size_t col) {
    if (row < matrix->rows && col < matrix->cols) {
        matrix->data[row][col] = data;
    }
}

void* GetElement(const DynamicMatrix *matrix, size_t row, size_t col) {
    if (row < matrix->rows && col < matrix->cols) {
        return matrix->data[row][col];
    }
    return NULL;
}

size_t GetRows(const DynamicMatrix *matrix) {
    return matrix->rows;
}

size_t GetCols(const DynamicMatrix *matrix) {
    return matrix->cols;
}

