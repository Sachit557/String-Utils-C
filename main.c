#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// string replace
// string length
// string append
// substring finder
// string insert

int string_length(const char *string);
char *string_append(const char *string, const char *append);
char *string_replace(int start, int end, const char *string, const char *new_text);
char *substring_finder(int start, int end, const char *string);
char *string_insert(const char *string, const char *added_string, int index);

int string_length(const char *string)
{
    int a = strlen(string);
    return a;
}

char *string_append(const char *string, const char *append)
{
    int string_length = strlen(string);
    int append_string_length = strlen(append);

    int total = string_length + append_string_length + 1;
    char *appended_string = malloc(total);

    if (!appended_string)
    {
        return NULL;
    }

    for (int i = 0; i < string_length; i++)
    {
        appended_string[i] = string[i];
    }

    for (int j = 0; j < append_string_length; j++)
    {
        appended_string[string_length + j] = append[j];
    }

    appended_string[total - 1] = '\0';

    return appended_string;
}

char *string_replace(int start, int end, const char *string, const char *new_text)
{
    // replace the text between i and j to the new text where i and j are included
    int difference = end - start - 1;
    int new_str_length = string_length(new_text);
    char updated_string[40];
    int k = 0;

    for (int i = 0; i < start && string[i] != '\0'; i++)
    {
        updated_string[k] = string[i];
        k++;
    }

    for (int i = 0; new_text[i] != '\0'; i++)
    {
        updated_string[k] = new_text[i];
        k++;
    }

    for (int i = end + 1; string[i] != '\0'; i++)
    {
        updated_string[k] = string[i];
        k++;
    }

    updated_string[k] = '\0';
    // return the updated string
}

char *substring_finder(int starting, int ending, const char *string)
{
    char substring[40];
    int difference = ending - starting + 1;
    for (int i = starting; i <= ending; i++)
    {
        string_append(substring, string[i]);
    }

    substring[difference] = '\0';

    // return substring
}

char *string_insert(const char *string, const char *added_string, int index)
{
}