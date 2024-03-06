/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test15.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: adri <adri@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 21:42:17 by adri          #+#    #+#                 */
/*   Updated: 2023/05/10 22:10:47 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int	ft_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char    *fix_str(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int space = 0;
    char *new = malloc((ft_strlen(str) + 1) * sizeof(char));
    while (str[i] && ft_space(str[i]))
        i++;
    while (i < ft_strlen(str))
    {
        if (ft_space(str[i]))
            space++;
        else
        {
            if (space > 0)
            {
                while (k++ <3)
                    new[j++] = ' ';
                k = 0;
                space = 0;
            }
            new[j++] = str[i];
        }
        i++;
    }
    while (j > 0 && ft_space(new[j -1]))
        j--;
    new[j] = '\0';
    return (new);
}

int main()
{
    char *str = "    hello  world\nI\nam einasu  ";
    char *new = fix_str(str);
    printf("%s\n", new);
    return 0;
}