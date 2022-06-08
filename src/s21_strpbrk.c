#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
    char *res = s21_NULL;
    for (; res == s21_NULL && *str1; str1++) {
        for (int i = 0; str2[i]; i++) {
            if (*str1 == str2[i]) {
                res = (char *)str1;
                break;
            }
        }
    }
    return res;
}
