#ifndef STRING_STRUCT_H
#define STRING_STRUCT_H
#include <stdio.h>
#include <stdlib.h>
struct string {
  char *array;
  size_t size;
};
// create a new string obj and malloc size to it
struct string string_malloc(size_t size);
// free memory taken by string
void string_free(struct string str);
// print non-null terminated string
void string_print(struct string str);
// make and return a deep copy of the string
struct string string_copy(struct string src);
// make and return a deep copy of the string
struct string string_copy_c_style(char *src, size_t size);
// compare two string objects
int string_compare(struct string a, struct string b);
// compare string object with a c style string
int string_compare_c_style(struct string a, char *b);
#endif

#ifdef STRING_STRUCT_IMPLEMENTATION
#include "stringstruct.h"
#include <string.h>

struct string string_malloc(size_t size) {
  struct string str;
  str.array = malloc(size);
  str.size = size;
  return str;
}
void string_free(struct string str) { free(str.array); }
void string_print(struct string str) {
  fwrite(str.array, sizeof(char), str.size, stdout);
  printf("\n");
}
struct string string_copy(struct string src) {
  struct string str = string_malloc(src.size);
  memcpy(str.array, src.array, src.size);
  str.size = src.size;
  return str;
}
struct string string_copy_c_style(char *src, size_t size) {
  struct string str = string_malloc(size);
  memcpy(str.array, src, size);
  str.size = size;
  return str;
}

int string_compare(struct string a, struct string b) {
  return strncmp(a.array, b.array, a.size < b.size ? a.size : b.size);
}
int string_compare_c_style(struct string a, char *b) {
  return strncmp(a.array, b, a.size);
}
#endif
