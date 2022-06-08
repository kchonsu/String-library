#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *nstr = s21_NULL;
    if (src && str && s21_strlen(src) >= start_index) {
        nstr = (char *)malloc((s21_strlen(src) + s21_strlen(str) + 1) *
                                 sizeof(char));
        if (nstr) {
            s21_strncpy(nstr, src, start_index);
            *(nstr + start_index) = '\0';
            s21_strcat(nstr, str);
            s21_strcat(nstr, src + start_index);
        }
    }
    return (void *)nstr;
}
