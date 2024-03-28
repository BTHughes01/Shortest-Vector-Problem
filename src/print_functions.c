#include <stdio.h>
#include "print_functions.h"

void print_matrix(double** matrix, int dimension) {
    //going through and printing each vector on a new line
    for (int i = 0; i < dimension; ++i) {
        printf("\n");
        for (int j = 0; j < dimension; ++j) {
            printf("%.3lf ", matrix[i][j]);
        }
    }
}

void print_vector(double* vector, int dimension) {
    //printing each number of the vector on a new line
    for (int i = 0; i < dimension; ++i) {
        printf("\n%f", vector[i]);
    }
}
