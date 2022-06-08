#include "s21_string.h"

void* s21_memcpy(void* dest, const void* src, s21_size_t n) {
    for (int i = 0; i < (int)n; ++i)
        *((char*)dest + i) = *((char*)src + i);
    return (char*)dest;
}
