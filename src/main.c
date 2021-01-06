#include "way_home.h"

int main(int argc, char const *argv[]) {
    if (argc != 6) {
        mx_error_usage();
    }

    int file = open(argv[1], O_RDONLY);

    if (file < 0)  {
        mx_error_map_does_not_exist();
    }

    char buffer[1];
    int number = read(file, buffer, 4);

    if (number <= 0) {
        mx_error_map_does_not_exist();
    }

    int row;
    int column;
    int length;
    int n1 = mx_atoi(argv[2]), x2 = mx_atoi(argv[4]);
    int m1 = mx_atoi(argv[3]), y2 = mx_atoi(argv[5]);
    char *string = mx_file_to_str(argv[1]);
    int **matrix_1 = mx_matrix_int(string, &row, &column);
    char **matrix_2 = mx_matrix_char(string, &row, &column);
    int **matrix_3 = mx_matrix_int(string, &row, &column);

    if (n1 >= column || x2 >= column || n1 < 0 || x2 < 0 || m1 < 0 || y2 < 0 ||
        m1 >= row || y2 >= row) {
        mx_error_points_are_out_of_map_range();
    }

    int n2[row * column];
    int m2[row * column];

    if (!mx_get_path(matrix_1, n1, m1, x2, y2, row, column, &length, n2, m2)) {
        mx_error_route_not_found();
    }

    int file_result = open("path.txt", O_WRONLY);

    if (file_result < 0) {
        file_result = open("path.txt", O_CREAT | O_WRONLY);
    }

    for (int i = 0; i < length; i++) {
        matrix_2[m2[i]][n2[i]] = '*';
    }

    matrix_2[y2][x2] = '*';
    mx_get_max(matrix_3, n1, m1, row, column, matrix_2);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            char buffer = matrix_2[i][j];

            write(file_result, &buffer, 1);
        }

        write(file_result, "\n", 1);
    }

    if (close(file_result) < 0) {
        mx_error_map_error();
    }

    mx_printstr("dist=");
    mx_printint(mx_get_max(matrix_3, n1, m1, row, column, matrix_2));
    mx_printstr("\n");
    mx_printstr("exit=");
    mx_printint(length);
    mx_printstr("\n");

    return 0;
}
