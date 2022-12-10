#include "s21_string.h"
#include <stdlib.h>

void *s21_to_upper(const char *str) {
    char *res = S21_NULL;
    if (str != S21_NULL) {
        s21_size_t len = s21_strlen(str);
        res = (char *)malloc(sizeof(char) * len + 1);
        if (res) {
            for (s21_size_t i = 0; i <= len; i++) {
                if (str[i] >= 'a' && str[i] <= 'z')
                    res[i] = str[i] - 32;
                else
                    res[i] = str[i];
            }
        }
        res[len] = '\0';
    }
    return res;
}
