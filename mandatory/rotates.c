/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:19:33 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/04 21:01:23 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_for_push_both(int **arr, int *a_len, int	*b_len, int steps)
{
	int	new_steps;

	new_steps = steps;
	while (new_steps != 0)
	{
		if (new_steps > 0)
		{
			do_rr(arr, a_len, b_len);
			new_steps--;
		}
		else
		{
			do_rrr(arr, a_len, b_len);
			new_steps++;
		}
	}
}

void	rotate_a(int *arr, int *a_len, int steps)
{
	int	new_steps;

	new_steps = steps;
	while (new_steps != 0)
	{
		if (new_steps > 0)
		{
			do_ra(arr, a_len, "ra");
			new_steps--;
		}
		else
		{
			do_rra(arr, a_len, "rra");
			new_steps++;
		}
	}
}

void	rotate_b(int *arr, int *b_len, int steps)
{
	int	new_steps;

	new_steps = steps;
	while (new_steps != 0)
	{
		if (new_steps > 0)
		{
			do_ra(arr, b_len, "rb");
			new_steps--;
		}
		else
		{
			do_rra(arr, b_len, "rrb");
			new_steps++;
		}
	}
}

void	freee_int(int	**res)
{
	free(res[0]);
	free(res[1]);
	free(res);
}

int	sign(int i)
{
	if (i > 0)
		return (1);
	return (-1);
}
