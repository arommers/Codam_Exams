#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	count_words(char *str)
{
	int i = 0;
	int words = 0;

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
	char	*new;
	int 	i = 0;

	if (!str || !str)
		return (NULL);
	new = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new [i] = '\0';
	return (new);
}

char 	**ft_split(char *str)
{
	char	**new;
	char	*start;
	int 	i = 0;
	int		words = count_words(str);

	if (!*str || !str)
		return (NULL);
	new = malloc ((words + 1) * sizeof (char *));
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n')
		{
			start = str;
			while (*str != ' ' && *str != '\t' && *str != '\n')
				str++;
			new[i++] = ft_substr(start, str - start);
		}
		else
			str++;
	}
	new[i] = NULL;
	return (new);
}

int	main()
{
	char	**new;
	char	*str = "	Hello\n world I  am\n\n Einasu!	";
	int i = 0;

	new = ft_split(str);
	while (new[i])
		printf("%s\n", new[i++]);
	return 0;
}
