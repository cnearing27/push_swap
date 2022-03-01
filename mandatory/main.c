#include <stdio.h>
#include "push_swap.h"

int	main(int	argc, char	**argv)
{
	t_list	*sol;
	int		i;
	int		**arr;

	arr = malloc(sizeof (int *) * 2);
	arr[0] = (int *)malloc(sizeof(int) * (argc - 1));
	arr[1] = NULL;
	sol = NULL;
	i = 0;
	if (check_args(argc, argv, arr[0]) == 1)
	{
		//тут выводтся список чисел из ARGV (./a.exe 1 2 0 3 4 5 | cat -e)
		printf("Get stack (a):\n");
		while (i < argc - 1)
		{
			printf("%d ", arr[0][i]);
			i++;
		}
		printf("\n");
		sol = solve(arr, argc - 1);
		printf("\nSolution is:\n");
		print_list(sol);
//		int	j;
//		j = 0;
//
//		//тут выводятся полученные команды (са ра рб и тд). это надо сдеать через write
//		printf("Get user solution:\n");
//		while (sol[j])
//		{
//			printf("%s\n", sol[j]);
//			j++;
//		}
	}
	else
		write (2, "Error\n", 6);
	//тут фришнуть арр и солве
	return (0);

}
