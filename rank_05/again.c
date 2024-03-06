#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int is_nega(char *str)
{
    if (str[0] == '-')
        return 1;
    return 0;
}

int find_start(char *str, int len)
{
    int i = 0;
    while (i < len && str[i] == '0')
        i++;
    return i;
}
void multi(char *first, char *second)
{
    int sign1 = is_nega(first);
    int sign2 = is_nega(second);

    char *str1 = (sign1) ? first + 1 : first;
    char *str2 = (sign2) ? second + 1 : second;

    if ((ft_strlen(str1) == 1 && str1[0] == '0') || (ft_strlen(str2) == 1 && str2[0] == '0'))
    {
        write (1, "0\n", 2);
        return ;
    }

    int len1 = ft_strlen(str1);
    int len2 = ft_strlen(str2);
    int len_result = len1 + len2 + 1;

    char *result = malloc(len_result * sizeof(char));
    for (int i = 0; i < len_result - 1; i++)
        result[i] = '0';
    result[len_result - 1] = '\0';

    for (int i = len1 - 1; i >= 0; i--)
    {
        int digit1 = str1[i] - '0';
        int carry = 0;
        for (int j = len2 - 1; j >= 0; j--)
        {
            int digit2 = str2[j] - '0';
            int product = (digit1 * digit2) + (result[i + j + 1] - '0') + carry;

            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i] += carry;
    }
    if (sign1 && !sign2 || !sign1 && sign2)
        write (1, "-", 1);
    int start = find_start(result, len_result);
    write (1, result + start, len_result - start);
    write (1, "\n", 1);
}

int main(int argc, char **argv)
{
    multi(argv[1], argv[2]);
    return 0;
}