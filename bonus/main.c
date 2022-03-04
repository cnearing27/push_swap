#include <stdio.h>
#include "checker.h"

int	str_compare(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_solution(char **sol, int	**arr, int	a_len)
{
	int	i;
	int	b_len;

	if (a_len == 1 && !sol[0])
		return (1);
	else if (a_len == 1 && sol)
		return (0);
	b_len = 0;
	i = 0;
	while (sol[i])
	{
		arr = do_op(sol[i], arr, &a_len, &b_len);
		i++;
	}
	i = 1;
	while (i < a_len)
	{
		if (arr[0][i] > arr[0][i - 1])
			i++;
		else
			break;
	}
	if (b_len == 0 && i == a_len)
		return (1);
	return (0);
}

int	check_right_args(char	**sol)
{
	int	j;

	if (!sol)
		return (1);
	j = 0;
	while (sol[j])
	{
		if (str_compare(sol[j], "sa") ||
			str_compare(sol[j], "sb") ||
			str_compare(sol[j], "ss") ||
			str_compare(sol[j], "pa") ||
			str_compare(sol[j], "pb") ||
			str_compare(sol[j], "ra") ||
			str_compare(sol[j], "rb") ||
			str_compare(sol[j], "rr") ||
			str_compare(sol[j], "rra") ||
			str_compare(sol[j], "rrb") ||
			str_compare(sol[j], "rrr"))
			j++;
		else
			return (0);
	}
	return (1);
}

int	main(int	argc, char	**argv)
{
	char	**sol;
	int		**arr;
	int	j;

	j = 0;
	arr = malloc(sizeof (int *) * 2);
	arr[0] = (int *)malloc(sizeof(int) * (argc - 1));
	arr[1] = NULL;
	sol = NULL;
	if (check_args(argc, argv, arr[0]) == 1)
	{
		sol = get_solution(0);
		j = 0;
		if (check_right_args(sol) == 1)
		{
			if (check_solution(sol, arr, argc - 1) == 1)
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		freee(sol);
		freee_int(arr);
	}
	else
	{
		freee_int(arr);
		write (2, "Error\n", 6);
	}
	return (0);
}
