#include <stdlib.h>
#include <stdio.h>

int ft_strlen(int nbr)
{
    int len;
    
    if (nbr < 0)
    {
        len++;
        nbr *= -1; 
    }
    if (nbr == 0)
        len++;
    while (nbr > 0)
    {
        nbr /= 10;
        len++;
    }
    return (len);
}

char    *ft_itoa(int nbr)
{
    int len = ft_strlen(nbr);
    char *new = malloc((len + 1) * sizeof(char));
    long n = nbr;
    
    if (nbr < 0)
    {
        new[0] = '-';
        nbr *= -1;
    }
    if (nbr == 0)
        new[0] = 0;
    new[len--] = '\0';
    while (nbr > 0)
    {
        new[len--] = 48 + (nbr % 10);
        nbr /= 10;
    }
    return (new);
}

int main()
{
    long i = 84767349437643747;
    ft_itoa(i);
    printf("%ld\n", i);
    return (0);
}