#include <stdio.h>

int check_ana(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int count[128] = {0};

    while (s1[i])
        count[s1[i++]]++;
    i = 0;
    while (s2[i])
        count[s2[i++]]--;
    while (j < 128)
    {
        if (count[j] != 0)
            return (1);
            j++;
    }
    return (0);
}

int main(void)
{
    char s1[] = "tttaa";
    char s2[] = "aaatt";

    if (check_ana(s1, s2) == 1)
        printf("not ana\n");
    else
        printf("ana\n");
    return (0);
}