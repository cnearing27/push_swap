#include "push_swap.h"

int	**mid_to_top(int	**arr, int	*a_len, int	*b_len, int	mid, t_list **sol)
{
	int	steps;
	int	i;

	steps = count_steps_to_top(arr[0], *a_len, mid);
	i = 0;
	if (steps > 0)
	{
		while (i < ft_abs(steps))
		{
			do_ra(arr[0], a_len, sol, "ra");
			i++;
		}
	}
	else if (steps < 0)
	{
		while (i < ft_abs(steps))
		{
			do_rra(arr[0], a_len, sol, "rra");
			i++;
		}
	}
	arr = do_pb(arr, a_len, b_len, sol);
	return (arr);
}

int	**push_all(int **arr, int *a_len, int *b_len, int *keys, t_list *sol)
{
	while (*a_len != 2)
	{
		if (arr[0][0] != keys[0] && arr[0][0] != keys[2])
		{
			arr = do_pb(arr, a_len, b_len, &sol);
			if (arr[0][0] > keys[1])
				do_ra(arr[1], b_len, &sol, "rb");
		}
		else
			do_ra(arr[0], a_len, &sol, "ra");
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

int	**large_push_min_flag(int **arr, int *a_len, int *b_len, int	*flags, t_list *sol)
{
	int	steps[2];
	int	min_flag_ind;

	min_flag_ind = minimum(flags, b_len);
	steps[1] = count_steps_to_top(arr[1], *b_len, arr[1][min_flag_ind]);
	steps[0] = count_steps_to_top(arr[0], *a_len, find_closest_big(arr[0], a_len, arr[1][min_flag_ind]));
	if ((steps[0] > 0 && steps[1] > 0) || (steps[0] < 0 && steps[1] < 0))
	{
		if (ft_abs(steps[0]) >= ft_abs(steps[1]))
		{
			rotate_for_push_both(arr, a_len, b_len, steps[1], sol);
			steps[0] += ft_abs(steps[1]);
			steps[1] = 0;
		}
		else
		{
			rotate_for_push_both(arr, a_len, b_len, steps[0], sol);
			steps[1] += ft_abs(steps[0]);
			steps[0] = 0;
		}
	}
	rotate_a(arr[0], a_len, steps[0], sol);
	rotate_b(arr[1], b_len, steps[1], sol);
	arr = do_pa(arr, a_len, b_len, &sol);
	return (arr);
}

t_list	*big_sort(int	**arr, int	*a_len)
{
	int		*keys;
	int		b_len;
	t_list	*sol = NULL;
	int		*flags = NULL;

	b_len = 0;
	keys = find_keys(arr[0], a_len);
	arr = mid_to_top(arr, a_len, &b_len, keys[1], &sol);
	arr = push_all(arr, a_len, &b_len, keys, sol);
	while (b_len != 0)
	{
		flags = count_flags(arr, a_len, &b_len);
		arr = large_push_min_flag(arr, a_len, &b_len, flags, sol);
		free(flags);
		flags = NULL;
	}
	rotate_a(arr[0], a_len, count_steps_to_top(arr[0], *a_len, keys[0]), sol);
	free(keys);
	free(flags);
	return (sol);
}
