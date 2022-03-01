#include "./checker/checker.h"

int	ft_atoi(const char	*str)
{
	int				i;
	int				sign;
	long long int	num;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (num < 0 && sign == -1)
			return (0);
		if (num < 0 && sign == 1)
			return (-1);
		i++;
	}
	return (num * sign);
}

int	is_integer(unsigned char	*str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	if (j == 0)
		return (0);
	if (str[i] == '-')
	{
		if (!str[i + 1])
			return (0);
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (i != j)
		return (0);
	return (1);
}

int	check_no_repeat(int	argc, int	arr[argc])
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(int	argc, char	**argv, int	*arr)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc <= 1)
		return (0);
	while (argv[i])
	{
		if (is_integer(argv[i]) == 1)
		{
			arr[j] = ft_atoi(argv[i]);
			j++;
			i++;
		}
		else
			return (0);
	}
	if (check_no_repeat(argc - 1, arr) == 0)
		return (0);
	return (1);
}
