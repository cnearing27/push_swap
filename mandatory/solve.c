#include "push_swap.h"

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

int	*sort_array(int *arr, int *a_len)
{
	int	i;
	int	j;
	int	temp;
	int	*new_arr;

	i = 0;
	new_arr = malloc(sizeof(int) * *a_len);
	while (i < *a_len)
	{
		new_arr[i] = arr[i];
		i++;
	}
	i = 0;
	while (i < *a_len - 1)
	{
		j = 0;
		while (j < *a_len - i - 1)
		{
			if (new_arr[j] > new_arr[j + 1])
			{
				temp = new_arr[j];
				new_arr[j] = new_arr[j + 1];
				new_arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (new_arr);
}

void	a_sort_three(int	*arr, t_list *solution, int	*a_len)
{
	int	min;
	int	mid;
	int	max;
	int	*sorted_a_arr = NULL;

	sorted_a_arr = sort_array(arr, a_len);
	min = sorted_a_arr[0];
	mid = sorted_a_arr[1];
	max = sorted_a_arr[2];
	if (arr[0] == max)
		do_ra(arr, a_len, &solution, "ra");
	if (arr[0] == mid)
	{
		if (arr[1] == max)
			do_rra(arr, a_len, &solution, "rra");
		else
			do_sa(arr, a_len, &solution, "sa");
		return ;
	}
	if (arr[1] == max)
	{
		do_rra(arr, a_len, &solution, "rra");
		do_sa(arr, a_len, &solution, "sa");
	}
}

void	b_sort_three(int	*arr, t_list *solution, int	*b_len)
{
	int	min;
	int	mid;
	int	max;
	int	*sorted_a_arr = NULL;

	sorted_a_arr = sort_array(arr, b_len);
	min = sorted_a_arr[0];
	mid = sorted_a_arr[1];
	max = sorted_a_arr[2];
	if (arr[0] == max)
		do_ra(arr, b_len, &solution, "rb");
	if (arr[0] == mid)
	{
		if (arr[1] == max)
			do_rra(arr, b_len, &solution, "rrb");
		else
			do_sa(arr, b_len, &solution, "sb");
		return ;
	}
	if (arr[1] == max)
	{
		do_rra(arr, b_len, &solution, "rrb");
		do_sa(arr, b_len, &solution, "sb");
	}
}

void	join_stacks(int	**arr, int	*a_len, int *b_len, t_list *solution)
{
	do_rra(arr[0], a_len, &solution, "rra");
	while (*b_len != 0)
	{
		arr = do_pa(arr, a_len, b_len, &solution);
		do_ra(arr[0], a_len, &solution, "ra");
	}
	do_ra(arr[0], a_len, &solution, "ra");
}

t_list	*mini_sort(int	**arr, int	*a_len)
{
	int		b_len;
	t_list	*solution = NULL;

	if (*a_len == 2)
	{
		do_sa(arr[0], a_len, &solution, "sa");
		return (solution);
	}
	b_len = 0;
	while (*a_len > 3)
		arr = do_pb(arr, a_len, &b_len, &solution);
	a_sort_three(arr[0], solution, a_len);
//	if (arr[1][0] > arr[1][1])
//	{
//		do_sa(arr[1], &b_len, &solution, "sb");
//		i++;
//	}
	if (b_len == 2 && !is_sorted(arr[1], b_len))
		do_sa(arr[1], &b_len, &solution, "sb");
	else if (b_len == 3)
		b_sort_three(arr[1], solution, &b_len);
	join_stacks(arr, a_len, &b_len, solution);
	int	i = 0;
	printf("\nMy programm sorted stack is:\n");
	while (i < *a_len)
	{
		printf("%d ", arr[0][i]);
		i++;
	}
	return (solution);
}

t_list	*solve(int	**arr, int	a_len)
{
	t_list *sol;

	if (is_sorted(arr[0], a_len) == 1)
		return (NULL);
	if (a_len <= 6)
		sol = mini_sort(arr, &a_len);
//	else
//		sol = big_sort(arr, a_len);
	return (sol);
}
