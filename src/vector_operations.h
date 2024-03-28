#ifndef VECTOR_OPERATIONS_H
#define VECTOR_OPERATIONS_H

/**
 * @brief Computes the inner product of two vectors.
 *
 * This function calculates the inner product of two input vectors.
 *
 * @param vector_1 The first input vector.
 * @param vector_2 The second input vector.
 * @param dimension The dimension of the vectors.
 * @return The computed inner product.
 */
double inner_product(double* vector_1, double* vector_2, int dimension);

/**
 * @brief Calculates the Cartesian length (Euclidean norm) of a vector.
 *
 * This function computes the Cartesian length (Euclidean norm) of a given vector.
 *
 * @param vector The input vector.
 * @param dimension The dimension of the vector.
 * @return The calculated Cartesian length.
 */
double cartesian_length(double* vector, int dimension);

#endif /* VECTOR_OPERATIONS_H */
