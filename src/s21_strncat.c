#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    int dest_len;
    dest_len = s21_strlen(dest);
    for (int i = 0; i < (int)n && src[i]; i++) {
        dest[dest_len] = src[i];
        dest_len++;
    }
    dest[dest_len] = '\0';
    return dest;
}
