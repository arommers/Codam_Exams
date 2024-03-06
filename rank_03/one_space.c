#include <unistd.h>

int is_space(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

void     fix_str(char *str)
{
    int i = 0;
    int spaces = 0;

    while (str[i])
    {
        if (is_space(str[i]))
            spaces++;
        else
        {
            if (spaces > 0)
            {
                write(1, " ", 1);
                spaces = 0;
            }
            write(1, &str[i], 1);
        }
        i++;
    }
}

int main()
{
    char *str = "   hello   world   I am EINAsu";
    fix_str(str);
    return (0);
}