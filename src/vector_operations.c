#include <math.h>
#include "vector_operations.h"

double inner_product(double* vector_1, double* vector_2, int dimension) {
    //calculating the inner product
    double sum = 0;
    for(int i = 0; i < dimension; i++) {
        sum += vector_1[i] * vector_2[i];
    }
    return sum;
}

double cartesian_length(double* vector, int dimension) {
    //returning the square root of the inner product with itself
    return sqrt(inner_product(vector, vector, dimension));
}
