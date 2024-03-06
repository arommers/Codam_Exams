#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	ft_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char *fix_str(char * str)
{
	char *new;
	int count = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	new = malloc((ft_strlen(str) + 1) * sizeof(char));
	while (str[i] && ft_space(str[i]))
		i++;
	while (str[i])
	{
		if (ft_space(str[i]))
			count++;
		else
		{
			if (count > 0)
			{
				while (k++ < 3)
					new[j++] = ' ';
				k = 0;
				count = 0;
			}
			new[j++] = str[i];
		}
		i++;
	}
	while (j > 0 && ft_space(new[j - 1]))
		j--;
	new[j] = '\0';
	return (new);
}
int	main()
{
	char *str = "Hello world I am Einasu";
	char *new = fix_str(str);

	printf("%s\n", str);
	printf("%s\n", new);
}