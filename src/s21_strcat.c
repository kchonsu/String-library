#include "s21_string.h"

char* s21_strcat(char* dest, const char* src) {
    int dest_len;
    dest_len = s21_strlen(dest);
    for (int i = 0; src[i]; i++) {
        dest[dest_len] = src[i];
        dest_len++;
    }
    dest[dest_len] = '\0';
    return dest;
}
