#include "s21_string.h"

void *s21_to_lower(const char *str) {
    char* string;
    if (str != s21_NULL) {
        int len_str = s21_strlen(str) + 1;
        int i = 0;
        string = (char*) calloc(len_str, sizeof(char));
        while (i < len_str) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                string[i] = str[i] + 32;
            } else {
                string[i] = str[i];
            }
            i++;
        }
    } else {
        string = s21_NULL;
    }
    return string;
}
