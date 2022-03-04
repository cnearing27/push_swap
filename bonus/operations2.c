/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:20:08 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/04 19:20:09 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_sa(int	*arr, int	*n)
{
	int	temp;

	if (*n == 0 || *n == 1)
		return ;
	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}

void	do_ss(int	*a, int	*b, int	*a_len, int *b_len)
{
	do_sa(a, a_len);
	do_sa(b, b_len);
}
