#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char	*fix_str(char *str)
{
	char	*new;
	int		i = 0;
	int		j = 0;
	int		k = 0;
	int 	len =  ft_strlen(str);
	int		count = 0;

	new = malloc ((len + 1) * sizeof(char));
	if (!str || !*str)
		return (0);
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (i < len)
	{
		if (ft_isspace(str[i]))
			count++;
		else
		{
			if (count > 0)
			{
				while (k < 3)
				{
					new[j++] = ' ';
					k++;	
				}
				count = 0;
				k = 0;
			}
			new[j++] = str[i];
		}
		i++;
	}
	while (j > 0 && ft_isspace(new[j - 1]))
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