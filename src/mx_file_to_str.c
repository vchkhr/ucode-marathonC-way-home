#include "way_home.h"

char *mx_file_to_str(const char *file_name) {
    int file = open(file_name, O_RDONLY);
    char buffer[1];
    int number;
    int count = 0;

    for (int count_in_row_first = 0, count_in_row_this = 0,
         first_line_counting = 1, number = read(file, buffer, 1); number > 0;
         number = read(file, buffer, 1)) {
        if (buffer[0] == '#' || buffer[0] == '.' || buffer[0] == '\n') {
            count++;
        }
        else if (buffer[0] != ',') {
            mx_error_map_error();
        }
        if (buffer[0] != '\n') {
            if (first_line_counting == 1) {
                count_in_row_first += 1;
            }
            else {
                count_in_row_this += 1;
            }
        }
        else {
            if (first_line_counting == 0) {
                if (count_in_row_first != count_in_row_this) {
                    mx_error_map_error();
                }
            }

            count_in_row_this = 0;
            first_line_counting = 0;
        }
    }

    close(file);

    file = open(file_name, O_RDONLY);

    char *result = (char *)malloc(count + 1);

    number = read(file, buffer, 1);

    for (int i = 0; i < count && number > 0; number = read(file, buffer, 1)) {
        if (buffer[0] == '.' || buffer[0] == '#' || buffer[0] == '\n') {
            result[i] = buffer[0];
            i++;
        }
    }

    result[count] = '\0';

    close(file);

    return result;
}
