#include "checker.h"

char	*new_string(char	*s, char	c, int	i)
{
	int		j;
	int		k;
	char	*str;

	j = i;
	k = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i - j + 2));
	if (!str)
		return (0);
	while (s[j] && s[j] != c)
	{
		str[k] = s[j];
		j++;
		k++;
	}
	str[k] = '\0';
	return (str);
}

void	freee(int	i, char	**res)
{
	while (i > 0)
	{
		i--;
		free(res[i]);
	}
	free(res);
}

void	ft_mal(char	**res, char	*s, char	c)
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	if (!res)
		return ;
	while (s[k])
	{
		while (s[k] == c)
			k++;
		if (s[k] != c && s[k])
		{
			res[i] = new_string(s, c, k);
			if (!res[i])
			{
				freee(i, res);
				return ;
			}
			i++;
			while (s[k] != c && s[k])
				k++;
		}
	}
	res[i] = NULL;
}

char	**ft_split(char	*s, char	c)
{
	char	**res;
	int		k;
	int		count_arr;

	count_arr = 0;
	k = 0;
	if (!s)
		return (0);
	while (s[k])
	{
		while (s[k] == c)
			k++;
		if (s[k] != c && s[k])
		{
			while (s[k] != c && s[k])
				k++;
			count_arr++;
		}
	}
	res = (char **)malloc(sizeof(char *) * (count_arr + 1));
	ft_mal(res,s, c);
	if (!res)
		return (NULL);
	return (res);
}
