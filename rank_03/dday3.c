#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int ft_getlen(char **array)
{
	int i = 0;
	int len = 0;

	while (array[i])
		len += ft_strlen(array[i++]);
	return (len);
}

char	*ft_join(char **array)
{
	int i = 0;
	int j;
	int k = 0;
	int len = ft_getlen(array);
	char	*new;

	new = malloc((len + 1) * sizeof(char));
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
	char *array[] = {"HELLO ", "world	", "I ", "am", "Einasu	!	", NULL};
	char *new = ft_join(array);
	printf("%s\n", new);
	return 0;
}