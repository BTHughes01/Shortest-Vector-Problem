#ifndef LLL_SOLVE_H
#define LLL_SOLVE_H

/**
 * @brief Computes the Gram-Schmidt coefficient of the two given vectors.
 *
 * This function calculates the Gram-Schmidt coefficient of the two input vectors.
 * The first vector is expected to be the basis, and the second vector is the orthogonal vector.
 *
 * @param vector_1 The basis input vector.
 * @param vector_2 The orthogonal input vector.
 * @param dimension The dimension of the two vectors.
 * @return The Gram-Schmidt coefficient.
 */
double gram_schmidt_coefficient(double* vector_1, double* vector_2, int dimension);

/**
 * @brief Orthogonalizes a set of basis vectors using the Gram-Schmidt process.
 *
 * This function applies the Gram-Schmidt process to orthogonalize a set of basis vectors.
 *
 * @param basis a basis which will be orthoganlised.
 * @param dimension The dimension of the vector space.
 */
void orthagonalize(double** basis, int dimension);

/**
 * @brief Finds the shortest vector among a set of basis vectors.
 *
 * This function calculates the shortest vector length among a set of basis vectors.
 *
 * @param basis The set of basis vectors.
 * @param dimension The dimension of the vectors.
 * @return The length of the shortest basis vector.
 */
double find_shortest_basis_vector(double** basis, int dimension);

/**
 * @brief Solves the LLL lattice reduction problem for a set of basis vectors.
 *
 * This function implements the LLL lattice reduction algorithm for a given set of basis vectors.
 *
 * @param basis The set of basis vectors.
 * @param dimension The dimension of the vector space.
 * @param delta A parameter controlling the lattice reduction process.
 * @return The success indicator for LLL lattice reduction.
 */
double LLL_solve(double** basis, int dimension, float delta);

#endif /* LLL_SOLVE_H */
