/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:19:49 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/04 19:57:08 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int	argc, char	**argv)
{
	t_list	*sol;
	int		**arr;

	arr = malloc(sizeof (int *) * 2);
	if (!arr)
		return (0);
	arr[0] = (int *)malloc(sizeof(int) * (argc - 1));
	if (!arr[0])
		return (0);
	arr[1] = NULL;
	sol = NULL;
	if (check_args(argc, argv, arr[0]) == 1)
	{
		sol = solve(arr, argc - 1);
		print_list(sol);
		ft_lstclear(&sol);
	}
	else
		write (2, "Error\n", 6);
	return (0);
}
