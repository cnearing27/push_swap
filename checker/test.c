#include <stdio.h>
#include "checker.h"

int	get_solution(int	fd, char	**lines)
{
	char	*curr_line;
	char	*outstr;
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
	i = 0;
	while (lines[i])
	{
		printf("%s\n", lines[i]);
		i++;
	}
	return (i);
}
