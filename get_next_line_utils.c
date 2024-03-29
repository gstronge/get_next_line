/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:25:19 by gstronge          #+#    #+#             */
/*   Updated: 2024/03/25 11:32:04 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_make_buffer(int fd, char *buffer, int *start, int bytes)
{
	bytes = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while (bytes <= BUFFER_SIZE)
	{
		buffer[bytes] = '\0';
		bytes++;
	}
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
		return (-1);
	if (bytes == 0)
		return (-2);
	*start = 0;
	return (bytes);
}

char	*ft_make_str(char *str, int size, int strlen)
{
	char	*newstr;
	int		i;

	newstr = NULL;
	i = 0;
	newstr = (char *)malloc(size * sizeof(char));
	if (newstr == NULL)
	{
		free (str);
		return (NULL);
	}
	if (strlen > 0)
	{
		while (str[i] != '\0' && str[i] != '\n')
		{
			newstr[i] = str[i];
			i++;
		}
	}
	newstr[size - 1] = '\0';
	free (str);
	return (newstr);
}

char	*ft_str(char *buffer, char *str, int start, int strlen)
{
	int	copylen;

	copylen = 0;
	if (start < 0)
		return (NULL);
	while (buffer[copylen] != '\0' && buffer[copylen] != '\n')
		copylen++;
	if (buffer[copylen] == '\n')
		copylen++;
	str = ft_make_str(str, (strlen + copylen + 1), strlen);
	if (str == NULL)
		return (NULL);
	copylen = 0;
	while (buffer[copylen] != '\0' && buffer[copylen] != '\n')
	{
		str[strlen + copylen] = buffer[copylen];
		copylen++;
	}
	str[strlen + copylen] = buffer[copylen];
	return (str);
}

int	ft_counters(char *buffer, int *start, char *str, int strlen)
{
	int	i;

	i = 0;
	while (str[strlen] != '\n' && str[strlen] != '\0')
		strlen++;
	if (str[strlen] == '\n')
		strlen = -1;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	*start = *start + i;
	return (strlen);
}

char	*ft_return(char *str, int bytes, int *start)
{
	if (bytes == -1)
	{
		*start = 0;
		if (str)
			free (str);
		return (NULL);
	}
	if (bytes == -2)
	{
		*start = 0;
		return (str);
	}
	return (str);
}
