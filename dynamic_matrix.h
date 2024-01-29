#ifndef DYNAMIC_MATRIX_H
#define DYNAMIC_MATRIX_H

#include <stddef.h>

typedef struct {
    void ***data;  // Pointer to a 2D array of void pointers
    size_t rows;
    size_t cols;
} DynamicMatrix;

// Function prototypes
extern DynamicMatrix* CreateDynamicMatrix(size_t rows, size_t cols);
extern void DestroyDynamicMatrix(DynamicMatrix *matrix);

extern void SetElement(DynamicMatrix *matrix, void *data, size_t row, size_t col);
extern void* GetElement(const DynamicMatrix *matrix, size_t row, size_t col);

extern size_t GetRows(const DynamicMatrix *matrix);
extern size_t GetCols(const DynamicMatrix *matrix);

#endif

