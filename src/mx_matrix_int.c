#include "way_home.h"

int **mx_matrix_int(char *result, int *row, int *column) {
    int i;
    int n = 0;
    int m = 0;

    for (i = 0; result[i] != '\0'; i++) {
        if (result[i] == '\n') {
            m++;
        }
    }

    n = (i - m) / m;

    int **result_x2 = (int **)malloc(m * 8);

    for (i = 0; i < m; i++) {
        result_x2[i] = (int *)malloc(n * 4);
    }

    for (i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                if (result[j] == '#') {
                    result_x2[i][j] = -1;
                }
                else if (result[j] == '.') {
                    result_x2[i][j] = -2;
                }
                else if (result[j] != ',' && result[j] != '\n') {
                    mx_printerr("map error\n");

                    exit(0);
                }
            }
            else {
                if (result[j + i * (n + 1)] == '#') {
                    result_x2[i][j] = -1;
                }
                else if (result[j + i * (n + 1)] == '.') {
                    result_x2[i][j] = -2;
                }
                else if (result[j + i * (n + 1)] != ',' &&
                         result[j + i * (n + 1)] != '\n') {
                    mx_printerr("map error\n");
                    
                    exit(0);
                }
            }
        }
    }

    *column = n;
    *row = m;

    return result_x2;
}
