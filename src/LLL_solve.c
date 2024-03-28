#include <stdio.h>
#include <stdlib.h>  //Include for malloc function
#include <math.h>    //Include for fabs and round functions
#include "vector_operations.h"  //Include for cartesian_length function
#include "LLL_solve.h"
#include "print_functions.h"

double gram_schmidt_coefficient(double* vector_1, double* vector_2, int dimension) {
    return inner_product(vector_1, vector_2, dimension) / inner_product(vector_2, vector_2, dimension);
}

void orthagonalize(double** basis, int dimension) {
    //Orthogonalizing the vectors
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < i; j++) {
            double coefficient = gram_schmidt_coefficient(basis[i], basis[j], dimension);

            //Subtract the projection of basis[i] onto basis[j] from basis[i]
            for (int k = 0; k < dimension; k++) {
                basis[i][k] -= coefficient * basis[j][k];
            }
        }
    }
}

double find_shortest_basis_vector(double** basis, int dimension) {
    double shortest_length = __DBL_MAX__;
    //Performing a linear search to find the shortest vector
    for (int i = 0; i < dimension; i++) {
        double length = cartesian_length(basis[i], dimension);
        if (length < shortest_length) {
            shortest_length = length;
        }
    }
    return shortest_length;
}

double LLL_solve(double** basis, int dimension, float delta) {

    int loopcount = 0;
    //Creating the matrix for the orthogonalized basis B* in the pseudocode
    double** orthogonalized_basis = (double**)malloc(dimension * sizeof(double*));
    for (int i = 0; i < dimension; ++i) {
        orthogonalized_basis[i] = (double*)malloc(dimension * sizeof(double));
        for (int j = 0; j < dimension; ++j) {
            orthogonalized_basis[i][j] = basis[i][j];
        }
    }

    /*
    Implementation of Lattice Basis Reduction using LLL algorithm,
    based on pseudocode from:
    
    Hoffstein, J., Pipher, J., & Silverman, J. H. (2008). 
    An Introduction to Mathematical Cryptography (p. 411, Chapter 6.12: Lattice Reduction Algorithms). 
    With corrections from errata. Silverman, J. 
    (Retrieved 10th Jan 2024). 
    "Introduction to Mathematical Cryptography Errata" (PDF). 
    Brown University Mathematics Dept.
    */
   
    orthagonalize(orthogonalized_basis, dimension);

    int k = 1;
    while (k < dimension && loopcount < 100000) {
        loopcount++;

        for (int j = k - 1; j >= 0; j--) {
            //size reduction
            double current_coefficient = gram_schmidt_coefficient(basis[k], orthogonalized_basis[j], dimension);

            if (fabs(current_coefficient) > 0.5) {
                for (int i = 0; i < dimension; i++) {
                    basis[k][i] = basis[k][i] - round(current_coefficient) * basis[j][i];
                }

                //Updating the orthogonal basis
                for (int i = 0; i < dimension; ++i) {
                    for (int j = 0; j < dimension; ++j) {
                        orthogonalized_basis[i][j] = basis[i][j];
                    }
                }
                orthagonalize(orthogonalized_basis, dimension);
            }
        }

        //lovasz condition
        if (inner_product(orthogonalized_basis[k], orthogonalized_basis[k], dimension) >
            (delta - pow(gram_schmidt_coefficient(basis[k], orthogonalized_basis[k - 1], dimension), 2)) *
                inner_product(orthogonalized_basis[k - 1], orthogonalized_basis[k - 1], dimension)) {
            k += 1;
        } 
        //swap step
        else {
            double* temp = basis[k];
            basis[k] = basis[k - 1];
            basis[k - 1] = temp;

            //Updating the orthogonal basis
            for (int i = 0; i < dimension; ++i) {
                for (int j = 0; j < dimension; ++j) {
                    orthogonalized_basis[i][j] = basis[i][j];
                }
            }
            orthagonalize(orthogonalized_basis, dimension);

            k = ((k - 1) > (1)) ? (k - 1) : (1);
        }
    }

    for (int i = 0; i < dimension; ++i) {
        free(orthogonalized_basis[i]);
    }

    free(orthogonalized_basis);

    return find_shortest_basis_vector(basis,dimension);
}
