#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int get_len(char **array)
{
    int i = 0;
    int len = 0;
    while (array[i])
        len += ft_strlen(array[i++]);
    return(len);
}

char    *ft_join(char **array)
{
    int     i = 0;
    int     j;
    int     k = 0;
    int     len = get_len(array);

    if (!array || !*array || !**array)
        return (NULL);
    char    *str = malloc((len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    while(array[i])
    {
        j = 0;
        while (array[i][j])
            str[k++] = array[i][j++];
        i++;
    }
    str[k] = '\0';
    return (str);
}

int main()
{
    char    *array[] = {"hello ", "world ", "I ", "am ", "einasu!", NULL};
    char    *str = ft_join(array);
    printf("array: %s\n", str);
    free(str);
    return (0);
}