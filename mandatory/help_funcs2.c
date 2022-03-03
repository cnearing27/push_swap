#include "push_swap.h"

int	*find_keys(int	*arr, int	*a_len)
{
	int	*keys;
	int	*sorted;

	sorted = sort_array(arr, a_len);
	keys = malloc(sizeof(int) * 3);
	keys[0] = sorted[0];
	keys[1] = sorted[(*a_len - 1) / 2];
	keys[2] = sorted[*a_len - 1];
	return (keys);
}

int	minimum(int	*arr, int	*len)
{
	int	min;
	int	min_index;
	int	i;

	i = 0;
	min = INT_MAX;
	while (i < *len)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	get_current_pos(int	*arr, int	arr_size, int	val)
{
	int	pos;

	pos = 0;
	while (pos < arr_size)
	{
		if (arr[pos] == val)
			return (pos);
		pos++;
	}
	return (0);
}

int	count_steps_to_top(int	*arr, int	arr_size, int	val)
{
	int	pos;
	int	rpos;

	pos = get_current_pos(arr, arr_size, val);
	rpos = pos - arr_size;
	if (ft_abs(pos) <= ft_abs(rpos))
		return (pos);
	return (rpos);
}

int	find_closest_big(int *arr, int *a_len, int val)
{
	int	max;
	int	i;

	i = 0;
	max = INT_MAX;
	while (i < *a_len)
	{
		if (arr[i] < max && arr[i] > val)
			max = arr[i];
		i++;
	}
	return (max);
}
