#include "way_home.h"

bool mx_get_path(int **matrix, int size_n, int size_m, int row, int column,
                 int He, int Wi, int *length, int *path_n, int *path_m) {

	if (matrix[size_m][size_n] == -1) {
		mx_error_entry_point_cannot_be_an_obstacle();
	}
	if (matrix[column][row] == -1) {
		mx_error_exit_point_cannot_be_an_obstacle();
	}

	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, -1, 0, 1};
	bool stop;

	matrix[size_m][size_n] = 0;

	for (int d = 0; true; d++) {
		stop = true;

		for (int y = 0; y < He; y++) {
			for (int x = 0; x < Wi; x++) {
				if (matrix[y][x] == d) {
					for (int k = 0; k < 4; k++) {
						int iy = y + dy[k], ix = x + dx[k];

						if (iy >= 0 && iy < He && ix >= 0 && ix < Wi &&
						    matrix[iy][ix] == -2) {
							stop = false;
							matrix[iy][ix] = d + 1;
						}
					}
				}
			}
		}

		if (stop || matrix[column][row] != -2) {
			break;
		}
	}

	if (matrix[column][row] == -2) {
		return false;
	}

	*length = matrix[column][row];

	int x = row;
	int y = column;
	int d = *length;

	for (; d > 0;) {
		path_n[d] = x;
		path_m[d] = y;
		d--;

		for (int k = 0; k < 4; k++) {
			int iy = y + dy[k], ix = x + dx[k];

			if (iy >= 0 && iy < He && ix >= 0 && ix < Wi &&
			    matrix[iy][ix] == d) {
				x = x + dx[k];
				y = y + dy[k];

				break;
			}
		}
	}

	path_n[0] = size_n;
	path_m[0] = size_m;

	return true;
}
