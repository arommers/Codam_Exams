#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str);

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return(i);
}

int main(int argc, char *argv[])
{
    
    int len = ft_strlen(argv[1]);
    int max_pal_len = 0;
    int start = 0;
    int end = 0;
    int i = 0;

    if (argc == 2)
    {
        while (i < len)
        {
            int j = i;
            int k = i;

            while (k < len - 1 && argv[1][k] == argv[1][k + 1])
                k++;
            i = k + 1;

            while (k < len - 1 && j > 0 && argv[1][k + 1] == argv[1][j - 1])
            {
                k++;
                j--;
            }

            int pal_len = k - j + 1;

            if (pal_len > max_pal_len)
            {
                max_pal_len = pal_len;
                start = j;
                end = k;
            }
        }
        i = start;
        while (i <= end) 
        {
            write (1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}