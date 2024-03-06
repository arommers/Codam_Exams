#ifndef TMP_H
# define TMP_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

void    print_numbers(const char *str, size_t start, size_t len, int sign1, int sign2);
void    infin_mult(char *str1, char* str2);
size_t  find_start(const char *str, size_t len);
size_t  ft_strlen(const char *str);


#endif