#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    char *tmp = s21_NULL;
    for (int i = 0; haystack[i] && tmp == s21_NULL; i++) {
        for (int j = 0; needle[j]; j++) {
            if (haystack[i] != needle[j]) {
                break;
            } else {
                if (needle[j + 1] == '\0') {
                    tmp = (char *) haystack + (i - s21_strlen(needle) + 1);
                    break;
                }
                i++;
            }
        }
    }
    if (needle[0] == '\0') {
        tmp = (char *)haystack;
    }
    return tmp;
}
