#include "s21_string.h"
#include <stdlib.h>

int trim_left(const char *src, const char *trim_chars) {
    const char *origin = src;
    int res = 0;
    s21_size_t len_trim = s21_strlen(trim_chars);
    if (s21_strlen(src) >= len_trim) {
        while ((src - origin) < (long)s21_strlen(origin) && s21_strstr(src, trim_chars) - src == 0) {
            if ((src + len_trim) - origin < (long)s21_strlen(origin))
                src += len_trim;
            else
                break;
            res += len_trim;
        }
    }
    return res;
}
int trim_right(const char *src, const char *trim_chars) {
    const char *origin = src;
    int res = 0;
    s21_size_t len_trim = s21_strlen(trim_chars);

    src += s21_strlen(src) - s21_strlen(trim_chars);
    while (s21_strstr(src, trim_chars) - src == 0 && src - origin >= 0) {
        src -= len_trim;
        res += len_trim;
    }
    return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
    if (src == S21_NULL) {
        return S21_NULL;
    }
    char *tmp = calloc(sizeof(*tmp), s21_strlen(src) + 1);

    const char space[] = " ";
    if (trim_chars == S21_NULL) {
        trim_chars = space;
    } else if (*trim_chars == '\0') {
        trim_chars = space;
    }

    int left = trim_left(src, trim_chars);
    s21_strcpy(tmp, src + left);

    int right = trim_right(tmp, trim_chars);
    if (right != 0) {
        tmp[s21_strlen(tmp) - right] = '\0';
    }

    return (void *)tmp;
}

// void *s21_trim(const char *src, const char *trim_chars) {
//   return S21_NULL;
//   if (src == S21_NULL) {
//     return S21_NULL;
//   }
//   const char spaces[] = " \t";
//   const char *chars = trim_chars;
//   if (chars == S21_NULL || *chars == 0) {
//     chars = spaces;
//   }
//   s21_size_t len_src = s21_strlen(src);
//   int flag;
//   char *p_start = (char *)src;
//   char *p_end = (char *)src + len_src - 1;
//   for (s21_size_t i = 0; i < len_src; i++) {
//     int n = 0;
//     flag = 0;
//     while (*(chars + n) != '\0') {
//       if (src[i] == *(chars + n)) {
//         p_start++;
//         flag = 1;
//         break;
//       }
//       n++;
//     }
//     if (flag == 1)
//       continue;
//     else
//       break;
//   }
//   for (int i = len_src - 1; i > 0; i--) {
//     int n = 0;
//     flag = 0;
//     while (chars[n] != '\0') {
//       if (src[i] == chars[n]) {
//         p_end--;
//         flag = 1;
//         break;
//       }
//       n++;
//     }
//     if (flag == 1)
//       continue;
//     else
//       break;
//   }
//   char *new_str = (char *)malloc(sizeof(*new_str) * (p_end - p_start + 2));
//   if (new_str != S21_NULL) {
//     int size_new_str = (int)(sizeof(*new_str) * (p_end - p_start + 2));
//     for (int i = 0; i < size_new_str; i++) {
//       new_str[i] = *(p_start + i);
//     }
//     new_str[size_new_str - 1] = '\0';
//   }
//   return new_str;
// }
