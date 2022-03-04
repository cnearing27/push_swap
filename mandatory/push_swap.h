/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:19:35 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/04 19:25:40 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	char			*command;
	struct s_list	*next;
}	t_list;

typedef struct		s_steps
{
	int	count_a;
	int	count_b;
	int	dest_a;
	int	dest_b;
}	t_steps;

t_list	*ft_lstnew(char	*command);
void	ft_lstadd_back(t_list	**lst, t_list	*new);
void	ft_lstclear(t_list	**lst);
int		check_args(int	argc, char	**argv, int	*arr);
int		**do_pb(int **arr, int	*a_len, int *b_len, t_list **solution);
int		**do_pa(int **arr, int	*a_len, int *b_len, t_list **solution);
void	do_ss(int	*a, int	*b, int	*a_len, int *b_len, t_list **solution);
void	do_sa(int	*arr, int	*n, t_list **solution, char	*op);
void	do_ra(int *arr, int *len, t_list **solution, char	*op);
void	do_rr(int	**arr, int	*a_len, int *b_len, t_list **solution);
void	do_rra(int	*arr, int	*len, t_list **solution, char	*op);
void	do_rrr(int	**arr, int	*a_len, int *b_len, t_list **solution);
void	print_list(t_list *list);
t_list	*solve(int	**arr, int	a_len);
int		*sort_array(int *arr, int *a_len);
t_list	*big_sort(int	**arr, int	*a_len);
int		ft_abs(int a);
int		same_sign(int a, int b);
void	ft_putstr(char	*str);
int		*find_keys(int	*arr, int	*a_len);
int		minimum(int	*arr, int	*len);
void	rotate_for_push_both(int **arr, int *a_len, int	*b_len, int steps, t_list *sol);
void	rotate_a(int *arr, int *a_len, int steps, t_list *sol);
void	rotate_b(int *arr, int *b_len, int steps, t_list *sol);
int		find_closest_big(int *arr, int *a_len, int val);
int		count_steps_to_top(int	*arr, int	arr_size, int	val);
int		get_current_pos(int	*arr, int	arr_size, int	val);
int		count_correct_position(int	**arr, int *a_len, int *b_len, int	val);
void	freee_int(int	**res);
#endif