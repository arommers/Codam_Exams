/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/06 11:42:09 by arommers      #+#    #+#                 */
/*   Updated: 2023/03/06 12:34:17 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Display the characters that appear in both strings
// in the order that they appear. No duplicates.

int	check_str(char *str, char x, int index);

int	check_str(char *str, char x, int index)
{
	int	i = 0;

	while (str[i] && (i < index || index == -1))
	{
		if (str[i++] == x)
			return (1);
	}
	return (0);
}

int	main(int argc, char	**argv)
{
	int	i;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (!check_str(argv[1], argv[1][i], i)
				&& check_str(argv[2], argv[1][i], -1))
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
