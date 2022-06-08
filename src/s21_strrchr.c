#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
    s21_size_t i;
    char *temp;
    temp = s21_NULL;
    i = s21_strlen(str);
    if ((char)c == '\0' && str[i] == (char)c)
        return ((char *)str + i);
    while (*str) {
         if (*str == (char)c) {
           temp = (char *)str;
        }
        str++;
    }
    return (temp);
}
