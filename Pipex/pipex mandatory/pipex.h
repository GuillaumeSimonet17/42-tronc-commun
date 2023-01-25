/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:35:47 by gusimone          #+#    #+#             */
/*   Updated: 2023/01/11 11:35:47 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"

typedef struct s_pip
{
	int		*pipe;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	char	*env_path;
	int		infile;
	int		outfile;
	int		pid;
	int		index;
	int		err_infile;
	int		err_outfile;
	int		nb_cmd;
	int		nb_pipe;
}	t_pip;

// pipex
void	create_pipes(t_pip *p);
char	*get_cmd(char **path, char *cmd);
void	msg(int errcd, char *s, t_pip *p);
void	close_pipes(t_pip *p);

// files
int		ft_get_file(t_pip *p, char **argv, int argc);
char	*ft_find_path(char **env);
void	close_files(t_pip *p);
void	free_pipe(t_pip *p);

// free_and_error
void	ft_free_child(t_pip *p);
void	parent_free(t_pip *p);
void	ft_putstr_err(char *s);
void	ft_error_argc(void);

// process
int		dup2_double(int in, int out);
int		is_contain(char *s, char c);
void	all_dup(t_pip *p);
void	child_process(t_pip *p, char **av, char **env);

#endif 