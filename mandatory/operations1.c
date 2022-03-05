/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:19:46 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/04 20:44:27 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ppush(int *arr, int b, int *len)
{
	int	*new_arr;
	int	i;

	new_arr = malloc(sizeof(int) * (*len));
	if (!new_arr)
		return (NULL);
	new_arr[0] = b;
	i = 1;
	while (i < *len)
	{
		new_arr[i] = arr[i - 1];
		i++;
	}
	free(arr);
	return (new_arr);
}

int	*delete_first(int *arr, int *len)
{
	int	*new_arr;
	int	i;

	new_arr = malloc(sizeof(int) * (*len));
	if (!new_arr)
		return (NULL);
	i = *len;
	while (i > 0)
	{
		new_arr[i - 1] = arr[i];
		i--;
	}
	free(arr);
	return (new_arr);
}

int	**do_pa(int **arr, int	*a_len, int *b_len)
{
	int	**arr2;

	if (b_len == 0)
		return (arr);
	arr2 = malloc(sizeof(int *) * 2);
	if (!arr2)
		return (NULL);
	*a_len = *a_len + 1;
	*b_len = *b_len - 1;
	arr2[0] = ppush(arr[0], arr[1][0], a_len);
	arr2[1] = delete_first(arr[1], b_len);
	free(arr);
	ft_putstr("pa");
	return (arr2);
}

int	**do_pb(int **arr, int	*a_len, int *b_len)
{
	int	**arr2;

	if (*a_len == 0)
		return (arr);
	arr2 = malloc(sizeof(int *) * 2);
	if (!arr2)
		return (NULL);
	*a_len = *a_len - 1;
	*b_len = *b_len + 1;
	arr2[1] = ppush(arr[1], arr[0][0], b_len);
	arr2[0] = delete_first(arr[0], a_len);
	free(arr);
	ft_putstr("pb");
	return (arr2);
}
