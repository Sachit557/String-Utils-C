#include <stdio.h>

#ifndef STRING_UTILS
#define STRING_UTILS

size_t string_length(const char *string); // returns length of a string
int string_find(const char *string, const char *pattern);
int string_equals(const char *string1, const char *string2); // returns 1 if the 2 strings are equal otherwise returns 0
char *string_append(const char *string, const char *append); // returns a string of the appended length on the string
char *string_replace(int start, int end, const char *string, const char *new_text);
char *substring_finder(int start, int end, const char *string); // returns the substring between 2 indexes
char *string_insert(const char *string, const char *added_string, int index);
char *string_copy(const char *string); // returns the copy of the string
char *string_trim(const char *string); // removes the spaces from starting and the end
char **string_split(const char *string, char delim, int *count);
void string_free(char *string); // frees the memory allocated to the pointer
int string_starts_with(const char *s, const char *prefix);
int string_ends_with(const char *s, const char *suffix);
char *string_to_lower(const char *s);
char *string_to_upper(const char *s);

#endif
