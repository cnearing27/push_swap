/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:49:19 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/05 13:21:35 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_sorted(int	*arr, int a_len)
{
	int	i;

	i = 0;
	while (i < a_len - 1)
	{
		if (arr[i] < arr[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	a_sort_three(int	*arr, int	*a_len)
{
	int	mid;
	int	max;
	int	*sorted_a_arr;

	sorted_a_arr = NULL;
	sorted_a_arr = sort_array(arr, a_len);
	mid = sorted_a_arr[1];
	max = sorted_a_arr[2];
	free(sorted_a_arr);
	if (arr[0] == max)
		do_ra(arr, a_len, "ra");
	if (arr[0] == mid)
	{
		if (arr[1] == max)
			do_rra(arr, a_len, "rra");
		else
			do_sa(arr, a_len, "sa");
		return ;
	}
	if (arr[1] == max)
	{
		do_rra(arr, a_len, "rra");
		do_sa(arr, a_len, "sa");
	}
}

void	b_sort_three(int	*arr, int	*b_len)
{
	int	mid;
	int	max;
	int	*sorted_a_arr;

	sorted_a_arr = NULL;
	sorted_a_arr = sort_array(arr, b_len);
	mid = sorted_a_arr[1];
	max = sorted_a_arr[2];
	free(sorted_a_arr);
	if (arr[0] == max)
		do_ra(arr, b_len, "rb");
	if (arr[0] == mid)
	{
		if (arr[1] == max)
			do_rra(arr, b_len, "rrb");
		else
			do_sa(arr, b_len, "sb");
		return ;
	}
	if (arr[1] == max)
	{
		do_rra(arr, b_len, "rrb");
		do_sa(arr, b_len, "sb");
	}
}

void	sort_five(int	**arr, int	*a_len, int min, int max)
{
	int	b_len;

	b_len = 0;
	while (b_len < 2)
	{
		if (arr[0][0] == min || arr[0][0] == max)
			arr = do_pb(arr, a_len, &b_len);
		else
			do_ra(arr[0], a_len, "ra");
	}
	a_sort_three(arr[0], a_len);
	b_sort_three(arr[1], &b_len);
	arr = do_pa(arr, a_len, &b_len);
	arr = do_pa(arr, a_len, &b_len);
	if (arr[0][0] == max)
		do_ra(arr[0], a_len, "ra");
	else
	{
		do_sa(arr[0], a_len, "sa");
		do_ra(arr[0], a_len, "ra");
	}
	free(arr[0]);
	free(arr[1]);
	free(arr);
}

void	solve(int	**arr, int a_len)
{
	int		*sorted;

	sorted = sort_array(arr[0], &a_len);
	if (!is_sorted(arr[0], a_len))
	{
		if (a_len == 2)
			do_sa(arr[0], &a_len, "sa");
		else if (a_len <= 3)
			a_sort_three(arr[0], &a_len);
		else if (a_len <= 5)
		{
			sort_five(arr, &a_len, sorted[0], sorted[a_len - 1]);
			free(sorted);
			return ;
		}
		else
		{
			big_sort(arr, &a_len);
			free(sorted);
			return ;
		}
	}
	free(arr[0]);
	free(arr);
	free(sorted);
}
