#include <stdio.h>
#include "utils.h"
#include "hasse.h"
#include "matrix.h"

int main(void)
{

    const char *inputFile = "../data/Matrice_Projet.txt";

    printf("* Reading graph ...\n");
    adj_list g = readGraph(inputFile);
    if (g.lists == NULL || g.size == 0) {
        printf("Error on reading the graph\n");
        return 1;
    }

    printf("* Generation of the file Mermaid ...\n");
    exportMermaid(&g, "matrix_mermaid.txt");


    printf("* Matrix creation ...\n");
    float ** matrix = create_matrix(g);
    float ** matrix2 = copy_matrix(matrix, g.size);
    float ** initStateMat = initialize_matrix(g.size);
    initStateMat[0][1] = 1;
    print_matrix(matrix, g.size);

    printf("|");
    for (int i = 0; i<g.size; i++) printf(" %.2f ", initStateMat[0][i]);
    printf(" |\n");

    printf("\n* After n=1:\n");
    float ** resmat = multiply_matrix(initStateMat,matrix2,g.size);

    printf("|");
    for (int i = 0; i<g.size; i++) printf(" %.2f ", resmat[0][i]);
    printf(" |\n--------------------");

    printf("\n* After n=2:\n");

    for (int i=0; i<1; i++) {
        matrix2 = multiply_matrix(matrix2,matrix,g.size);
    }

    resmat = multiply_matrix(initStateMat,matrix2,g.size);

    printf("|");
    for (int i = 0; i<g.size; i++) printf(" %.2f ", resmat[0][i]);
    printf(" |\n");

    printf("\n* After n=10:\n");

    for (int i=0; i<10; i++) {
        matrix2 = multiply_matrix(matrix2,matrix,g.size);
    }

    resmat = multiply_matrix(initStateMat,matrix2,g.size);

    printf("|");
    for (int i = 0; i<g.size; i++) printf(" %.4f ", resmat[0][i]);
    printf(" |\n");

    printf("\n* After n=50:\n");

    for (int i=0; i<50; i++) {
        matrix2 = multiply_matrix(matrix2,matrix,g.size);
    }

    resmat = multiply_matrix(initStateMat,matrix2,g.size);

    printf("|");
    for (int i = 0; i<g.size; i++) printf(" %.4f ", resmat[0][i]);
    printf(" |\n");

    free_matrix(matrix,g.size);
    free_matrix(matrix2,g.size);
    free_adj_list(&g);


    return 0;

}