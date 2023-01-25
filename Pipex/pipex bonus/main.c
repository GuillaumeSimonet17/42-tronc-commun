/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:12:40 by gusimone          #+#    #+#             */
/*   Updated: 2023/01/02 17:12:40 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipes(t_pip *p)
{
	int	i;

	i = 0;
	while (i < p->nb_cmd - 1)
	{
		if (pipe(p->pipe + 2 * i) < 0)
			parent_free(p);
		i++;
	}
}

char	*get_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		path++;
	}
	return (NULL);
}

void	msg(int errcd, char *s, t_pip *p)
{
	if (!s)
		s = "(null)";
	if (errcd == -1)
	{
		ft_putstr_err("command not found : ");
		ft_putstr_err(s);
		ft_putstr_err("\n");
	}
	if (errcd == -2)
	{
		ft_putstr_err("permission denied: ");
		ft_putstr_err(s);
		ft_putstr_err("\n");
	}
	if (errcd == -3)
	{
		ft_putstr_err("Dup2 error\n");
		exit(1);
	}
	if (errcd == -4)
	{
		parent_free(p);
		ft_putstr_err("Fork error\n");
		exit(1);
	}
}

void	ft_processes(t_pip *p, char **argv, char **env)
{
	p->index = -1;
	while (++(p->index) < p->nb_cmd)
		child_process(p, argv, env);
	close_pipes(p);
	close(p->infile);
	close(p->outfile);
}

int	main(int argc, char **argv, char **env)
{
	t_pip	p;

	if (argc < 5)
		ft_error_argc();
	ft_get_file(&p, argv, argc);
	p.nb_cmd = argc - 3;
	p.nb_pipe = 2 * (p.nb_cmd - 1);
	p.pipe = malloc(sizeof(int) * p.nb_pipe);
	if (!p.pipe)
		close_files(&p);
	p.env_path = ft_find_path(env);
	if (p.env_path != NULL)
	{
		p.cmd_paths = ft_split(p.env_path, ':');
		if (!p.cmd_paths)
			free_pipe(&p);
	}
	else
		p.cmd_paths = NULL;
	create_pipes(&p);
	ft_processes(&p, argv, env);
	while (waitpid(-1, NULL, 0) != -1)
		;
	parent_free(&p);
	return (0);
}
