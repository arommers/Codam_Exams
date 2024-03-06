#include <stdio.h>
#include <stdlib.h>

void ft_free(char **array)
{
    int i = 0;
    while (array[i])
        free(array[i++]);
    free (array);    
}

int ft_len(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int count_rows(char *str)
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

char *ft_substr(char *str, int len)
{
    char    *new;
    int i = 0;

    if (!*str || !str)
        return (NULL);
    if (len > ft_len(str))
        len = ft_len(str);
    new = malloc( len * sizeof(char) + 1);
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
    int     i = 0;
    int     rows = 0;

    if (!*str || !str)
        return (NULL);
    rows = count_rows(str);
    printf("rows: %d\n", rows);
    array = malloc((rows + 1) * sizeof(char *));
    if (!array)
        return (NULL);
    while (*str) 
    {
        if (*str != ' ' && *str != '\n' && *str != '\t')
        {
            start = str;
            while (*str && (*str != ' ' && *str != '\n' && *str != '\t'))
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
    char    str[] = "hello world i am einasu";
    char    **new;
    int i = 0;

    new = ft_split(str);
    while (new[i])
        printf("%s\n", new[i++]);
    ft_free(new);
    return (0);
}