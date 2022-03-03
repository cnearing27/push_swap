#include "push_swap.h"

void	do_sa(int	*arr, int	*n, t_list **solution, char	*op)
{
	int	temp;

	if (*n == 0 || *n == 1)
		return ;
	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	ft_lstadd_back(solution, ft_lstnew(op));
}

void	do_ss(int	*a, int	*b, int	*a_len, int *b_len, t_list **solution)
{
	do_sa(a, a_len, solution, "");
	do_sa(b, b_len, solution, "");
	ft_lstadd_back(solution, ft_lstnew("ss"));
}
