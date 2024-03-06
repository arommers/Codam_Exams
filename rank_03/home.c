/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   home.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: adri <adri@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/13 16:45:00 by adri          #+#    #+#                 */
/*   Updated: 2023/05/13 17:17:05 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

int word_count(char *str)
{
    int i = 0;
    int words = 0;

    while(str[i])
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        if (str[i])
            words++;
        while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            i++;
    }
    return (words);
}

char *ft_substr(char *str, int len)
{
    char    *new = NULL;
    int i = 0;
    
    if (len > ft_strlen(str))
        len = ft_strlen(str);
    new = malloc((len + 1) * sizeof(char));
    while (str[i] && i < len)
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
    
}

char **ft_split(char *str)
{
    char **array;
    char *start;
    int i = 0;
    int rows = word_count(str);
    if (!str)
        return(NULL);
    
    array = malloc ((rows + 1) * sizeof(char *));
    while (*str)
    {
        if (*str != ' ' && *str != '\t' && *str != '\n')
        {
            start = str;
            while (*str  && (*str != ' ' && *str != '\t' && *str != '\n'))
                str++;
             array[i++] = ft_substr(start, str - start);
        }
        else
            str++;
    }
    array[i] = NULL;
    return (array);
}

int main()
{
    char *str = "   Hello   world\n\n i am  einasu  ";
    char **new = ft_split(str);
    int i = 0;
    while (new[i])
        printf("%s\n", new[i++]);
    return (0);
}