/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:19:41 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/05 13:27:28 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(int *arr, int *len, char	*op)
{
	int	i;
	int	temp;

	i = 0;
	temp = arr[0];
	if (*len == 1)
		return ;
	while (i < *len - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[i] = temp;
	if (op)
		ft_putstr(op);
}

void	do_rr(int	**arr, int *a_len, int *b_len)
{
	do_ra(arr[0], a_len, NULL);
	do_ra(arr[1], b_len, NULL);
	ft_putstr("rr");
}

void	do_rra(int *arr, int *len, char	*op)
{
	int	i;
	int	temp;

	i = *len - 1;
	temp = arr[i];
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = temp;
	i = 0;
	if (op)
		ft_putstr(op);
}

void	do_rrr(int	**arr, int	*a_len, int *b_len)
{
	do_rra(arr[0], a_len, NULL);
	do_rra(arr[1], b_len, NULL);
	ft_putstr("rrr");
}
