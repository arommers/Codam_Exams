#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' )
		return (1);
	return (0);
}

char	*fix_str(char *str)
{
	char	*new;
	int 	i = 0;
	int 	j = 0;
	int		spaces = 0;
	int 	len = ft_strlen(str);

	new = malloc((len + 1) * sizeof(char));
	while (ft_isspace(str[i]) && str[i])
		i++;
	while (i < len)
	{
		if (ft_isspace(str[i]))
			spaces++;
		else
		{
			if (spaces > 0)
			{
				new[j++] = ' ';
				spaces = 0;
			}
			new[j++] = str[i];
		}
		i++;
	}
	if (j > 0 && ft_isspace(new[j - 1]))
		j--;
	new[j] = '\0';
	return (new);
}

int main()
{
	char	*str = "	Hello  \nworld  I am EINASU!  \n";
	char	*new = fix_str(str);

	printf("%s\n", str);
	printf("%s\n", new);
}
