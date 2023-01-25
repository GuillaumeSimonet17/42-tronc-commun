/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:31:50 by gusimone          #+#    #+#             */
/*   Updated: 2023/01/25 14:29:30 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *line, char *buf, int i)
{
	int		j;
	int		k;
	char	*tmp;

	k = 0;
	j = ft_strlen(line);
	tmp = ft_calloc(j + i + 2, 1);
	if (!tmp)
		return (NULL);
	while (line[k])
	{
		tmp[k] = line[k];
		k++;
	}
	tmp[k + i + 1] = 0;
	while (i >= 0)
	{
		tmp[k + i] = buf[i];
		i--;
	}
	free(line);
	line = NULL;
	return (tmp);
}

char	*ft_buf_to_start(char *buf, int i)
{
	int	j;

	j = 0;
	if (buf[0] != '\0')
		i++;
	while (buf[i])
	{
		buf[j] = buf[i];
		j++;
		i++;
	}
	while (j <= i)
	{
		buf[j] = 0;
		j++;
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE < 1 || (!buf[0] && \
	(read(fd, buf, BUFFER_SIZE) < 1)))
		return (NULL);
	i = ft_is_new_line(buf);
	line = ft_calloc(i + 1, 1);
	if (!line)
		return (NULL);
	while (i == ft_strlen(buf))
	{
		line = ft_join(line, buf, i);
		if (!line)
			return (NULL);
		ft_buf_to_start(buf, i);
		if (read(fd, buf, BUFFER_SIZE) == 0)
			return (line);
		i = ft_is_new_line(buf);
	}
	line = ft_join(line, buf, i);
	ft_buf_to_start(buf, i);
	return (line);
}

int main()
{
	int fd = open("txt.txt", O_RDONLY);
	char *s = get_next_line(fd);
	printf("k");
	while(s)
	{
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
}