/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:29:16 by gusimone          #+#    #+#             */
/*   Updated: 2023/01/20 17:00:02 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_pip *p)
{
	close(p->pipe[0]);
	close(p->pipe[1]);
}

void	close_files(t_pip *p)
{
	close(p->infile);
	close(p->outfile);
	exit(1);
}

void	free_pipe(t_pip *p)
{
	close(p->infile);
	close(p->outfile);
	free(p->pipe);
	exit(1);
}

int	ft_get_file(t_pip *p, char **argv, int argc)
{
	p->err_outfile = 0;
	p->err_infile = 0;
	p->infile = open(argv[1], O_RDONLY);
	if (p->infile == -1)
	{
		p->err_infile = -1;
		ft_putstr_err("no such file or directory: ");
		ft_putstr_err(argv[1]);
		ft_putstr_err("\n");
		p->infile = open("/dev/null", O_RDONLY);
		if (p->infile == -1)
			exit(1);
	}
	p->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (p->outfile == -1)
	{
		p->err_outfile = -1;
		msg(-2, argv[argc - 1], p);
		return (1);
	}
	return (1);
}

char	*ft_find_path(char **env)
{
	if (!env[0])
		return (NULL);
	while (ft_strncmp("PATH=", *env, 5))
	{
		env++;
		if (!*env)
			return (NULL);
	}
	return (*env + 5);
}
