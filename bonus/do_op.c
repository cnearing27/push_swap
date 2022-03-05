/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:20:27 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/05 14:06:15 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	**do_op(char	*sol, int	**arr, int	*a_len, int *b_len)
{
	if (str_cmp(sol, "sa"))
		do_sa(arr[0], a_len);
	else if (str_cmp(sol, "sb"))
		do_sa(arr[1], b_len);
	else if (str_cmp(sol, "ss"))
		do_ss(arr[0], arr[1], a_len, b_len);
	else if (str_cmp(sol, "pa"))
		arr = do_pa(arr, a_len, b_len);
	else if (str_cmp(sol, "pb"))
		arr = do_pb(arr, a_len, b_len);
	else if (str_cmp(sol, "ra"))
		do_ra(arr[0], a_len);
	else if (str_cmp(sol, "rb"))
		do_ra(arr[1], b_len);
	else if (str_cmp(sol, "rr"))
		do_rr(arr, a_len, b_len);
	else if (str_cmp(sol, "rra"))
		do_rra(arr[0], a_len);
	else if (str_cmp(sol, "rrb"))
		do_rra(arr[1], b_len);
	else if (str_cmp(sol, "rrr"))
		do_rrr(arr, a_len, b_len);
	return (arr);
}
