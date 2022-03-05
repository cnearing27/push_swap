/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:15:02 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/05 14:25:53 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

int	str_cmp(char *str1, char *str2)
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

int	check_solution(char **sol, int	**arr, int a_len)
{
	int	i;
	int	b_len;

	if (a_len == 1 && !sol)
		return (1);
	b_len = 0;
	i = 0;
	while (sol[i])
	{
		arr = do_op(sol[i], arr, &a_len, &b_len);
		i++;
	}
	i = 0;
	if (is_sorted(arr[0], a_len))
		i = a_len;
	if (sol)
		freee(sol);
	freee_int(arr);
	if (b_len == 0 && i == a_len)
		return (1);
	return (0);
}

int	check_right_args(char	**sol, int	**arr)
{
	int	j;

	if (!sol)
		return (1);
	j = 0;
	while (sol[j])
	{
		if (str_cmp(sol[j], "sa") || str_cmp(sol[j], "sb")
			|| str_cmp(sol[j], "ss") || str_cmp(sol[j], "pa")
			|| str_cmp(sol[j], "pb") || str_cmp(sol[j], "ra")
			|| str_cmp(sol[j], "rb") || str_cmp(sol[j], "rr")
			|| str_cmp(sol[j], "rra")
			|| str_cmp(sol[j], "rrb")
			|| str_cmp(sol[j], "rrr"))
			j++;
		else
		{
			freee_int(arr);
			freee(sol);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char	**argv)
{
	char	**sol;
	int		**arr;

	arr = malloc(sizeof (int *) * 2);
	arr[0] = (int *)malloc(sizeof(int) * (argc - 1));
	arr[1] = NULL;
	sol = NULL;
	if (check_args(argc, argv, arr[0]) == 1)
	{
		sol = get_solution(0);
		if (check_right_args(sol, arr))
		{
			if (check_solution(sol, arr, argc - 1))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		else
			write (2, "Error\n", 6);
		return (0);
	}
	else
		freee_int(arr);
	write (2, "Error\n", 6);
	return (0);
}
