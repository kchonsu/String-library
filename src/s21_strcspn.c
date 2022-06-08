#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    long i = 0, stop = 1;
    for (; i <= (long)s21_strlen(str1) && stop; i++) {
        for (long j = 0; j <= (long)s21_strlen(str2); j++) {
            if (str1[i] == str2[j]) {
                stop = 0;
                break;
            }
        }
    }
    return (i - 1) * (i != 0);
}
