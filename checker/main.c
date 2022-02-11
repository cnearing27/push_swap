#include <stdio.h>
#include "checker.h"

//int	check_solution()

int	check_right_args(char	**sol, int	i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if(sol[j] == "sa" || sol[j] == "sb" ||
			sol[j] == "ss" || sol[j] == "pa" ||
			sol[j] == "pb" || sol[j] == "ra" ||
			sol[j] == "rb" || sol[j] == "rr" ||
			sol[j] == "rra" || sol[j] == "rrb" ||
			sol[j] == "rrr")
			j++;
		else
			return (0);
	}
	return (1);
}

int	main(int	argc, char	**argv)
{
	int		arr[argc - 1];
	char	**sol;
	int		i;

	sol = NULL;
	i = 0;
	if (check_args(argc, argv, arr) == 1)
	{
		i = get_solution(open("ex.txt", O_RDONLY), sol); // не забыть поменять файл на фд = 0;
//		printf("%d", i);
//		int	j;
//		j = 0;
//		while (j < i)
//		{
//			printf("%s\n", sol[j]);
//			j++;
//		}
//		if (check_right_args(sol, 2) == 0)
//		{
//			write (2, "Error\n", 6);
//			return (0);
//		}
//		if (check_solution(sol, 2) == 1)
//			write(1, "OK\n", 3);
//		else
			write(1, "KO\n", 3);
		//проверяем иф(чек_солушн==1)
		//то выводим ок
		//если нет - КО
	}
	else
		write (2, "Error\n", 6);
	return (0);
}
