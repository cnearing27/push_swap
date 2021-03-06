/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:20:16 by cnearing          #+#    #+#             */
/*   Updated: 2022/03/05 13:59:08 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

char	**get_solution(int fd)
{
	char	*curr_line;
	char	*outstr;
	char	**lines;
	int		i;

	outstr = NULL;
	curr_line = malloc(sizeof(char) * 2);
	lines = NULL;
	i = 1;
	while (i)
	{
		i = read(fd, curr_line, 1);
		if (i == -1)
		{
			free(curr_line);
			break ;
		}
		curr_line[i] = '\0';
		outstr = ft_strcat(outstr, curr_line);
	}
	free(curr_line);
	lines = ft_split(outstr, '\n');
	free(outstr);
	return (lines);
}

int	is_sorted(int	*arr, int a_len)
{
	int	i;

	i = 0;
	while (i < a_len - 1)
	{
		if (arr[i] < arr[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
