#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// string replace
// string length
// string append
// substring finder
// string insert

int string_length(const char *string);
int string_find(const char *string, const char *pattern);
int string_equals(const char *string1, const char *string2);
char *string_append(const char *string, const char *append);
char *string_replace(int start, int end, const char *string, const char *new_text);
char *substring_finder(int start, int end, const char *string);
char *string_insert(const char *string, const char *added_string, int index);
char *string_copy(const char *string);
char *string_trim(const char *string);
char **string_split(const char *string, char delim, int *count);
void string_free(char *string);

int string_length(const char *string)
{
    int a = strlen(string);
    return a;
}

char *string_append(const char *string, const char *append)
{
    size_t string_l1 = string_length(string);
    size_t string_l2 = string_length(append);
    size_t result_size = string_l1 + string_l2 + 1; // +1 is added for null termination at the end

    char *result = malloc(result_size * sizeof(char));

    if (result == NULL)
    {
        printf("Memory not allocated\n");
        return NULL;
    }

    for (size_t i = 0; i < string_l1; i++)
        result[i] = string[i];

    for (size_t i = 0; i < string_l2; i++)
        result[string_l1 + i] = append[i];

    result[result_size - 1] = '\0';

    return result;
}

char *string_replace(int start, int end, const char *string, const char *new_text) // complete this
{
    if (start < 0 || end < 0)
    {
        printf("Indexes must be greater than 0\n");
        return NULL;
    }

    if (end <= start)
    {
        printf("second index should be higher than the first one\n");
        return NULL;
    }

    size_t string_l1 = string_length(string);
    size_t string_l2 = string_length(new_text);

    if (string_l1 - 1 >= end)
    {
        char *result;

        for (int i = 0; i < start; i++)
        {
            result[i] = string[i];
        }

        for (int i = 0; i < string_l2; i++)
        {
            result[start + i] = new_text[i];
        }
    }

    else if (string_l1 - 1 < end)
    {
        // if start index is within the length of the string then append that if not then skip
        // append the new text that had to be replaced
    }
}

char *substring_finder(int start, int end, const char *string)
{
    size_t index = 0;
    if (start < 0 || end < 0)
    {
        printf("Indexes must be greater than 0\n");
        return NULL;
    }

    if (end < start)
    {
        printf("second index should be higher than the first one\n");
        return NULL;
    }

    size_t string_l1 = string_length(string);

    if (string_l1 - 1 < end)
    {
        printf("second index cant be greater than the length of the string\n");
        return NULL;
    }

    size_t substring_length = end - start + 2;
    char *result = malloc(substring_length * sizeof(char));

    if (result == NULL)
    {
        printf("Memory not allocated\n");
        return NULL;
    }

    for (size_t i = start; i < end + 1; i++)
    {
        result[index] = string[i];
        index++;
    }

    result[index] = '\0';
    return result;
}

char *string_insert(const char *string, const char *added_string, int index) // complete this
{
    if (index < 0)
    {
        printf("index cannot be less than 0\n");
        return NULL;
    }

    size_t string_l1 = string_length(string);
    size_t string_l2 = string_length(added_string);
    char *result;

    if (index <= string_l1 - 1)
    {
        int k = 0;
        for (int i = 0; i < index; i++)
            result[i] = string[i];

        for (int i = index; i < index + string_l2 + 1; i++)
        {
            result[i] = added_string[k];
            k++;
        }

        for (int i = index + string_l2 + 1;; i++)
        {
        }
    }

    else
    {
        string_append(string, added_string);
    }

    return result;
}

char *string_copy(const char *string)
{
    size_t string_l1 = string_length(string);
    char *result = malloc((string_l1 + 1) * sizeof(char));

    for (int i = 0; i < string_l1; i++)
        result[i] = string[i];
    result[string_l1] = '\0';

    return result;
}

char *string_trim(const char *string)
{
    size_t k = 0;
    size_t string_l1 = string_length(string);
    int startindex = 0;
    int endindex = 0;

    for (size_t i = 0; i < string_l1; i++)
    {
        if (string[i] != ' ')
        {
            startindex = i;
            break;
        }
    }

    for (size_t i = string_l1 - 1; i >= 0; i--)
    {
        if (string[i] != ' ')
        {
            endindex = i;
            break;
        }
    }

    char *result = malloc(endindex - startindex + 2);

    for (size_t i = startindex; i < endindex + 1; i++)
    {
        result[k] = string[i];
        k++;
    }

    result[endindex - startindex + 1] = '\0';
    return result;
}

void string_free(char *string)
{
    free(string);
}

int string_equals(const char *string1, const char *string2)
{
    size_t string_l1 = string_length(string1);
    size_t string_l2 = string_length(string2);

    if (string_l1 != string_l2)
        return 0;

    for (size_t i = 0; i < string_l1; i++)
    {
        if (string1[i] != string2[i])
            return 0;
    }

    return 1;
}

int string_find(const char *string, const char *pattern)
{
    size_t string_l1 = string_length(string);
    size_t string_l2 = string_length(pattern);

    if (string_l2 > string_l1)
    {
        return -1;
    }
}

int main()
{
    char s1[] = "Hello   WOOOORD        s";
    char s2[] = "World";
    int a = string_length(s1);
    char *s = string_trim(s1);
    int b = string_equals("World", s2);

    printf("%d", b);

    return 0;
}

/*
int  string_starts_with(const char *s, const char *prefix);
int  string_ends_with(const char *s, const char *suffix);
char *string_to_lower(const char *s);
char *string_to_upper(const char *s);


*/