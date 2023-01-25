/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:40:35 by gusimone          #+#    #+#             */
/*   Updated: 2022/11/18 17:51:50 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2000
# endif

void	*ft_calloc( size_t elementCount, size_t elementSize);
size_t	ft_strlen(char *s);
size_t	ft_is_new_line(char *buf);
char	*ft_join(char *line, char *buf, int i);
char	*ft_buf_to_start(char *buf, int i);
char	*get_next_line(int fd);

#endif