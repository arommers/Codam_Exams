#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int ft_putchar(char x)
{
    write (1, &x, 1);
    return (1);
}

int ft_putstring(char *str)
{
    int i = 0;

    if (!str)
        str = "(null)";
    while (str[i])
    {
        write (1, &str[i], 1);
        i++;
    }
    return (i);
}

int ft_putnbr(int nbr)
{
    int     len = 0;
    long    n = nbr;
    if (n < 0)
    {
        len += write(1, "-", 1);
        n = n * -1;
    }
    if (n > 9)
    {
        len += ft_putnbr(n / 10);
        len += ft_putnbr(n % 10);
    }
    else
        len += ft_putchar(n + '0');
    return (len);
}

int ft_puthex(unsigned int nbr)
{
    int len = 0;

    if (nbr >= 16)
    {
        len += ft_puthex(nbr / 16);
        len += ft_puthex(nbr % 16);
    }
    else if (nbr > 9)
        len += ft_putchar(nbr + 87);
    else
        len += ft_putchar(nbr + '0');
    return (len);
}

int ft_printf(const char *format, ...)
{
    int     i = 0;
    int     len = 0;
    va_list arg;

    va_start(arg, format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++;
            if (format[i] == 's')
                len += ft_putstring(va_arg(arg, char *));
            else if (format[i] == 'd')
                len += ft_putnbr(va_arg(arg, int));
            else if (format [i] == 'x')
                len += ft_puthex(va_arg(arg, unsigned int));
        }
        else
        {
            if (format[i] != '%')
                len += ft_putchar(format[i]);
        }
        i++;
    }
    va_end(arg);
    return (len);
}