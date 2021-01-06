#include "way_home.h"

void mx_error_exit_point_cannot_be_an_obstacle() {
    mx_printerr("exit point cannot be an obstacle\n");

    exit(0);
}
