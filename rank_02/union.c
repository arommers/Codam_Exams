/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   union.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/06 13:23:57 by arommers      #+#    #+#                 */
/*   Updated: 2023/03/07 19:47:33 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	check_char(char *str, char x, int index);

int	check_char(char *str, char x, int index)
{
	int i = 0;

	while (i < index)
	{
		if (str[i] == x)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;

	if (argc == 3)
	{
		while (argv[1][i])
			i++;
		while (argv[2][j])
			argv[1][i++] = argv[2][j++];
		i--;
		while (k <= i)
		{
			if (check_char(argv[1], argv[1][k], k) == 0)
				write(1, &argv[1][k], 1);
			k++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
