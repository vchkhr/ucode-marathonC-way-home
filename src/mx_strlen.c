#include "way_home.h"

int mx_strlen(const char *s) {
    if (!s) {
        return 0;
    }

    int i = 0;

    for (; s[i];) {
        i++;
    }

    return i;
}
