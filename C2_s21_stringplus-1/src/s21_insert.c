#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result_str = s21_NULL;
  s21_size_t len_src = src ? s21_strlen(src) : 0;
  s21_size_t len_str = str ? s21_strlen(str) : 0;
  if (start_index <= len_src && src && str) {
    result_str = (char *)calloc(len_src + len_str + 1, sizeof(char));
    if (result_str) {
      for (s21_size_t i = 0, j = 0, l = 0; i < len_src + len_str;) {
        if (i == start_index)
          for (; *(str + j); ++j) result_str[i++] = str[j];
        else
          result_str[i++] = src[l++];
      }
    }
  }
  return result_str;
}
