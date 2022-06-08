#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
    char *new_str = s21_NULL;
    if (src && trim_chars) {
        char *ptr_str = (char *)src;
        char *end_str = (char *)src + s21_strlen(src);
        for (; *ptr_str && s21_strchr(trim_chars, *ptr_str); ptr_str++) {
        }
        for (; end_str != ptr_str && s21_strchr(trim_chars, *(end_str - 1));
             end_str--) {
        }
        new_str = (char *)malloc((end_str - ptr_str + 1) * sizeof(char));
        if (new_str) {
            s21_strncpy(new_str, ptr_str, end_str - ptr_str);
            *(new_str + (end_str - ptr_str)) = '\0';
        }
    }
    return (void *)new_str;
}
