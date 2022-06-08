#include "s21_string.h"

void s21_itoa(int n, char *str) {
    int i = 0;
    long int x = n;
    if (n < 0) x *= -1;
    if (!x) str[i++] = '0';
    while (x > 0) {
        str[i] = x % 10 + '0';
        i++;
        x /= 10;
    }
    if (n < 0) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    reverse(str);
}
