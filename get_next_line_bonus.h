/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:24:48 by gstronge          #+#    #+#             */
/*   Updated: 2024/04/03 12:50:16 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_copy_str(char *buffer, char *str, int buff_strlen, int old_strlen);
char	*ft_make_str(char *buffer, char *str, int *bytes);
int		ft_make_buffer(int fd, char *buffer, char *str, int bytes);
int		ft_nl_str(char *str, int bytes);
int		ft_buffer_strlen(char *buffer, int strlen);

#endif