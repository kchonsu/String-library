#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
    for (; *str1 == *str2 && *str1 && *str2; str1++, str2++)
    continue;
    return (int)*str1 - (int)*str2;
}
