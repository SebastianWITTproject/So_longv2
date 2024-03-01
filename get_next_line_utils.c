/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: switt <switt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:27:14 by switt             #+#    #+#             */
/*   Updated: 2023/08/12 02:32:21 by switt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	fill_string(char *str, char *readstr, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (readstr[i] != '\0')
	{
		str[i] = readstr[i];
		i ++;
	}
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[i] = '\0';
	return (i);
}

char	*ft_strjoin(char *readstr, char *buffer)
{
	char	*str;

	if (!buffer)
		return (0);
	if (!readstr)
	{
		readstr = (char *)malloc(1);
		if (!readstr)
			return (0);
		readstr[0] = '\0';
	}
	str = (char *)malloc(ft_strlen(readstr) + ft_strlen(buffer) + 1);
	if (!str)
	{
		free(readstr);
		return (0);
	}
	fill_string(str, readstr, buffer);
	free(readstr);
	return (str);
}

char	*ft_strchr(const char *s, int f)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (0);
	}
	while (s[i])
	{
		if (s[i] == (char)f)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)f)
		return ((char *)(s + i));
	return (0);
}
