#include <stdio.h>
#include "checker.h"

char	**get_solution(int	fd)
{
	char	*curr_line;
	char	*outstr;
	char	**lines;
	int		i;

	outstr = NULL;
	curr_line = malloc(sizeof(char) * 2);
	lines = malloc(sizeof(char	*));
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
	close(fd);
	free(curr_line);
	lines = ft_split(outstr, '\n');
	return (lines);
}
