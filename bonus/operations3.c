#include "checker.h"

void	do_ra(int *arr, int *len)
{
	int i = 0;
	int	temp = arr[0];
	if (!len)
		return ;
	if (*len == 1)
		return ;
	while (i < *len - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[i] = temp;
}

void	do_rr(int	**arr, int	*a_len, int *b_len)
{
	do_ra(arr[0], a_len);
	do_ra(arr[1], b_len);
}

void	do_rra(int	*arr, int	*len)
{
	int i = *len - 1;
	int	temp = arr[i];
	if (!len)
		return ;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = temp;
	i = 0;
}

void	do_rrr(int	**arr, int	*a_len, int *b_len)
{
	do_rra(arr[0], a_len);
	do_rra(arr[1], b_len);
}
