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
	printf("\nAfter operation '%s' stack is:\n", op);
	int	j = 0;
	while (j < *len)
	{
		printf("%d ", arr[j]);
		j++;
	}
}

void	do_rr(int	**arr, int	*a_len, int *b_len, t_list **solution)
{
	do_ra(arr[0], a_len, solution, "");
	do_ra(arr[1], b_len, solution, "");
	ft_lstadd_back(solution, ft_lstnew("rr"));
	printf("\nAfter operation 'rr' stack A is:\n");
	int	j = 0;
	while (j < *a_len)
	{
		printf("%d ", arr[0][j]);
		j++;
	}
	j = 0;
	printf("\nStack B is:\n");
	while (j < *b_len)
	{
		printf("%d ", arr[1][j]);
		j++;
	}
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
	printf("\nAfter operation '%s' stack is:\n", op);
	int	j = 0;
	while (j < *len)
	{
		printf("%d ", arr[j]);
		j++;
	}
}

void	do_rrr(int	**arr, int	*a_len, int *b_len, t_list **solution)
{
	do_rra(arr[0], a_len, solution, "");
	do_rra(arr[1], b_len, solution, "");
	ft_lstadd_back(solution, ft_lstnew("rrr"));
	printf("\nAfter operation 'rrr' stack A is:\n");
	int	j = 0;
	while (j < *a_len)
	{
		printf("%d ", arr[0][j]);
		j++;
	}
	j = 0;
	printf("\nStack B is:\n");
	while (j < *b_len)
	{
		printf("%d ", arr[1][j]);
		j++;
	}
}
