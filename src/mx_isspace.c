#include "way_home.h"

bool mx_isspace(char c) {
	if (c == 32 || (c >= 9 && c <= 13)) {
		return 1;
	}

	return 0;
}
