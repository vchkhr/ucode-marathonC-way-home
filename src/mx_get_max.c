#include "way_home.h"

int mx_get_max(int **matrix, int size_n, int size_m, int row, int column,
               char **matrix_2) {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool stop = false;
    int max;

    matrix[size_m][size_n] = 0;

    for (int d = 0, flag = 1; !stop || flag; d++, flag = 0) {
        stop = true;

        for (int y = 0; y < row; y++) {
            for (int x = 0; x < column; x++) {
                if (matrix[y][x] == d) {
                    for (int k = 0; k < 4; k++) {
                        int iy = y + dy[k], ix = x + dx[k];

                        if (iy >= 0 && iy < row && ix >= 0 && ix < column &&
                            matrix[iy][ix] == -2) {
                            stop = false;
                            matrix[iy][ix] = d + 1;
                        }
                    }
                }
            }
        }
    }

    max = matrix[0][0];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (matrix[i][j] == max) {
                if (matrix_2[i][j] == '*') {
                    matrix_2[i][j] = 'X';
                }
                else {
                    matrix_2[i][j] = 'D';
                }
            }
        }
    }

    return max;
}
