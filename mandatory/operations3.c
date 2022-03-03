#include "push_swap.h"

void	do_ra(int *arr, int *len, t_list **solution, char	*op)
{
	int i = 0;
	int	temp = arr[0];
	if (*len == 1)
		return ;
	while (i < *len - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[i] = temp;
	ft_lstadd_back(solution, ft_lstnew(op));
}

void	do_rr(int	**arr, int	*a_len, int *b_len, t_list **solution)
{
	do_ra(arr[0], a_len, solution, "");
	do_ra(arr[1], b_len, solution, "");
	ft_lstadd_back(solution, ft_lstnew("rr"));
}

void	do_rra(int	*arr, int	*len, t_list **solution, char	*op)
{
	int i = *len - 1;
	int	temp = arr[i];
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = temp;
	i = 0;
	ft_lstadd_back(solution, ft_lstnew(op));
}

void	do_rrr(int	**arr, int	*a_len, int *b_len, t_list **solution)
{
	do_rra(arr[0], a_len, solution, "");
	do_rra(arr[1], b_len, solution, "");
	ft_lstadd_back(solution, ft_lstnew("rrr"));
}
