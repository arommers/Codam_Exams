/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   restr_cap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 15:33:18 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/24 16:03:32 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	ft_space(char c)
{
	if (c == ' ' || c == '\t'|| c == '\n')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int i = 1;
	int j = 0;

	if (argc <= 1)
	{
		write (1, "\n", 1);
		return (0);
	}
	while (argv[i])
	{
		j = 0;
		while (ft_space(argv[i][j]))
			j++;
		while (argv[i][j])
		{
			if (!ft_space(argv[i][j + 1]) && !ft_space(argv[i][j]))
			{
				argv[i][j] = to_lower(argv[i][j]);
				write (1, &argv[i][j], 1);
			}
			else
			{
				if (ft_space(argv[i][j + 1]) && !ft_space(argv[i][j]) && argv[i][j])
				{
					argv[i][j] = to_upper(argv[i][j]);
					write (1, &argv[i][j], 1);
					write (1, " ", 1);
				}
			}
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}