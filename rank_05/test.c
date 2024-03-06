#include "test.h"

size_t  ft_strlen(const char *str)
{
    size_t  len = 0;

    while (str[len])
        len++;
    return(len);
}

size_t  find_start(const char *str, size_t len)
{
    size_t i = 0;
    while (i < len -1 && str[i] == '0')
        i++;
    return (i);
}

void    print_number(const char *str, size_t start, size_t len)
{
    write(1, str + start, len - start - 1);
    write(1, "\n", 1); 
}

void    infin_mult(const char *str1, char* str2)
{
    size_t len1 = ft_strlen(str1);
    size_t len2 = ft_strlen(str2);
    size_t result_len = len1 + len2 + 1;

    char *result = (char *)malloc(sizeof(result_len));
    for (size_t i = 0; i < result_len; i++)
        result[i] = '0';
    result[result_len - 1] = '\0';

    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int digit1 = str1[i] - '0';
        for (int j = len2 - 1; j >= 0; j--)
        {
            int digit2 = str2[j] - '0';
            int product = (digit1 * digit2) + (result[i + j + 1] - '0') + carry;

            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i] += carry;
    }
    size_t start = find_start(result, result_len);
    print_number(result, start, result_len);
    free (result);
}
