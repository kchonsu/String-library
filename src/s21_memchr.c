#include "s21_string.h"

void* s21_memchr(const void *arr, int c, s21_size_t n) {
    char* b;
    int i = 0;
    for (; i < (int)n - 1 && *((char*)arr + i) != c; i++)
    continue;
    if (*((char*)arr + i) == c)
        b = (char*)arr + i;
    else
        b = s21_NULL;
    return (char*)b;
}
