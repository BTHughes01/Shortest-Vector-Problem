#ifndef BRUTE_FORCE_SOLVE_H
#define BRUTE_FORCE_SOLVE_H

/**
 * @brief computes the shortest vector from 2 2D basis vectors.
 *
 * This function recursively calculates the shortest vector formed by two input vectors
 * within a given vector space definied by the search_resolution.
 *
 * @param vector_1 The first input vector.
 * @param vector_2 The second input vector.
 * @param search_resolution The resolution for the brute-force search.
 * @return The shortest vector formed by the 2 basis vectors.
 */
double brute_force_2D(double* vector_1, double* vector_2, int search_resolution);

/**
 * @brief Recursively searches for the shortest vector.
 *
 * This function recursively searches for the shortest vector within a given vector space definied by the search_resolution.
 *
 * @param basis The basis vectors.
 * @param dimension The dimension of the vector space.
 * @param search_resolution The resolution for the brute-force search.
 * @param depth The current recursion depth.
 * @param current_vector The current vector being explored.
 * @param shortest_length The shortest length found so far.
 */
void brute_force_recursive(double** basis, int dimension, int search_resolution, int depth, double* current_vector, double* shortest_length);

/**
 * @brief finds the shortest vector using recursion.
 *
 * This function recursively searches for the shortest vector within a given vector space definied by the search_resolution
 * by recursively calling the function brute_force_recursive.
 *
 * @param basis The basis vectors.
 * @param dimension The dimension of the vector space.
 * @param search_resolution The resolution for the brute-force search.
 * @return The computed result.
 */
double brute_force(double** basis, int dimension, int search_resolution);

#endif /* BRUTE_FORCE_SOLVE_H */
