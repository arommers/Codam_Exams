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

    if (!str || !*str)
        return 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
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
    char *new;
    int i = 0;

    if (!*str || !str)
        return (NULL);
    if (len > ft_strlen(str))
        len = ft_strlen(str);
    new = malloc ((len + 1) * sizeof(char));
    while (i < len)
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char    **ft_split(char *str)
{
    char    **new;
    char    *start;
    int     i = 0;
    int     rows = word_count(str);

    if (!*str || !str)
        return (NULL);
    new = malloc((rows + 1) * sizeof(char *));
    while (*str)
    {
        if (*str != ' ' && *str != '\n' && *str != '\t')
        {
            start = str;
            while (*str != ' ' && *str != '\n' && *str != '\t')
                str++;
            new[i] = ft_substr(start, str - start);
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
    int i = 0;
    char **new;
    char *str = "Hello  world\nI am  Einasu ";

    new = ft_split(str);
    while (new[i])
        printf("%s\n", new[i++]);
    return 0;
}