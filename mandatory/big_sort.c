/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:20:02 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/05 14:05:27 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**mid_to_top(int **arr, int *a_len, int *b_len, int mid)
{
	int	steps;
	int	i;

	steps = count_steps(arr[0], *a_len, mid);
	i = 0;
	if (steps > 0)
	{
		while (i < ft_abs(steps))
		{
			do_ra(arr[0], a_len, "ra");
			i++;
		}
	}
	else if (steps < 0)
	{
		while (i < ft_abs(steps))
		{
			do_rra(arr[0], a_len, "rra");
			i++;
		}
	}
	arr = do_pb(arr, a_len, b_len);
	return (arr);
}

int	**push_all(int **arr, int *a_len, int *b_len, int *keys)
{
	while (*a_len != 2)
	{
		if (arr[0][0] != keys[0] && arr[0][0] != keys[2])
		{
			arr = do_pb(arr, a_len, b_len);
			if (arr[0][0] > keys[1])
				do_ra(arr[1], b_len, "rb");
		}
		else
			do_ra(arr[0], a_len, "ra");
	}
	return (arr);
}

int	*count_flags(int **arr, int *a_len, int *b_len)
{
	int	i;
	int	*flags;

	i = 0;
	flags = malloc(sizeof(int) * (*b_len));
	while (i < *b_len)
	{
		flags[i] = 0;
		i++;
	}
	i = 0;
	while (i < *b_len)
	{
		flags[i] = count_correct_position(arr, a_len, b_len, arr[1][i]);
		i++;
	}
	return (flags);
}

int	**large_push_min_flag(int **arr, int *a_len, int *b_len, int	*flags)
{
	int	steps[2];

	steps[1] = count_steps(arr[1], *b_len, arr[1][minimum(flags, b_len)]);
	steps[0] = count_steps(arr[0], *a_len, find_big(arr[0], a_len,
				arr[1][minimum(flags, b_len)]));
	if ((steps[0] > 0 && steps[1] > 0) || (steps[0] < 0 && steps[1] < 0))
	{
		if (ft_abs(steps[0]) >= ft_abs(steps[1]))
		{
			rotate_for_push_both(arr, a_len, b_len, steps[1]);
			steps[0] = (ft_abs(steps[0]) - ft_abs(steps[1])) * sign(steps[0]);
			steps[1] = 0;
		}
		else
		{
			rotate_for_push_both(arr, a_len, b_len, steps[0]);
			steps[1] = (ft_abs(steps[1]) - ft_abs(steps[0])) * sign(steps[0]);
			steps[0] = 0;
		}
	}
	rotate_a(arr[0], a_len, steps[0]);
	rotate_b(arr[1], b_len, steps[1]);
	arr = do_pa(arr, a_len, b_len);
	return (arr);
}

void	big_sort(int	**arr, int	*a_len)
{
	int		*keys;
	int		b_len;
	int		*flags;

	flags = NULL;
	b_len = 0;
	keys = find_keys(arr[0], a_len);
	arr = mid_to_top(arr, a_len, &b_len, keys[1]);
	arr = push_all(arr, a_len, &b_len, keys);
	while (b_len != 0)
	{
		flags = count_flags(arr, a_len, &b_len);
		arr = large_push_min_flag(arr, a_len, &b_len, flags);
		free(flags);
		flags = NULL;
	}
	rotate_a(arr[0], a_len, count_steps(arr[0], *a_len, keys[0]));
	free(keys);
	free(arr[0]);
	free(arr[1]);
	free(arr);
}
