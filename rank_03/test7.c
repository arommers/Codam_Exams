/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test7.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 11:39:12 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/08 12:13:49 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stdio.h"

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	len_count(char **array)
{
	int	i = 0;
	int len = 0;
	
	while (array[i])
		len += ft_strlen(array[i++]);
	return (len);
}
char	*ft_join(char **array)
{
	char	*new;
	int		i = 0;
	int		j;
	int		k = 0;
	int		len = len_count(array);

	new = malloc(( len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (array[i])
	{
		j = 0;
		while (array[i][j])
			new[k++] = array[i][j++];
		i++;
	}
	new[k] = '\0';
	return (new);
}

int	main()
{
	char	*array[] = {"hello ", "world ", "I " "am ", "Einasu!", NULL};
	char	*new;

	new = ft_join(array);
	printf("%s\n", new);
	return (0);
}