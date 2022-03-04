/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:19:44 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/04 19:19:45 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(int	*arr, int	*n, t_list **solution, char	*op)
{
	int	temp;

	if (*n == 0 || *n == 1)
		return ;
	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	if (op)
		ft_lstadd_back(solution, ft_lstnew(op));
}

void	do_ss(int	*a, int	*b, int	*a_len, int *b_len, t_list **solution)
{
	do_sa(a, a_len, solution, NULL);
	do_sa(b, b_len, solution, NULL);
	ft_lstadd_back(solution, ft_lstnew("ss"));
}
