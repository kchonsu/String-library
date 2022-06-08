#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
    int len = s21_strlen(str), i = 0;
    for (; i < (int)n; i++) {
        *((char*)str + i) = c;
    }
    if (len < (int)n) {
        *((char*)str + i) = '\0';
    }
    return str;
}
