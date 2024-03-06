#include <stdlib.h>
#include <stdio.h>

void    ft_free(char **array)
{
    int i = 0;

    while (array[i])
        free(array[i]);
    free(array);
}

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
    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
            i++;
        if (str[i])
            words++;
        while (str[i] && (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'))
            i++;
    }
    return (words);
}

char    *ft_substr(char *str, int len)
{
    char    *new;
    int i = 0;

    if (!str || !*str)
        return (NULL);
    if (len > ft_strlen(str))
        len = ft_strlen(str);
    new = malloc((len + 1) * sizeof(char));
    if (!new)
        return (NULL);
    while (str[i] && i < len)
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char    **ft_split(char *str)
{
    char    **array;
    char    *start;
    int     rows = 0; 
    int     i = 0;

    if (!str || !*str)
        return (NULL);
    rows = word_count(str);
    array = malloc((rows + 1) * sizeof(char *));
    if (!array)
        return (NULL);
    while (*str)
    {
        if (*str != ' ' && *str != '\t' && *str != '\n')
        {
            start = str;
            while (*str && (*str != ' ' && *str != '\t' && *str != '\n'))
                str++;
            array[i] = ft_substr(start, str - start);
            if (!array[i])
            {
                ft_free(array);
                return (NULL);
            }
            i++;
        }
        else
            str++;
    }
    array[i] = NULL;
    return (array);
}

int main()
{
    int i = 0;
    char    str[] = "Hello world i am einasu!";
    char    **new;

    new = ft_split(str);
    while (new[i])
        printf("%s\n", new[i++]);
    return (0);
}