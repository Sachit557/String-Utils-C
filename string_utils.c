#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Fundamental functions
size_t string_length(const char *string);                    // Returns length of null-terminated string (excludes '\0')
char *string_duplicate(const char *string);                  // Returns a dynamically allocated copy of the string, caller must free
void string_free(char *string);                              // Frees memory allocated for a string, safe if NULL
int string_equals(const char *string1, const char *string2); // Returns 1 if strings are equal, otherwise returns 0

// Search and comparision
int string_find(const char *string, const char *pattern);       // Returns the starting index of the first occurrence of pattern in string, or -1 if not found or inputs are NULL
int string_starts_with(const char *string, const char *prefix); // returns 1 if the string starts with the prefix otherwise returns 0
int string_ends_with(const char *string, const char *suffix);   // returns 1 if the string ends with the suffix otherwise returns 0

// Substrings and slicing
char *substring_finder(int start, int end, const char *string); // Returns new substring from start to end, caller must free
char *string_replace(int start, int end, const char *string, const char *new_text);
char *string_insert(const char *string, const char *added_string, int index); // Returns a new string with the added string inserted at the index , caller calls free

// String modification and construction
char *string_append(const char *string, const char *append); // Returns new string with appended string, caller must free
char *string_trim(const char *string);                       // Returns new string with leading/trailing spaces removed, caller must free

// Case Conversion
char *string_to_lower(const char *string); // returns a new string with all characters in lowercase
char *string_to_upper(const char *string); // returns a new string with all characters un uppercase

// Tokenization
char **string_split(const char *string, char delim, int *count);

char *string_reverse(const char *string); // Returns new reversed string  , caller must free
char *string_sort(const char *string);    // returns new sorted string , caller must free

int string_compare(const char *a, const char *b);
int string_find_char(const char *string, char c);
char *string_ltrim(const char *string); // Returns a newly allocated string with all leading whitespace removed from the input string
char *string_rtrim(const char *string); // Returns a newly allocated string with all trailing whitespace removed from the input string
char *string_join(char **strings, int count, const char *separator);
char *string_replace_first(const char *string, const char *old, const char *new); // Returns a new string with the first occurrence of a particular string replaced with a different string
char *string_replace_all(const char *string, const char *old, const char *new);
int string_is_empty(const char *string);                           // returns 1 if the string is empty and returns 0 otherwise
int string_is_numeric(const char *string);                         // returns 1 if the string is numeric and returns 0 otherwise
int string_is_alpha(const char *string);                           // returns 1 if the string is alphabetical and returns 0 otherwise
int string_is_alnum(const char *string);                           // returns 1 if the string is alphanumeric and returns 0 otherwise
int string_index_valid(const char *string, int index);             // Returns 1 if index is within valid bounds of the string, otherwise returns 0
int string_range_valid(const char *string, int start, int end);    // Returns 1 if the range [start, end) is valid within the string, otherwise returns 0
char *string_repeat(const char *string, int times);                // Returns a newly allocated string formed by repeating the input string 'times' times
char *string_pad_left(const char *string, int width, char pad);    // Pads a string to a given width by adding the specified character to the left.
char *string_pad_right(const char *string, int width, char pad);   // Pads a string to a given width by adding the specified character to the right.
char *string_remove_range(const char *string, int start, int end); // Returns a new string with the range removed from the string . caller must free

char *string_pop_back(const char *string);                          // returns a new string with last character removed . caller must free
char *string_pop_front(const char *string);                         // returns a new string with first character removed . caller must free
char *string_remove_char(const char *string, char c);               // returns a new string with all occurrence of the particular character removed
char *string_remove_first(const char *string, const char *pattern); // returns a new string with first occurence of the substring removed
char *string_remove_all(const char *string, const char *pattern);

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
        return NULL;

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
        return NULL;

    if (end <= start)
        return NULL;

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
        return NULL;

    if (end < start)
        return NULL;

    size_t string_l1 = string_length(string);

    if (string_l1 - 1 < end)
        return NULL;

    size_t substring_length = end - start + 2;
    char *result = malloc(substring_length * sizeof(char));

    if (result == NULL)
        return NULL;

    for (size_t i = start; i < end + 1; i++)
    {
        result[index] = string[i];
        index++;
    }

    result[index] = '\0';
    return result;
}

char *string_insert(const char *string, const char *added_string, int index)
{
    if (index < 0)
        return NULL;
    size_t string_l1 = string_length(string);
    size_t string_l2 = string_length(added_string);
    size_t j = 0;

    if (index > string_l1)
        return NULL;
    char *result = malloc((string_l1 + string_l2 + 1) * sizeof(char));

    if (result == NULL)
        return NULL;

    for (size_t i = 0; i < index; i++)
        result[i] = string[i];

    for (size_t i = index; i < index + string_l2; i++)
        result[i] = added_string[j++];

    for (size_t i = index; i < string_l1; i++)
        result[string_l2 + i] = string[i];

    result[string_l1 + string_l2] = '\0';
    return result;
}

char *string_duplicate(const char *string)
{
    size_t string_l1 = string_length(string);
    char *result = malloc((string_l1 + 1) * sizeof(char));
    if (result == NULL)
        return NULL;

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
        if (!isspace(string[i]))
        {
            startindex = i;
            break;
        }
    }

    for (int i = string_l1 - 1; i >= 0; i--)
    {
        if (!isspace(string[i]))
        {
            endindex = i;
            break;
        }
    }

    char *result = malloc(endindex - startindex + 2);

    if (result == NULL)
        return NULL;

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

int string_find(const char *string, const char *pattern)
{

    if (string == NULL || pattern == NULL)
        return -1;

    size_t string_l1 = string_length(string);
    size_t string_l2 = string_length(pattern);
    size_t lastindex = string_l1 - string_l2;
    size_t index = 0;

    if (string_l2 > string_l1)
    {
        return -1;
    }

    for (size_t i = 0; i < lastindex + 1; i++)
    {
        if (string[i] != pattern[0])
            continue;

        else
        {

            index = i;
            size_t k = 0;
            size_t counter = 0;
            for (size_t j = i; j < string_l2 + i; j++)
            {
                if (string[j] == pattern[k++])
                {
                    counter++;
                }

                else
                    break;
            }

            if (counter == string_l2)
                return index;
            else
                continue;
        }
    }

    return -1;
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
        if (isalnum((unsigned char)string[i]))
        {
            result[i] = tolower((unsigned char)string[i]);
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
        if (isalnum((unsigned char)string[i]))
        {
            result[i] = toupper((unsigned char)string[i]);
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

    size_t string_l1 = string_length(string);

    if (width <= string_l1)
    {
        char *result = malloc((string_l1 + 1) * sizeof(char));
        if (result == NULL)
            return NULL;
        for (size_t i = 0; i < string_l1; i++)
        {
            result[i] = string[i];
        }

        result[string_l1] = '\0';
        return result;
    }

    else
    {
        char *result = malloc((width + 1) * sizeof(char));
        if (result == NULL)
            return NULL;

        for (size_t i = 0; i < width - string_l1; i++)
        {
            result[i] = pad;
        }

        for (size_t i = 0; i < string_l1; i++)
        {
            result[width - string_l1 + i] = string[i];
        }

        result[width] = '\0';
        return result;
    }
}

char *string_pad_right(const char *string, int width, char pad)
{
    size_t string_l1 = string_length(string);

    if (width <= string_l1)
    {
        char *result = malloc((string_l1 + 1) * sizeof(char));
        if (result == NULL)
            return NULL;
        for (size_t i = 0; i < string_l1; i++)
        {
            result[i] = string[i];
        }

        result[string_l1] = '\0';
        return result;
    }

    else
    {
        char *result = malloc((width + 1) * sizeof(char));
        if (result == NULL)
            return NULL;

        for (size_t i = 0; i < string_l1; i++)
        {
            result[i] = string[i];
        }

        for (size_t i = 0; i < width - string_l1; i++)
        {
            result[string_l1 + i] = pad;
        }

        result[width] = '\0';
        return result;
    }
}

char *string_ltrim(const char *string)
{
    if (string == NULL)
        return NULL;

    int startindex = 0;

    size_t string_l1 = string_length(string);

    for (size_t i = 0; i < string_l1; i++)
    {
        if (!isspace(string[i]))
        {
            startindex = i;
            break;
        }
    }

    size_t trimmed_str_lenth = string_l1 - startindex;
    char *result = malloc((trimmed_str_lenth + 1) * sizeof(char));

    if (result == NULL)
        return NULL;

    for (int i = 0; i < trimmed_str_lenth; i++)
        result[i] = string[i + startindex];

    result[trimmed_str_lenth] = '\0';
    return result;
}

char *string_rtrim(const char *string)
{
    if (string == NULL)
        return NULL;

    int endindex = 0;

    int string_l1 = (int)string_length(string);

    for (int i = string_l1 - 1; i >= 0; i--)
    {
        if (!isspace(string[i]))
        {
            endindex = i;
            break;
        }
    }

    int trimmed_str_lenth = endindex + 1;
    char *result = malloc((trimmed_str_lenth + 1) * sizeof(char));

    if (result == NULL)
        return NULL;

    for (int i = 0; i < endindex + 1; i++)
        result[i] = string[i];

    result[trimmed_str_lenth] = '\0';
    return result;
}

char **string_split(const char *string, char delim, int *count) // complete this
{
    if (string == NULL)
        return NULL;

    size_t string_l1 = string_length(string);

    int startindex = 0;
    int endindex = 0;

    for (int i = 0; i < string_l1; i++)
    {
        if (string[i] != delim)
        {
            startindex = i;
            break;
        }
    }

    for (int i = string_l1 - 1; i >= 0; i--)
    {
        if (string[i] != delim)
        {
            endindex = i;
            break;
        }
    }

    int counter = 0;
    for (int i = startindex; i <= endindex; i++)
    {
        if (string[i] == delim)
        {
            while (string[i] == delim)
                i++;
            counter++;
        }
    }

    *count = counter + 1;

    char **result = malloc((*count + 1) * sizeof(char *)); // last one for null terminator

    if (result == NULL)
        return NULL;

    result[*count] = '\0'; // null terminated
    int k = 0;

    //
    // write logic for allocatin tokens and then adding them to **result
    //
    int i = startindex;

    while (i <= endindex)
    {
        if (string[i] != delim)
        {
        }

        else
            i++;
    }

    return result;
}

char *string_repeat(const char *string, int times)
{
    if (string == NULL)
        return NULL;

    if (times < 0)
        return NULL;

    if (times == 0)
    {
        char *result = malloc(1 * sizeof(char));
        if (result == NULL)
            return NULL;
        result[0] = '\0';
        return result;
    }

    size_t string_l1 = string_length(string);
    size_t string_l2 = string_l1 * times;
    size_t k = 0;

    char *result = malloc((string_l2 + 1) * sizeof(char));

    if (result == NULL)
        return NULL;

    for (size_t i = 0; i < times; i++)
    {
        for (size_t j = 0; j < string_l1; j++)
        {
            result[k] = string[j];
            k++;
        }
    }

    result[string_l2] = '\0';
    return result;
}

int string_index_valid(const char *string, int index)
{

    if (string == NULL || index < 0)
        return 0;

    return index < (int)string_length(string);
}

int string_range_valid(const char *string, int start, int end)
{
    if (string == NULL || start < 0 || end < 0 || start < end)
        return 0;

    return end <= (int)string_length(string);
}

char *string_replace_first(const char *string, const char *old, const char *new)
{
    if (string == NULL || old == NULL || new == NULL)
        return NULL;

    size_t string_l1 = string_length(string);
    size_t string_l2 = string_length(old);
    size_t string_l3 = string_length(new);
    size_t j = 0;

    int index = string_find(string, old);

    if (index == -1)
        return NULL;

    size_t size = string_l1 - string_l2 + string_l3 + 1;
    char *result = malloc(size * sizeof(char));

    for (size_t i = 0; i < index; i++)
        result[i] = string[i];

    for (size_t i = index; i < index + string_l3; i++)
        result[i] = new[j++];

    for (size_t i = index + string_l2; i < string_l1; i++)
        result[string_l3 + i - string_l2] = string[i];

    result[size - 1] = '\0';
    return result;
}

char *string_replace_all(const char *string, const char *old, const char *new) // complete this
{
    size_t string_l1 = string_length(string);
    size_t string_l2 = string_length(old);
    size_t string_l3 = string_length(new);
}

char *string_remove_range(const char *string, int start, int end)
{
    if (end < start)
        return NULL;

    if (string == NULL)
        return NULL;
    size_t startindex = start;
    size_t endindex = end - 1;
    size_t string_l1 = string_length(string);
    size_t string_l2 = endindex - startindex + 1;
    size_t string_l3 = string_l1 - string_l2;
    size_t k = 0;

    if (endindex > string_l1 - 1)
        return NULL;

    char *result = malloc((string_l3 + 1) * sizeof(char));

    if (result == NULL)
        return NULL;

    for (size_t i = 0; i < startindex; i++)
        result[k++] = string[i];

    for (size_t i = end; i < string_l1; i++)
        result[k++] = string[i];

    result[string_l3] = '\0';
    return result;
}

char *string_pop_back(const char *string)
{
    if (string == NULL)
        return NULL;

    size_t string_l1 = string_length(string);

    if (string_l1 == 1 || string_l1 == 0)
    {
        char *result = malloc(1 * sizeof(char));

        if (result == NULL)
            return NULL;

        result[0] = '\0';
        return result;
    }

    char *result = malloc(string_l1 * sizeof(char));

    if (result == NULL)
        return NULL;

    for (size_t i = 0; i < string_l1 - 1; i++)
        result[i] = string[i];

    result[string_l1 - 1] = '\0';
    return result;
}

char *string_pop_front(const char *string)
{
    if (string == NULL)
        return NULL;

    size_t string_l1 = string_length(string);
    size_t k = 0;

    if (string_l1 == 1 || string_l1 == 0)
    {
        char *result = malloc(1 * sizeof(char));

        if (result == NULL)
            return NULL;

        result[0] = '\0';
        return result;
    }

    char *result = malloc(string_l1 * sizeof(char));

    if (result == NULL)
        return NULL;

    for (size_t i = 1; i < string_l1 - 1; i++)
        result[k++] = string[i];

    result[string_l1 - 1] = '\0';
    return result;
}

char *string_remove_char(const char *string, char c)
{
    if (string == NULL)
        return NULL;

    size_t string_l1 = string_length(string);
    size_t count = 0;
    size_t k = 0;

    for (size_t i = 0; i < string_l1; i++)
        if (string[i] == c)
            count++;

    size_t size = string_l1 - count;

    char *result = malloc((size + 1) * sizeof(char));

    if (result == NULL)
        return NULL;

    for (size_t i = 0; i < string_l1; i++)
    {
        if (string[i] != c)
            result[k++] = string[i];
    }

    result[size] = '\0';
    return result;
}

char *string_remove_first(const char *string, const char *pattern)
{
    if (string == NULL || pattern == NULL)
        return NULL;

    size_t string_l1 = string_length(string);
    size_t string_l2 = string_length(pattern);
    size_t string_l3 = string_l1 - string_l2;
    size_t k = 0;

    if (string_l2 > string_l1)
        return NULL;

    size_t startindex = string_find(string, pattern);
    if (startindex == -1)
        return NULL;

    size_t endindex = startindex + string_l2 - 1;

    char *result = malloc((string_l3 + 1) * sizeof(char));

    if (result == NULL)
        return NULL;

    for (size_t i = 0; i < startindex; i++)
        result[k++] = string[i];

    for (size_t i = endindex + 1; i < string_l1; i++)
        result[k++] = string[i];

    result[string_l3] = '\0';
    return result;
}

char *string_remove_all(const char *string, const char *pattern)
{
    if (string == NULL || pattern == NULL)
        return NULL;

    size_t string_l1 = string_length(string);
    size_t string_l2 = string_length(pattern);
    size_t last_index = string_l1 - string_l2;

    size_t k = 0;
    size_t size = 0;

    if (string_l2 > string_l1)
        return NULL;

    int *indexes = NULL;
    int *result = NULL;

    while (1)
    {
        for (size_t i = 0; i < string_l1; i++)
        {
            if (string[i] != pattern[0])
                continue;

            else
            {
                size_t index = i;
                for (size_t j = i; j < string_l1; j++)
                {
                }
            }
        }
    }
}

int main()
{
    char s1[] = "Helloo   Hello Hello hi hi hi Hello";
    char s2[] = "Hello ";
    char *s4 = "          H e l    l   o     a                a";
    char *s3 = "aaaa df df df Hello";
    char *s = string_remove_all(s1, "Hello");

    printf("%s", s);

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