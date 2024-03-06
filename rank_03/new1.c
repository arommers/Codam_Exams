#include <stdio.h>
#include <stdlib.h>

int	ft_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}


int	ft_strlen(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return (i);
}

char	*fix_str(char *str)
{
	char	*new;
	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;
	int	len = ft_strlen(str);

	if (!str)
		return (NULL);
		new = malloc((len + 1) * sizeof (char));
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
	char *old = "	 hello\nworld  I  am\nEINASU!!   ";
	char *new = fix_str(old);

	printf("%s\n", old);
	printf("%s\n", new);
	return (0);
}
