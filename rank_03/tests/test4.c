#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i =0;

    while (str[i])
        i++;
    return (i);
}

int str_count(char **array)
{
    int i = 0;
    int len = 0;

    if (!array || !*array || !**array)
        return (0);
    while(array[i])
        len += ft_strlen(array[i++]);
    return (len);
}

char    *ft_join(char **array)
{
    int i = 0;
    int j;
    int k = 0;
    int len = str_count(array);
    char *new;

    if (!array || !*array || !**array)
        return (NULL);
    new = malloc((len + 1) * sizeof(char));
    if (!new)
        return (NULL);
    while (array[i])
    {
        j = 0;
        while (array[i][j])
            new[k++] = array[i][j++];
        i++;
    }
    new[k] = '\0';
    return (new);
}

int main()
{
    char *array[] = {"hello ", "world ", "I ", "Einasu ", NULL};
    char    *str = ft_join(array);
    printf("%s\n", str);
    return 0;
}