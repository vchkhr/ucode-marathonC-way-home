#include "way_home.h"

char *mx_strnew(const int size) {
    if (size < 0) {
        return NULL;
    }

    char *memory = NULL;
    int i = 0;

    memory = (char *)malloc(size + 1);

    for (; i < size; i++) {
        memory[i] = '\0';
    }

    memory[i] = '\0';

    return memory;
}
