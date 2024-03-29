/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:24:48 by gstronge          #+#    #+#             */
/*   Updated: 2024/03/29 11:59:56 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_make_buffer(int fd, char *buffer, int *start, int bytes);
char	*ft_make_str(char *str, int size, int strlen);
char	*ft_str(char *buffer, char *str, int start, int strlen);
int		ft_counters(char *buffer, int *start, char *str, int strlen);
char	*ft_return(char *str, int bytes, int *start);

#endif