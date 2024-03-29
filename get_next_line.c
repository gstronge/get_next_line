/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:34:31 by gstronge          #+#    #+#             */
/*   Updated: 2024/03/24 17:47:36 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static int	start = 0;
	static int	bytes = 0;
	char		*str;
	int			strlen;

	str = NULL;
	strlen = 0;
	while (strlen >= 0)
	{
		if (start == 0 || start == bytes || bytes == 0)
			bytes = ft_make_buffer(fd, &buffer[0], &start, bytes);
		if (bytes <= 0)
			return (ft_return(str, bytes, &start));
		str = ft_str(&buffer[start], str, start, strlen);
		if (str == NULL)
			return (NULL);
		strlen = ft_counters(&buffer[start], &start, str, strlen);
	}
	return (str);
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int	fd;

// 	fd = open("test.pdf", O_RDONLY);

// 	// get_next_line(fd);

// 	printf("%s \n-------NEW-------\n\n", get_next_line(fd));
// 	printf("%s \n-------NEW-------\n\n", get_next_line(fd));
// 	// printf("%s \n-------NEW-------\n\n", get_next_line(fd));
// 	// printf("%s \n-------NEW-------\n\n", get_next_line(fd));
// 	// printf("%s \n-------NEW-------\n\n", get_next_line(fd));
// 	// printf("%s \n-------NEW-------\n\n", get_next_line(fd));
// 	// printf("%s \n-------NEW-------\n\n", get_next_line(fd));
// 	// printf("%s \n-------NEW-------\n\n", get_next_line(fd));

// 	close(fd);
// }