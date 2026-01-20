#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Fundamental functions
size_t string_length(const char *string);                    // Returns length of null-terminated string (excludes '\0')
char *string_copy(const char *string);                       // Returns a dynamically allocated copy of the string, caller must free
void string_free(char *string);                              // Frees memory allocated for a string, safe if NULL
int string_equals(const char *string1, const char *string2); // Returns 1 if strings are equal, otherwise returns 0

// Search and comparision
int string_find(const char *string, const char *pattern);
int string_starts_with(const char *string, const char *prefix); // returns 1 if the string starts with the prefix otherwise returns 0
int string_ends_with(const char *string, const char *suffix);   // returns 1 if the string ends with the suffix otherwise returns 0

// Substrings and slicing
char *substring_finder(int start, int end, const char *string); // Returns new substring from start to end, caller must free
char *string_replace(int start, int end, const char *string, const char *new_text);
char *string_insert(const char *string, const char *added_string, int index);

// String modification and construction
char *string_append(const char *string, const char *append); // Returns new string with appended string, caller must free
char *string_trim(const char *string);                       // Returns new string with leading/trailing spaces removed, caller must free

// Case Conversion
char *string_to_lower(const char *string);
char *string_to_upper(const char *string);

// Tokenization
char **string_split(const char *string, char delim, int *count);

char *string_reverse(const char *string); // Returns new reversed string  , caller must free
char *string_sort(const char *string);    // returns new sorted string , caller must free

int string_compare(const char *a, const char *b);
int string_find_char(const char *string, char c);
char *string_ltrim(const char *string);
char *string_rtrim(const char *string);
char *string_join(char **strings, int count, const char *separator);
char *string_replace_first(const char *string, const char *old, const char *new);
char *string_replace_all(const char *string, const char *old, const char *new);
int string_is_empty(const char *string);   // returns 1 if the string is empty and returns 0 otherwise
int string_is_numeric(const char *string); // returns 1 if the string is numeric
int string_is_alpha(const char *string);   // returns 1 if the string is alphabetical
int string_is_alnum(const char *string);   // returns 1 if the string is alphanumeric
int string_index_valid(const char *string, int index);
int string_range_valid(const char *string, int start, int end);
char *string_repeat(const char *string, int times);
char *string_pad_left(const char *string, int width, char pad);
char *string_pad_right(const char *string, int width, char pad);
size_t string_length(const char *string)
{
    if (string == NULL)
        return 0;
    return strlen(string);
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
    if (result == NULL)
    {
        printf("Memory not allocated\n");
        return NULL;
    }

    for (size_t i = 0; i < string_l1; i++)
        result[i] = string[i];
    result[string_l1] = '\0';

    return result;
}

char *string_trim(const char *string)
{
    size_t k = 0;
    int startindex = 0;
    int endindex = 0;

    if (string == NULL)
        return NULL;

    size_t string_l1 = string_length(string);

    for (size_t i = 0; i < string_l1; i++)
    {
        if (string[i] != ' ')
        {
            startindex = i;
            break;
        }
    }

    for (int i = string_l1 - 1; i >= 0; i--)
    {
        if (string[i] != ' ')
        {
            endindex = i;
            break;
        }
    }

    char *result = malloc(endindex - startindex + 2);

    if (result == NULL)
    {
        printf("Memory not allocated\n");
        return NULL;
    }

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
    if (string != NULL)
        free(string);
}

int string_equals(const char *string1, const char *string2)
{
    if (string1 == NULL || string2 == NULL)
        return 0;

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

int string_find(const char *string, const char *pattern) // complete this
{

    size_t string_l1 = string_length(string);
    size_t string_l2 = string_length(pattern);

    if (string_l2 > string_l1)
    {
        return -1;
    }
}

int string_starts_with(const char *string, const char *prefix)
{
    if (string == NULL || prefix == NULL)
        return -1;
    size_t string_l1 = string_length(string);
    size_t string_l2 = string_length(prefix);
    int startswithprefix = 1;

    if (string_l2 > string_l1)
        return -1;

    for (size_t i = 0; i < string_l2; i++)
    {
        if (string[i] != prefix[i])
        {
            startswithprefix = 0;
            break;
        }
    }

    return startswithprefix;
}

int string_ends_with(const char *string, const char *suffix)
{
    if (string == NULL || suffix == NULL)
        return -1;

    size_t string_l1 = string_length(string);
    size_t string_l2 = string_length(suffix);
    int endswithsuffix = 1;

    if (string_l2 > string_l1)
        return -1;

    for (size_t i = 0; i < string_l2 - 1; i++)
    {
        if (string[string_l1 - string_l2 + i] != suffix[i])
        {
            endswithsuffix = 0;
            break;
        }
    }

    return endswithsuffix;
}

char *string_to_lower(const char *string)
{
    if (string == NULL)
        return NULL;

    size_t string_l1 = string_length(string);
    char *result = malloc((string_l1 + 1) * sizeof(char));

    if (result == NULL)
        return NULL;

    for (int i = 0; i < string_l1; i++)
    {
        if (isalnum(string[i]) == 1)
        {
            result[i] = tolower(string[i]);
        }

        else
            result[i] = string[i];
    }

    result[string_l1] = '\0';
    return result;
}

char *string_to_upper(const char *string)
{
    if (string == NULL)
        return NULL;

    size_t string_l1 = string_length(string);
    char *result = malloc((string_l1 + 1) * sizeof(char));

    if (result == NULL)
        return NULL;

    for (int i = 0; i < string_l1; i++)
    {
        if (isalnum(string[i]) == 1)
        {
            result[i] = toupper(string[i]);
        }

        else
            result[i] = string[i];
    }

    result[string_l1] = '\0';
    return result;
}

char *string_reverse(const char *string)
{
    if (string == NULL)
        return NULL;

    size_t string_l1 = string_length(string);

    char *result = malloc((string_l1 + 1) * sizeof(char));
    if (result == NULL)
        return NULL;

    for (size_t i = 0; i < string_l1; i++)
    {
        result[i] = string[string_l1 - 1 - i];
    }
    result[string_l1] = '\0';
    return result;
}

char *string_sort(const char *string)
{
    if (string == NULL)
        return NULL;

    size_t string_l1 = string_length(string);

    char *result = malloc((string_l1 + 1) * sizeof(char));

    if (result == NULL)
        return NULL;

    if (string_l1 < 2)
    {
        if (string_l1 == 1)
            result[0] = string[0];

        result[string_l1] = '\0';
        return result;
    }

    for (size_t i = 0; i < string_l1; i++)
        result[i] = string[i];

    for (size_t i = 0; i < string_l1 - 1; i++)
    {
        for (size_t j = 0; j < string_l1 - i - 1; j++)
        {
            if (result[j] > result[j + 1])
            {
                char temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }

    result[string_l1] = '\0';
    return result;
}

int string_is_empty(const char *string)
{
    if (string == NULL || string[0] == '\0')
    {
        return 1;
    }
    return 0;
}

int string_is_numeric(const char *string)
{
    if (string == NULL || string[0] == '\0')
        return 0;

    size_t string_l1 = string_length(string);
    int isnumeric = 1;

    for (size_t i = 0; i < string_l1; i++)
    {
        if (isdigit(string[i]) == 0)
        {
            isnumeric = 0;
            break;
        }
    }

    return isnumeric;
}

int string_is_alpha(const char *string)
{
    if (string == NULL || string[0] == '\0')
        return 0;

    size_t string_l1 = string_length(string);
    int isalphabet = 1;

    for (size_t i = 0; i < string_l1; i++)
    {
        if (isalpha(string[i]) == 0)
        {
            isalphabet = 0;
            break;
        }
    }

    return isalphabet;
}

int string_is_alnum(const char *string)
{

    if (string == NULL || string[0] == '\0')
        return 0;

    size_t string_l1 = string_length(string);
    int isalphanum = 1;

    for (size_t i = 0; i < string_l1; i++)
    {
        if (isalnum(string[i]) == 0)
        {
            isalphanum = 0;
            break;
        }
    }

    return isalphanum;
}

char *string_pad_left(const char *string, int width, char pad)
{
    char *result = malloc((width + 1) * sizeof(char));
    if (result == NULL)
        return NULL;
    size_t string_l1 = string_length(string);
}

char *string_pad_right(const char *string, int width, char pad);

int main()
{
    char s1[] = "Helloo   WOOOORD        s";
    char s2[] = "Hello";
    char *s3 = "aaaa df df df Hello";
    int a = string_find(s1, s2);
    char *s = string_to_lower(s1);
    int b = string_equals("World", s2);
    int c = string_ends_with(s3, s2);
    char *d = string_sort(s1);

    printf("%s", d);

    return 0;
}

/*
int  string_starts_with(const char *s, const char *prefix);
int  string_ends_with(const char *s, const char *suffix);
char *string_to_lower(const char *s);
char *string_to_upper(const char *s);

fix functions
fix formatting issues with comments
remove print statements
add readme.md
*/