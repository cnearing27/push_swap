/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:14:44 by cnearing          #+#    #+#             */
/*   Updated: 2021/12/05 20:14:44 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
char	*save_buf(char	*outstr)
{
	char	*new_out;
	int		count;
	int		start_i;

	start_i = 0;
	if (!outstr)
		return (NULL);
	while (outstr[start_i] && outstr[start_i] != '\n')
		start_i++;
	if (!outstr[start_i])
	{
		free(outstr);
		return (NULL);
	}
	new_out = malloc(sizeof(char) * (ft_strlen(outstr) - start_i + 1));
	if (!new_out)
		return (NULL);
	start_i++;
	count = 0;
	while (outstr[start_i])
		new_out[count++] = outstr[start_i++];
	new_out[count] = '\0';
	free(outstr);
	return (new_out);
}

char	*ft_crop(char	*outstr)
{
	char	*dest;
	int		i;

	if (!outstr)
		return (NULL);
	i = 0;
	while (outstr[i] && outstr[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 2));
	if (!dest)
		return (NULL);
	i = 0;
	while (outstr[i] && outstr[i] != '\n')
	{
		dest[i] = outstr[i];
		i++;
	}
	dest[i] = outstr[i];
	dest[i + 1] = '\0';
	if (dest[0] == '\0')
	{
		free(dest);
		return (NULL);
	}
	return (dest);
}

int	inc_endl(char	*outstr)
{
	int	i;

	i = 0;
	if (!outstr)
		return (0);
	while (outstr[i])
	{
		if (outstr[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int	fd)
{
	int				ret;
	char			*buf;
	static char		*outstr;

	if (fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * 2);
	if (!buf)
		return (NULL);
	ret = 1;
	while (ret && !inc_endl(outstr))
	{
		ret = read(fd, buf, 1);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		outstr = ft_strcat(outstr, buf);
	}
	free(buf);
	buf = ft_crop(outstr);
	outstr = save_buf(outstr);
	return (buf);
}
