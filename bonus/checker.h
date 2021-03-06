/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:02:53 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/05 14:26:08 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

int					check_args(int argc, char	**argv, int	*arr);
char				*get_next_line(int fd);
unsigned long long	ft_strlen(char	*str);
char				*ft_strcat(char	*dest, char	*src);
char				**ft_split(char	*s, char c);
char				**get_solution(int fd);
int					str_cmp(char *str1, char *str2);
int					**do_op(char	*sol, int	**arr, int	*a_len, int *b_len);
int					**do_pb(int **arr, int	*a_len, int *b_len);
int					**do_pa(int **arr, int	*a_len, int *b_len);
void				do_ss(int	*a, int	*b, int	*a_len, int *b_len);
void				do_sa(int	*arr, int	*n);
void				do_ra(int *arr, int *len);
void				do_rr(int	**arr, int	*a_len, int *b_len);
void				do_rra(int	*arr, int	*len);
void				do_rrr(int	**arr, int	*a_len, int *b_len);
void				freee(char	**res);
void				freee_int(int	**res);
int					is_sorted(int	*arr, int a_len);
#endif
