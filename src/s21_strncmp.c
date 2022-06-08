#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    if ((int)n == 0) return 0;
    int i = 0;
    while (--n && *((char*)str1 + i) == *((char*)str2 + i)) i++;
    return *((char *)str1 + i) - *((char *)str2 + i);
}
