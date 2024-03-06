/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   multi.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 15:04:07 by arommers      #+#    #+#                 */
/*   Updated: 2024/01/31 15:53:51 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int    is_nega(char *str)
{
    if (str[0] == '-')
        return 1;
    return 0;
}

int find_start(char *str, int len)
{
    int i = 0;
    while (i < len - 1 && str[i] == '0')
        i++;
    return (i);
}

void    print_result(char *str, int len, int start, int one, int two)
{
    if (one && !two || !one && two)
        write(1, "-", 1);
    write(1, str + start, len - start);
    write(1, "\n", 1);
}

void    multi(char *first, char *second)
{
    int sign1 = is_nega(first);
    int sign2 = is_nega(second);

    char *str1 = (sign1) ? first + 1: first;
    char *str2 = (sign2) ? second + 1: second;

    int len1 = ft_strlen(str1);
    int len2 = ft_strlen(str2);
    int result_len = len1 + len2 + 1;
    char *result = malloc(result_len * sizeof(char));
    
    for(int i = 0;i  < result_len; i++)
        result[i] = '0';
    result[result_len - 1] = '\0';
    
    for (int i = len1 -1; i >= 0; i--)
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
    int start = find_start(result, result_len);
    print_result(result, result_len, start, sign1, sign2);
}

int main(int argc, char **argv)
{
    if (argc != 3)
        return 1;
    
    multi(argv[1], argv[2]);
    
    return 0;
}