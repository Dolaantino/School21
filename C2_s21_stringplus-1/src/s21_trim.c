#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  void *result = s21_NULL;
  static char *buf = s21_NULL;
  buf = malloc(s21_strlen(src) + 1);
  if (!buf) exit(0);
  s21_strcpy(buf, src);
  if (src) {
    if (trim_chars && *trim_chars) {
      for (int i = (int)s21_strlen(src) - 1;
           i >= 0 && s21_strrchr(trim_chars, buf[i]) != s21_NULL; i--)
        buf[i] = '\0';

      while (buf[0] != '\0' && s21_strrchr(trim_chars, buf[0]) != s21_NULL)
        s21_memmove(&buf[0], &buf[1], s21_strlen(src));
      result = buf;
    } else {
      char def_trim[] = " \n\t\r\x0B\f";
      for (int i = (int)s21_strlen(src) - 1;
           i >= 0 && s21_strrchr(def_trim, buf[i]) != s21_NULL; i--)
        buf[i] = '\0';

      while (buf[0] != '\0' && s21_strrchr(def_trim, buf[0]) != s21_NULL)
        s21_memmove(&buf[0], &buf[1], s21_strlen(src));

      result = buf;
    }
  }
  return result;
}