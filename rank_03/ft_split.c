#include <stdlib.h>
#include <stdio.h>

void    ft_free(char **array)
{
    int i = 0;

    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

int ft_strlen(char *str)
{
    int i = 0;

    if (!str || !*str)
        return (0);
    while(str[i])
        i++;
    return (i);
}

char    *ft_substr(char *str, int len)
{
    int i = 0;
    int j = 0;
    int k = ft_strlen(str);
    char *new;

    if (!str || !*str)
        return (NULL);
    if (k <= len)
        len = k;
    new = malloc(len * sizeof(char) + 1);
    if (!new)
        return (NULL);
    while (str[i] && j < len)
        new[j++] = str[i++];
    new[j] = '\0';
    return (new);
}

int word_count(char *str, char c)
{
    int i = 0;
    int count = 0;

    if (!str || !*str)
        return(0);
    while (str[i])
    {
        while (str[i] && str[i] == c)
            i++;
        if (str[i])
            count++;
        while (str[i] && str[i] != c)
            i++;
    }
    return (count);    
}

char    **ft_split(char *str, char c)
{
    char    **new;
    char    *start;
    int    i = 0;
    int    count = word_count(str, c);
    if (!str || !*str)
        return (NULL);
    new = malloc((count + 1)* sizeof(char *));
    if (!new)
        return (NULL);
    while(*str)
    {
        if (*str != '\t' && *str != ' ' && *str != '\n')
        {
            start = str;
            while (*str && *str != c)
                str++;
            new[i] = ft_substr(start, str - start);
            if (!new[i])
            {
                ft_free(new);
                return (NULL);
            }
            i++;
        }
        else
            str++;
    }
    new[i] = NULL;
    return (new);
}

int main()
{
    char    *str = "hello world i am einasu";
    char    **new;
    int i = 0;

    new = ft_split(str, ' ');
    while (new[i])
        printf("%s\n", new[i++]);
    ft_free(new);
    return (0);
}