/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mon.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: adri <adri@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 14:01:16 by adri          #+#    #+#                 */
/*   Updated: 2023/05/15 17:43:44 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    return (0);
}

int main()
{
    char    str[1000] = "   hello\nworld\n\nI   am Einasu   ";
    char    new[5000];
    int     spaces = 0;
    int     i = 0;
    int     j = 0;
    int     k = 0;

    while (ft_space(str[i]))
        i++;
    while (str[i])
    {
        if (ft_space(str[i]))
            spaces++;
        else
        {
            if (spaces > 0)
            {
                while (k++ < 3)
                    new[j++] = ' ';
                k = 0;
                spaces = 0;
            }
            new[j++] = str[i];
        }
        i++;
    }
    while (j > 0 && ft_space(new[j - 1]))
        j--;
    new[j] = '\0';
    printf("%s\n", new);
    return (0);
}