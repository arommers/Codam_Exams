/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 13:54:43 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/24 14:01:11 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int n = nbr;
	int len = 0;
	char *str;

	if (nbr <= 0)
		len ++;
	while (n)
	{
		n /= 10;
		len++;
	}
	str = malloc((len + 1) * sizeof(char));
	str[len--] = '\0';
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		str[len--] = 48 + (nbr % 10);
		nbr /= 10;
	}
	return (str);
}

int	main()
{
	int i = 0;
	char *new = ft_itoa(i);
	printf("%s\n", new);
	return (0);
}