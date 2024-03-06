#ifndef EXAM_H
# define EXAM_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

void    infin(char *first, char *second);
int     is_nega(char *str);
size_t   ft_strlen(char *str);
void    print(char *result, size_t len, size_t start, int sign1, int sign2);
size_t  start(char *str, size_t len);



#endif