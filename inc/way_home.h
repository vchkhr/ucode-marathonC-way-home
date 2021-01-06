#ifndef WAY_HOME_H
#define WAY_HOME_H

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

bool mx_get_path(int **matrix, int size_n, int size_m, int row, int column, int He, int Wi, int *length, int *path_n, int *path_m);
bool mx_isdigit(int c);
bool mx_isspace(char c);
char **mx_matrix_char(char *result, int *row, int *column);
char *mx_file_to_str(const char *file_name);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
int **mx_matrix_int(char *result, int *row, int *column);
int mx_atoi(const char *str);
int mx_get_max(int **matrix, int size_n, int size_m, int row, int column, char **matrix_2);
int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);
void mx_error_entry_point_cannot_be_an_obstacle();
void mx_error_exit_point_cannot_be_an_obstacle();
void mx_error_map_does_not_exist();
void mx_error_map_error();
void mx_error_points_are_out_of_map_range();
void mx_error_route_not_found();
void mx_error_usage();
void mx_printchar(char c);
void mx_printerr(const char *s);
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_strdel(char **str);

#endif
