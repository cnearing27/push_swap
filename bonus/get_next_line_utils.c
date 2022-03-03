/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:14:38 by marvin            #+#    #+#             */
/*   Updated: 2021/12/05 20:14:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

unsigned long long	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src, int	i)
{
	int	count;

	count = 0;
	while (count < i)
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, src, i));
}

char	*ft_strcat(char	*dest, char	*src)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (dest == NULL)
		return (ft_strdup(src));
	while (dest[i])
		i++;
	while (src[j])
		j++;
	ret = malloc(sizeof(char) * (i + j + 1));
	ret = ft_strcpy(ret, dest, i + j);
	j = 0;
	while (src[j])
	{
		ret[i] = src[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	free(dest);
	return (ret);
}
