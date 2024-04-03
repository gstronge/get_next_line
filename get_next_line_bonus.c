/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:34:31 by gstronge          #+#    #+#             */
/*   Updated: 2024/04/03 11:23:59 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[4096][BUFFER_SIZE + 1];
	char		*str;
	int			bytes;

	str = NULL;
	bytes = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	while (bytes >= 0)
	{
		str = ft_make_str(buffer[fd], str, &bytes);
		if (bytes == 0 && buffer[fd][0] == '\0')
			bytes = ft_make_buffer(fd, buffer[fd], str, bytes);
		if (bytes == -1)
			return (NULL);
		bytes = ft_nl_str(str, bytes);
	}
	if (str && str[0] != '\0')
		return (str);
	free (str);
	return (NULL);
}
