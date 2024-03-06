/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spaces.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 10:33:17 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/24 10:41:04 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	fix_str(char *str)
{
	int		i = 0;
	int		spaces = 0;

	if (!str)
		return ;
	while (ft_space(str[i]))
		i++;
	while (str[i])
	{
		if (ft_space(str[i]))
			spaces++;
		else
		{
			if (spaces > 0)
			{
				write(1, " ", 1);
				spaces = 0;
			}
			write(1, &str[i], 1);
		}
		i++;
	}
	write (1, "\n", 1);
}

int	main()
{
	char *str = "	 hello WORLD	I    am einasu       ";
	fix_str(str);
	return (0);
}
