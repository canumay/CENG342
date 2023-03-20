#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Run the program with following values: %s <rows> <cols> <output_file>\n", argv[0]);
        return 1;
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    char *output_file = argv[3];

    srand(1705011016);

    double **matrix = (double **) malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double *) malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = ((double) rand() / RAND_MAX) * 99.0 + 1.0; 
        }
    }

    double *vector = (double *) malloc(cols * sizeof(double));
    for (int i = 0; i < cols; i++) {
        vector[i] = ((double) rand() / RAND_MAX) * 99.0 + 1.0;
    }

    double *result = (double *) calloc(rows, sizeof(double));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    FILE *file = fopen(output_file, "w");
    if (file == NULL) {
        printf("Error: Unable to open output file!\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        fprintf(file, "%.2f\n", result[i]);
    }
    fclose(file);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(vector);
    free(result);

    return 0;
}
