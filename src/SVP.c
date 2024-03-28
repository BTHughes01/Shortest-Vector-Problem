#include "print_functions.h"
#include "vector_operations.h"
#include "brute_force_solve.h"
#include "LLL_solve.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char *argv[]){

    int dimension = 0;

    //making sure that there is a square number of arguments so the basis is square
    float args_root = sqrt(argc);
    if(args_root == floor(args_root)){
        printf("\nERROR: wrong number of arguments, basis should be square");
        return EXIT_FAILURE;
    };
    dimension = (int)args_root;

    //making sure every vector opens with a [ and closes with a ]
    for(int position = 1; position < argc-1; position += dimension){
        if(argv[position][0] != '['){
            printf("\nINPUT ERROR: vector was not opened correctly in argument #%d %s",position,argv[position]);
            return EXIT_FAILURE;
        }
        else if(argv[position + dimension-1][strlen(argv[position+dimension-1])-1] != ']'){
            printf("\nINPUT ERROR: vector was not closed correctly in argument #%d %s",position + dimension-1,argv[position + dimension-1]);
            return EXIT_FAILURE;
        }

        //removing the brackets
        argv[position][0] = ' ';
        argv[position + dimension-1][strlen(argv[position+dimension-1])-1] = ' ';
        
    }

    //making sure only one dot
    for(int i = 1; i < argc; i++){
        size_t dot_count = 0;
        for(size_t j = 0; j < strlen(argv[i]); j++)
        if(argv[i][j] == '.'){
            dot_count++;
        }
        if(dot_count > 1){
            printf("\nERROR: Too many dots in argument: %d %s",i,argv[i]);
            return EXIT_FAILURE;
        }
    }

    //making sure all input arguments are only numbers with . in between
    for(int i = 1; i < argc; i++){      
        //going through each char and making sure it is a digit or there is only one .
        size_t j = 0;
        while( j < strlen(argv[i])){
            //if first or last char is empty then pass
            if((j==0 || j == strlen(argv[i])-1) && argv[i][j] == ' '){
                j++;
                //if next car is - then pass
                if(argv[i][j] == '-'){
                    j++;
                }
            }
            //if first char is - then pass
            else if (j==0 && argv[i][j] == '-'){
                j++;
            }
            //if char is not digit or is a .
            else if(isdigit(argv[i][j]) == 0 && argv[i][j] != '.'){
                printf("ERROR: foreign character %c in argument %s",argv[i][j],argv[i]);
                return EXIT_FAILURE;
            }
            else{
                j++;
            }
            
        }
    }

    //create a structure basis which is a pointer to an array of pointers to arrays representing the vectors
    double **basis = (double **)malloc(dimension * sizeof(double *));

    //creating the vectors that the basis points to
    for (int i = 0; i < dimension; ++i) {
        basis[i] = (double *)malloc(dimension * sizeof(double));
        //filling the vectors with the arguments from the command line
        for (int j = 0; j < dimension; ++j) {
            //inserting the argv into the basis matrix
            basis[i][j] = atof(argv[i*dimension+j+1]);
        }
    }

    //using LLL to solve
    double delta = 0.99;
    double result = LLL_solve(basis,dimension,delta);

    //printing the answer to a file
    FILE *file = fopen("result.txt", "w");
    fprintf(file, "%lf",result);
    fclose(file);

    //Free the dynamically allocated memory
    for (int i = 0; i < dimension; ++i) {
        free(basis[i]);
    }

    free(basis);

    return EXIT_SUCCESS;
}