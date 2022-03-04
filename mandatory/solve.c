#include "push_swap.h"
#include <stdio.h>

int	is_sorted(int	*arr, int	a_len)
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

void	a_sort_three(int	*arr, t_list **solution, int	*a_len)
{
	int	mid;
	int	max;
	int	*sorted_a_arr = NULL;

	sorted_a_arr = sort_array(arr, a_len);
	mid = sorted_a_arr[1];
	max = sorted_a_arr[2];
	free(sorted_a_arr);
	if (arr[0] == max)
		do_ra(arr, a_len, solution, "ra");
	if (arr[0] == mid)
	{
		if (arr[1] == max)
			do_rra(arr, a_len, solution, "rra");
		else
			do_sa(arr, a_len, solution, "sa");
		return ;
	}
	if (arr[1] == max)
	{
		do_rra(arr, a_len, solution, "rra");
		do_sa(arr, a_len, solution, "sa");
	}
}

void	b_sort_three(int	*arr, t_list **solution, int	*b_len)
{
	int	mid;
	int	max;
	int	*sorted_a_arr = NULL;

	sorted_a_arr = sort_array(arr, b_len);
	mid = sorted_a_arr[1];
	max = sorted_a_arr[2];
	free(sorted_a_arr);
	if (arr[0] == max)
		do_ra(arr, b_len, solution, "rb");
	if (arr[0] == mid)
	{
		if (arr[1] == max)
			do_rra(arr, b_len, solution, "rrb");
		else
			do_sa(arr, b_len, solution, "sb");
		return ;
	}
	if (arr[1] == max)
	{
		do_rra(arr, b_len, solution, "rrb");
		do_sa(arr, b_len, solution, "sb");
	}
}

t_list	*sort_five(int	**arr, int	*a_len, int min, int max)
{
	int	b_len;
	t_list *solution = NULL;

	b_len = 0;
	while (b_len < 2)
	{
		if (arr[0][0] == min || arr[0][0] == max)
			arr = do_pb(arr, a_len, &b_len, &solution);
		else
			do_ra(arr[0], a_len, &solution, "ra");
		
	}
	a_sort_three(arr[0], &solution, a_len);
	b_sort_three(arr[1], &solution, &b_len);
	arr = do_pa(arr, a_len, &b_len, &solution);
	arr = do_pa(arr, a_len, &b_len, &solution);
	if (arr[0][0] == max)
		do_ra(arr[0], a_len, &solution, "ra");
	else
	{
		do_sa(arr[0], a_len, &solution, "sa");
		do_ra(arr[0], a_len, &solution, "ra");
	}
	free(arr[0]);
	free(arr[1]);
	free(arr);
	return (solution);
}

t_list	*solve(int	**arr, int	a_len)
{
	t_list *sol = NULL;
	int		*sorted;

	sorted = sort_array(arr[0], &a_len);
	if (is_sorted(arr[0], a_len) == 1)
		return (NULL);
	else if (a_len == 2)
		do_sa(arr[0], &a_len, &sol, "sa");
	else if (a_len <= 3)
		a_sort_three(arr[0], &sol, &a_len);
	else if (a_len <= 5)
		sol = sort_five(arr, &a_len, sorted[0], sorted[a_len - 1]);
	else
		sol = big_sort(arr, &a_len);
	free(sorted);
	return (sol);
}
