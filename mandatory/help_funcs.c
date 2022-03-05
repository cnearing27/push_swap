/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:19:59 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/04 20:42:16 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	*copy_arr(int *arr, int len)
{
	int	i;
	int	*new_arr;

	new_arr = malloc(sizeof(int) * len);
	if (!new_arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_arr[i] = arr[i];
		i++;
	}
	return (new_arr);
}

int	*sort_array(int *arr, int *a_len)
{
	int	i;
	int	j;
	int	temp;
	int	*new_arr;

	new_arr = NULL;
	new_arr = copy_arr(arr, *a_len);
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

int	count_correct_position(int **arr, int *a_len, int *b_len, int val)
{
	int	closest;
	int	count;

	count = ft_abs(count_steps(arr[1], *b_len, val));
	closest = find_big(arr[0], a_len, val);
	count += ft_abs(count_steps(arr[0], *a_len, closest));
	return (count);
}
