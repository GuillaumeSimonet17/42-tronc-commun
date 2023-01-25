/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:07:25 by gusimone          #+#    #+#             */
/*   Updated: 2023/01/20 16:39:40 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	dup2_double(int in, int out)
{
	if (dup2(in, 0) == -1)
		return (-1);
	if (dup2(out, 1) == -1)
		return (-1);
	return (0);
}

int	is_contain(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	all_dup(t_pip *p)
{
	if (p->index == 0)
	{
		if (p->err_infile == -1)
			exit(1);
		if (dup2_double(p->infile, p->pipe[1]) == -1)
			msg(-3, "", p);
	}
	else if (p->index == p->nb_cmd - 1)
	{
		if (p->err_outfile == -1)
			exit(1);
		if (dup2_double(p->pipe[2 * p->index - 2], p->outfile) == -1)
			msg(-3, "", p);
	}
	else
		if (dup2_double(p->pipe[2 * p->index - 2],
				p->pipe[2 * p->index + 1]) == -1)
			msg(-3, "", p);
}

void	ft_sleep(t_pip *p, char **env)
{
	msg(-1, p->cmd_args[0], p);
	p->cmd = "sleep";
	p->cmd_args[0] = "sleep";
	p->cmd_args[1] = "0";
	p->cmd_args[2] = 0;
	execve("/bin/sleep", p->cmd_args, env);
	ft_free_child(p);
}

void	child_process(t_pip *p, char **av, char **env)
{
	p->pid = fork();
	if (p->pid == -1)
		msg(-4, "", p);
	if (p->pid == 0)
	{
		all_dup(p);
		close_pipes(p);
		p->cmd_args = ft_split(av[2 + p->index], ' ');
		if (!p->cmd_args)
			exit(1);
		if (is_contain(p->cmd_args[0], '/') == 0)
		{
			if (!p->env_path)
				ft_sleep(p, env);
			p->cmd = get_cmd(p->cmd_paths, p->cmd_args[0]);
		}
		else
			p->cmd = p->cmd_args[0];
		if (!p->cmd || access(p->cmd, F_OK) != 0)
			ft_sleep(p, env);
		execve(p->cmd, p->cmd_args, env);
	}
}
