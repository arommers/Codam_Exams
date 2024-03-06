#include <stdlib.h>
#include <stdio.h>

void    ft_free(char **array)
{
    int i = 0;

    while (array[i])
        free(array[i++]);
    free(array);
}
int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int count_rows(char *array)
{
    int i = 0;
    int rows = 0;
    if (!*array || !array)
        return (0);
    while (array[i])
    {
        while (array[i] && (array[i] == '\t' || array[i] == ' ' || array[i] == '\n'))
            i++;
        if (array[i])
            rows++;
        while (array[i] && (array[i] != '\t' && array[i] != ' ' && array[i] != '\n'))
            i++;
    }
    return (rows);
}

char    *ft_substr(char *str, int len)
{
    char    *new;
    int     i = 0;

    if (!*str || !str)
        return (NULL);
    if (len > ft_strlen(str))
        len = ft_strlen(str);
    new = malloc((len + 1) * sizeof(char));
    if (!new)
        return (NULL);
    while(str[i] && i < len)
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
    int     words = 0;   
    int     i = 0;

    if (!str || !*str)
        return (NULL);
    words = count_rows(str);
    array = malloc((words + 1) * sizeof(char *));
    if (!array)
        return (NULL);
    while (*str)
    {
        if (*str != '\n' && *str != '\t' && *str != ' ')
        {
            start = str;
            while (*str && (*str != '\n' && *str != '\t' && *str != ' '))
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
    char    str[] = "hello world    i  am\neinasu";
    char    **new;
    int i = 0;

    new = ft_split(str);
    while (new[i])
        printf("%s\n", new[i++]);
    ft_free(new);
    return (0);
}