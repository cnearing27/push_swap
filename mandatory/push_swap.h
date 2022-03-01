#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //убрать

typedef struct s_list
{
	char			*command;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(char	*command);
void	ft_lstadd_back(t_list	**lst, t_list	*new);
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
#endif
