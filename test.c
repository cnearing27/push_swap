#include <stdio.h>

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

int main(void)
{
	printf("%d", ft_atoi("187887878777"));
}
