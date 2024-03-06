#include <stdio.h>
#include <stdlib.h>

int ft_strlen(int nbr)
{
    int len = 0;

    if (nbr < 0)
    {
        len += 1;
        nbr = nbr * -1;
    }
    if (nbr == 0)
        len = 1;
    while (nbr > 0)
    {
        nbr = nbr / 10;
        len++;
    }
    return (len);
}

char    *ft_itoa(int nbr)
{
    int     len = ft_strlen(nbr);
    char    *new = malloc((len + 1) * sizeof(char));

    new[len--] = '\0';
    if (nbr == 0)
        new[0] = '0';
    if (nbr < 0)
    {
        new[0] = '-';
        nbr = nbr * -1;
    }
    while (nbr > 0)
    {
        new[len--] = (nbr % 10) + '0';
        nbr = nbr / 10;
    }
    return (new);
}

int main()
{
    int i = 0;
    printf("%s\n", ft_itoa(i));
    return (0);
}