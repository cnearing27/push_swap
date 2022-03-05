/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:19:35 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/04 21:01:27 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		check_args(int argc, char	**argv, int	*arr);
int		**do_pb(int **arr, int	*a_len, int *b_len);
int		**do_pa(int **arr, int	*a_len, int *b_len);
void	do_ss(int	*a, int	*b, int	*a_len, int *b_len);
void	do_sa(int	*arr, int	*n, char	*op);
void	do_ra(int *arr, int *len, char	*op);
void	do_rr(int	**arr, int	*a_len, int *b_len);
void	do_rra(int	*arr, int	*len, char	*op);
void	do_rrr(int	**arr, int	*a_len, int *b_len);
void	solve(int	**arr, int a_len);
int		*sort_array(int *arr, int *a_len);
void	big_sort(int	**arr, int	*a_len);
int		ft_abs(int a);
int		same_sign(int a, int b);
void	ft_putstr(char	*str);
int		*find_keys(int	*arr, int	*a_len);
int		minimum(int	*arr, int	*len);
void	rotate_for_push_both(int **arr, int *a_len, int	*b_len, int steps);
void	rotate_a(int *arr, int *a_len, int steps);
void	rotate_b(int *arr, int *b_len, int steps);
int		find_big(int *arr, int *a_len, int val);
int		count_steps(int	*arr, int arr_size, int val);
int		get_current_pos(int *arr, int arr_size, int val);
int		count_correct_position(int	**arr, int *a_len, int *b_len, int val);
void	freee_int(int	**res);
int		sign(int i);
#endif