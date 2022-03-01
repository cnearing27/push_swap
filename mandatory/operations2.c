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
	printf("\nAfter operation '%s' stack is:\n", op);
	int	j = 0;
	while (j < *n)
	{
		printf("%d ", arr[j]);
		j++;
	}
}

void	do_ss(int	*a, int	*b, int	*a_len, int *b_len, t_list **solution)
{
	do_sa(a, a_len, solution, "");
	do_sa(b, b_len, solution, "");
	ft_lstadd_back(solution, ft_lstnew("ss"));
	printf("\nAfter operation 'ss' stack A is:\n");
	int	j = 0;
	while (j < *a_len)
	{
		printf("%d ", a[j]);
		j++;
	}
	j = 0;
	printf("\nStack B is:\n");
	while (j < *b_len)
	{
		printf("%d ", b[j]);
		j++;
	}
}
