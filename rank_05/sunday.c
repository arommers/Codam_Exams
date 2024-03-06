#include <unistd.h>

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
        {
            if (*s1 > *s2)
                return 1;
            return -1;
        }
        s1++;
        s2++;
    }
    return 0;
}

int get_add_value(char s1, char s2, int carry, char *c)
{
    char tmp = s1 + s2 - '0' + carry;
    carry  = 0;
    if (tmp > '9')
    {
        tmp -= 10;
        carry = 1;
    }
    *c = tmp;
    return carry;
}

void    add_func(char *s1, char *s2, int len1, int len2, int carry)
{
    char    tmp;
    int     c;
    if (len1 >= 0 && len2 >= 0)
    {
        c = get_add_value(s1[len1], s2[len2], carry, &tmp);
        add_func(s1, s2, --len1, --len2, c);
    }
    else if (len1 >= 0)
    {
        c = get_add_value(s1[len1], '0', carry, &tmp);
        add_func(s1, s2, --len1, --len2, c);
    }
    else if (len2 >= 0)
    {
        c = get_add_value('0', s2[len2], carry, &tmp);
        add_func(s1, s2, --len1, --len2, c);
    }
    else
    {
        if (carry)
            write(1, "1", 1);
        return ;
    }
    write(1, &tmp, 1);
}

int get_sub_value(char s1, char s2, int carry, char *c)
{
    char tmp = s1 - s2 - carry;
    if (tmp < 0)
    {
        tmp += 10;
        carry = 1;
    }
    else
        carry = 0;
    *c = tmp;
    return carry;
}


void    sub_func(char *s1, char *s2, int len1, int len2, int carry, int first)
{
    char tmp;
    if (len1 >= 0 && len2 >=0)
    {
        carry = get_sub_value(s1[len1], s2[len2], carry, &tmp);
        if (len1 == 0 && len2 == 0 && tmp == 0)
            first = 1;
        else
            first = 0;
        sub_func(s1, s2, --len1, --len2, carry, first);
    }
    else if (len1 >= 0)
    {
        carry = get_sub_value(s1[len1], '0', carry, &tmp);
        if (len1 == 0 && tmp == 0)
            first = 1;
        else
            first  = 0;
        sub_func(s1, s2, --len1, --len2, carry, first);
    }
    else if (len2 >= 0)
    {
        carry = get_sub_value('0', s2[len2], carry, &tmp);
        if (len2 == 0 && tmp == 0)
            first = 1;
        else
            first  = 0;
        sub_func(s1, s2, --len1, --len2, carry, first);
    }
    else
        return ;
    if (first)
        return ;
    tmp += '0';
    write(1, &tmp, 1);
}

void    infin_add(char *s1, char *s2)
{
    int len1 = ft_strlen(s1) - 1;
    int len2 = ft_strlen(s2) - 1;

    if (s1[0] == '-' && s2[0] == '-')
    {
        write(1, "-", 1);
        add_func(s1 + 1, s2 + 1, len1 - 1, len2 - 1, 0);
    }
    else if (s1[0] == '-')
    {
        if (len1 - 1 > len2 || (len1 - 1 == len2 && ft_strcmp(s1 + 1, s2) > 0))
        {
            write(1, "-", 1);
            sub_func(s1 + 1, s2, len1 - 1, len2, 0, 1);
        }
        else
            sub_func(s2, s1 + 1, len2, len1 - 1, 0, 1);
    }
    else if (s2[0] == '-')
    {
        if (len2 - 1 > len1 || (len2 - 1 == len1 && ft_strcmp(s2 + 1, s1) > 0))
        {
            write(1, "-", 1);
            sub_func(s2 + 1, s1, len2 - 1, len1, 0, 1);
        }
        else
            sub_func(s1, s2 + 1, len1, len2 - 1, 0, 1);
    }
    else
        add_func(s1, s2, len1, len2, 0);  
}

int main(int argc, char ** argv)
{
    infin_add(argv[1], argv[2]);
    write(1, "\n", 1);
    return 0;
}