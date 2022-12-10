#include "s21_string.h"
#include <stdlib.h>

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = S21_NULL;
  if (src != S21_NULL && str != NULL) {
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_str = s21_strlen(str);
    s21_size_t final_len = len_src + len_str;
    if (len_src >= start_index) {
      res = (char *)malloc(sizeof(char) * final_len + 1);
    }
    if (res) {
      for (s21_size_t i = 0, j = 0, k = 0; i < final_len; i++) {
        if (i >= start_index && j < len_str) {
          res[i] = str[j];
          j++;
        } else {
          res[i] = src[k];
          k++;
        }
      }
      res[final_len] = '\0';
    }
  }
  return res;
}
