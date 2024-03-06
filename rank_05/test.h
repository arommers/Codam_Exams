#ifndef TEST_H
# define TEST_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

size_t  ft_strlen(const char *str);
size_t  find_start(const char *str, size_t len);
void    infin_mult(const char *str1, char* str2);
void    print_number(const char *str, size_t start, size_t len);

#endif