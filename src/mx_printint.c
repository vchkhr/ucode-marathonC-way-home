#include "way_home.h"

void mx_printint(int n) {
    int count = 0;
    int number = n;
    int degree = 1;

    if (n < 0) {
        mx_printchar('-');
        n = n * (-1);
        number = n;
    }
    if (n == 0) {
        mx_printchar('0');
    }

    for (; n != 0; count++) {
        n /= 10;
    }
    for (int i = 1; i < count; i++) {
        degree *= 10;
    }

    for (; number > 0; count--) {
        int digit = number / degree + 48;
        mx_printchar(digit);
        
        number %= degree;
        degree /= 10;
    }
    for (; count; count--) {
        mx_printchar('0');
    }
}
