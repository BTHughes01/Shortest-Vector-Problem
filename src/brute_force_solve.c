#include <stdio.h>
#include <stdlib.h>
#include "vector_operations.h"
#include "brute_force_solve.h"

double brute_force_2D(double* vector_1, double* vector_2, int search_resolution) {
    double shortest_length = cartesian_length(vector_1, 2);
    double current_length;
    double current_vector[2];

    //searching through all the vectors within a given space
    for (int i = -search_resolution; i <= search_resolution; i++) {
        for (int j = -search_resolution; j <= search_resolution; j++) {
            if (i != 0 || j != 0) {

                //the current vector to test
                current_vector[0] = vector_1[0] * i + vector_2[0] * j;
                current_vector[1] = vector_1[1] * i + vector_2[1] * j;

                //seeing if the current vector is closer than the shortest so far and swapping
                current_length = cartesian_length(current_vector, 2);
                if (current_length < shortest_length) {
                    shortest_length = current_length;
                }
            }
        }
    }

    return shortest_length;
}

void brute_force_recursive(double** basis, int dimension, int search_resolution, int depth, double* current_vector, double* shortest_length) {
    //basis case
    if (dimension == depth) {
        //calculating the length of the current vector
        double vector_length = cartesian_length(current_vector, dimension);

        //if the current vector length is shorter than the shortest then replace
        if (vector_length > 0.00001 && vector_length < *shortest_length) {
            *shortest_length = vector_length;
        }
    } else {
        for (int i = -search_resolution; i <= search_resolution; i++) {
            //multiply the vector and add to the sum then recurse
            //adding the multiple of the vector to the current vector
            for (int j = 0; j < dimension; j++) {
                current_vector[j] += i * basis[depth][j];
            }

            brute_force_recursive(basis, dimension, search_resolution, depth + 1, current_vector, shortest_length);

            for (int j = 0; j < dimension; j++) {
                current_vector[j] -= i * basis[depth][j];
            }
        }
    }
}

double brute_force(double** basis, int dimension, int search_resolution) {
    //a variable to hold the value for the shortest vector
    double shortest_vector = __DBL_MAX__;

    //an array to hold the current vector
    double* current_vector = (double*)malloc(dimension * sizeof(double));
    brute_force_recursive(basis, dimension, search_resolution, 0, current_vector, &shortest_vector);
    free(current_vector);
    return shortest_vector;
}
