#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <stdio.h>		//не забыть убрать))
# include <unistd.h>
# include <fcntl.h>
int					check_args(int	argc, char	**argv, int	arr[argc - 1]);
char				*get_next_line(int	fd);
unsigned long long	ft_strlen(char	*str);
char				*ft_strcat(char	*dest, char	*src);
char				**ft_split(char	*s, char	c);
int					get_solution(int	fd, char	**lines);
#endif
