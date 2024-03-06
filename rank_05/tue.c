#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int i  = 0;
    while( s[i])
        i++;
    return i;
}

int is_nega(char *s)
{
    if (s[0] == '-')
        return 1;
    return 0;
}

int find_start(char *s, int len)
{
    int i = 0;
    while (i < len && s[i] == '0')
        i++;
    return i;
}

void    infin_add(char *str1, char *str2)
{
    int sign1 = is_nega(str1);
    int sign2 = is_nega(str2);

    char *s1 = (sign1) ? str1 + 1 : str1;
    char *s2 = (sign2) ? str2 + 1 : str2;

    if ((ft_strlen(s1) == 1 && s1[0] == '0') || (ft_strlen(s2) == 1 && s2[0] == '0'))
    {
        write(1, "0", 1);
        return ;
    }

    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);
    int len_result = len1 + len2 + 1;

    char *result = malloc(len_result * sizeof(char));
    for (int i = 0; i < len_result - 1; i++)
        result[i] = '0';
    result[len_result - 1] = '\0';

    for (int i = len1 - 1; i >= 0; i--)
    {
        int d1 = s1[i] - '0';
        int carry = 0;
        for (int j = len2 - 1; j >= 0; j--)
        {
            int d2 = s2[j] - '0';
            int product = (d1 * d2) + (result[i + j + 1] - '0') + carry;

            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i] += carry;
    }
    if ((sign1 && !sign2) || (!sign1 && sign2))
        write(1, "-", 1);

    int start = find_start(result, len_result);
    write(1, result + start, len_result - start);
}

int main(int argc, char **argv)
{
    infin_add(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}