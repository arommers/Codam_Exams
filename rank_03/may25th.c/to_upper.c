/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   to_upper.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 11:23:04 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/24 13:52:54 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	fix_str(char *str)
{
	int	i = 0;

	while (ft_space(str[i]))
		i++;
	while (str[i])
	{
		if (!ft_space(str[i + 1]) && !ft_space(str[i]))
		{
			str[i] = to_lower(str[i]);
			write(1, &str[i], 1);
		}
		else
		{
			if (ft_space(str[i + 1]) && str[i + 1] && !ft_space(str[i]))
			{
				str[i] = to_upper(str[i]);
				write (1, &str[i], 1);
				write (1, " ", 1);
			}
		}
		i++;
	}
	write (1, "\n", 1);
}

int	main()
{
	char str[] = "	 HELLo WoRLd	i Am  EINasu   ";
	fix_str(str);
	return (0);
}
