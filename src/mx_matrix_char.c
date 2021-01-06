#include "way_home.h"

char **mx_matrix_char(char *result, int *row, int *column) {
    int i;
    int n = 0;
    int m = 0;

    for (i = 0; result[i] != '\0'; i++) {
        if (result[i] == '\n') {
            m++;
        }
    }

    n = (i - m) / m;

    char **result_x2 = (char **)malloc(m * 8);

    for (i = 0; i < m; i++) {
        result_x2[i] = mx_strnew(n);
    }

    for (i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                if (result[j] == '#') {
                    result_x2[i][j] = '#';
                }
                else if (result[j] == '.') {
                    result_x2[i][j] = '.';
                }
                else if (result[j] != ',' && result[j] != '\n') {
                    mx_printerr("map error\n");

                    exit(0);
                }
            }
            else {
                if (result[j + i * (n + 1)] == '#') {
                    result_x2[i][j] = '#';
                }
                else if (result[j + i * (n + 1)] == '.') {
                    result_x2[i][j] = '.';
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
