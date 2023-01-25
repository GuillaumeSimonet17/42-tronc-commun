/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:33:48 by gusimone          #+#    #+#             */
/*   Updated: 2023/01/20 14:06:20 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_argc(void)
{
	ft_putstr_err("number of arguments invalid\n");
	exit(1);
}

void	ft_free_child(t_pip *p)
{
	int	i;

	i = 0;
	if (p->cmd_args)
	{
		while (p->cmd_args[i])
		{
			free(p->cmd_args[i]);
			i++;
		}
		free(p->cmd_args);
	}
	free(p->cmd);
}

void	parent_free(t_pip *p)
{
	int	i;

	i = 0;
	close(p->infile);
	close(p->outfile);
	if (p->cmd_paths)
	{
		while (p->cmd_paths[i])
		{
			free(p->cmd_paths[i]);
			i++;
		}
		free(p->cmd_paths);
	}
	if (p->pipe)
		free(p->pipe);
}

void	ft_putstr_err(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}
