#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;

    while(str[i])
        i++;
    return (i);
}

int ft_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    return (0);
}

char *fix_str(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int len = ft_strlen(str);
    int space = 0;
    char *new;

    if (!str || !*str)
        return (NULL);
    new = malloc ((len + 1) * sizeof(char));
    while (str[i] && ft_space(str[i]))
        i++;
    while (str[i])
    {
        if (ft_space(str[i]))
            space++;
        else
        {
            if (space > 0)
            {
                while (k++ < 3)
                    new[j++] = ' ';
                k = 0;
                space = 0;
            }
            new[j++] = str[i];
        }
        i++;
    }
    while (j > 0 && ft_space(str[j -1]))
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