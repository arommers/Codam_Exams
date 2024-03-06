/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test6.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 10:17:21 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/08 10:40:17 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_free(char **array)
{
	int i = 0;

	while (array[i])
		free(array[i++]);
	free(array);
}

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	word_count(char *str)
{
	int i = 0;
	int words = 0;

	if (!*str ||!str)
		return (0);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
			words++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	return (words);
}

char	*ft_substr(char *str, int len)
{
	int i = 0;
	char *new;

	if (!*str ||!str)
		return (NULL);
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char *str)
{
	char	**array;
	char	*start;
	int i = 0;

	if (!*str ||!str)
		return (NULL);
	array = malloc((word_count(str) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (*str)
	{
		if (*str != ' ' && *str != '\n' && *str != '\t')
		{
			start = str;
			while (*str && (*str != ' ' && *str != '\n' && *str != '\t'))
				str++;
			array[i] = ft_substr(start, str - start);
			if (!array[i])
			{
				ft_free(array);
				return (NULL);
			}
			i++;
		}
		else
			str++;
	}
	array[i] = NULL;
	return (array);
}

int	main()
{
	int i = 0;
	char	*str = "Hello	world I am\n Einasu!";
	char	**new = ft_split(str);

	while (new[i])
		printf("%s\n", new[i++]);
	return (0);
}
