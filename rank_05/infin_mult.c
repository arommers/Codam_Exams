#include "infin_mult.h"

// Function to get the length of a string
size_t ft_strlen(const char* str)
{
    size_t len = 0;
    while (str[len])
        len++;
    return (len);
}

// Function to multiply two numbers represented as strings
void multiply_strings(const char* num1, const char* num2)
{
    size_t len1 = ft_strlen(num1);
    size_t len2 = ft_strlen(num2);
    size_t result_len = len1 + len2 + 1; // Maximum possible length of the result

    // Allocate memory for the result string
    char* result = (char*)malloc(result_len);
    if (!result)
    {
        write(1, "Malloc failed\n", 15);
        return;
    }

    // Initialize the result to zero
    for (size_t i = 0; i < result_len; i++)
        result[i] = '0';
    result[result_len - 1] = '\0';

    // Perform multiplication and convert to char
    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int digit1 = num1[i] - '0';

        for (int j = len2 - 1; j >= 0; j--)
        {
            int digit2 = num2[j] - '0';
            int product = (digit1 * digit2) + (result[i + j + 1] - '0') + carry;

            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i] += carry;
    }

    // Find the position of the first non-zero digit
    size_t start_pos = 0;
    while (start_pos < result_len - 1 && result[start_pos] == '0')
        start_pos++;

    // Print the result to stdout
    write(1, result + start_pos, result_len - start_pos - 1);
    write(1, "\n", 1);

    // Free allocated memory
    free(result);
}

