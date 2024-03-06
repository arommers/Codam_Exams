#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int get_len(char **array)
{
	int i = 0;
	int len = 0;

	while (array[i])
		len += ft_strlen(array[i++]);
	return (len);
}

char	*ft_join(char **array)
{
	char *new;
	int len = get_len(array);
	int i = 0;
	int j = 0;
	int k = 0;

	new = malloc((len + 1) * sizeof(char));
	while (array[i])
	{
		while (array[i][j])
			new[k++] = array[i][j++];
		j = 0;
		i++;
	}
	new[k] = '\0';
	return (new);
}

int main()
{
    char    *array[] = {"hello ", "world ", "I ", "am ", "einasu!", NULL};
    char    *str = ft_join(array);
    printf("array: %s\n", str);
    free(str);
    return (0);
}