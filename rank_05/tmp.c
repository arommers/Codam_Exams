#include "tmp.h"

size_t  ft_strlen(const char *str)
{
    size_t i = 0;
    while(str[i])
        i++;
    return(i);
}

size_t  find_start(const char *str, size_t len)
{
    size_t i = 0;
    while(i < len - 1 && str[i] == '0')
        i++;
    return (i);
}

void    print_numbers(const char *str, size_t start, size_t len, int sign1, int sign2)
{
    if (sign1 && !sign2  || !sign1 && sign2)
        write (1, "-" , 1);
    
    write(1, str + start, len - start - 1);
    write(1, "\n", 1);
}

int is_negative(char *str)
{
    return (str[0] == '-');
}

void    infin_mult(char *str1, char *str2)
{
    int sign1 = is_negative(str1);
    int sign2 = is_negative(str2);

    char *first = (sign1) ? str1 + 1 : str1;
    char *second = (sign2) ? str2 + 1 : str2;

    
    size_t len1 = ft_strlen(first);
    size_t len2 = ft_strlen(second);
    size_t result_len = len1 + len2 + 1;

    char *result = (char *)malloc(result_len * sizeof(char *));
    for(size_t i = 0; i < result_len; i++)
        result[i] = '0';
    result[result_len - 1] = '\0';

    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int digit1 = first[i] - '0';
        for (int j = len2 - 1; j >= 0; j--)
        {
            int digit2 = second[j] - '0';
            int product = (digit1 * digit2) + (result[i + j + 1] - '0') + carry;

            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i] += carry;
    }
    size_t start = find_start(result, result_len);
    print_numbers(result, start, result_len, sign1, sign2);
    free(result);
}
