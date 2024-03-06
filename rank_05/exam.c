#include "exam.h"

size_t ft_strlen(char *str)
{
    size_t i = 0;
    while (str[i])
        i++;
    return (i);
}

int is_nega(char *str)
{
    return (str[0] == '-');
}

size_t  start(char *str, size_t len)
{
    size_t start = 0;
    while (start < len -1 && str[start] == '0')
        start++;
    return start;
}

void    print(char *result, size_t len, size_t start, int sign1, int sign2)
{
    if (sign1 && !sign2 || !sign1 && sign2)
        write (1, "-", 1);
    write(1, result + start, len - start - 1);
    write(1, "\n", 1);
}

void    infin(char *first, char *second)
{
    int sign1 = is_nega(first);
    int sign2 = is_nega(second);

    char *str1 = (sign1) ? first + 1 : first;
    char *str2 = (sign2) ? second + 1 : second;

    size_t len1 = ft_strlen(str1);
    size_t len2 = ft_strlen(str2);
    size_t result_len = len1 + len2 + 1;

    char *result = (char *)malloc(result_len * sizeof(char *));
    for (int i = 0; i < result_len; i++)
        result[i] = '0';
    result[result_len - 1] = '\0';

    for (int i = len1 - 1; i >= 0; i--)
    {
        int digit1 = str1[i] - '0';
        int carry = 0;
        for (int j = len2 - 1; j >= 0; j--)
        {
            int digit2 = str2[j] -'0';
            int product = (digit1 * digit2) + (result[i + j + 1] - '0' ) + carry;
            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i] += carry;
    }
    size_t start_pos = start(result, result_len);
    print(result, result_len, start_pos, sign1, sign2);
    free(result);
}

int main(int argc, char **argv)
{
    infin(argv[1], argv[2]);
    return (0);
}