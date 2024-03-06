/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rstr_str.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 11:01:01 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/12 12:50:11 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	char		new[5000];
	int			i = 1;
	int			j;
	int			k = 0;


	if (argc <= 1)
		write (1, "\n", 1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] == ' ' || argv[i][j] == '\t')
				j++;
		while (argv[i][j])
		{
			if (!ft_isspace(argv[i][j + 1]))
			{
				new[k] = to_lower(argv[i][j++]);
				write(1, &new[k++], 1);
			}
			else if (ft_isspace(argv[i][j + 1]))
			{
				new[k] = to_upper(argv[i][j++]);
				write(1, &new[k++], 1);
			}
			else
			{
				new[k] = argv[i][j++];
				write(1, &new[k++], 1);
			}
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
