/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:37:28 by mfusil            #+#    #+#             */
/*   Updated: 2022/05/11 15:32:32 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*pipex_true_access(char *cmd, char **path)
{
	int		x;
	char	*true_access;
	char	*true_access_cmd;

	x = 0;
	while (path[x])
	{
		true_access = ft_strjoin(path[x], "/");
		true_access_cmd = ft_strjoin(true_access, cmd);
		if (access (true_access_cmd, F_OK | X_OK) == 0)
			return (true_access_cmd);
		x++;
	}
	return (NULL);
}

char	**pipex_access(char **envp)
{
	int		x;
	char	*path;
	char	**diff_path;

	x = 0;
	path = NULL;
	while (envp[x] && path == NULL)
	{
		if (envp[x][0] == 'P' && envp[x][1] == 'A')
			path = &envp[x][5];
		x++;
	}
	if (path != NULL)
	{
		diff_path = ft_split(path, ':');
		return (diff_path);
	}
	return (NULL);
}

t_format	*pipex_init_var(char **argv, char **envp)
{
	t_format	*var;

	var = malloc(sizeof(t_format));
	var->fd_1 = open(argv[1], O_RDONLY);
	var->cmd1_args = ft_split(argv[2], ' ');
	var->access_cmd1 = pipex_access(envp);
	var->path_cmd1 = pipex_true_access(var->cmd1_args[0], var->access_cmd1);
	var->fd_2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC | 0777);
	var->cmd2_args = ft_split(argv[3], ' ');
	var->access_cmd2 = pipex_access(envp);
	var->path_cmd2 = pipex_true_access(var->cmd2_args[0], var->access_cmd2);
	return (var);
}

int	main(int argc, char **argv, char **envp)
{
	t_format	*var;
	int			error;

	var = pipex_init_var(argv, envp);
	error = pipex_error(argc, var->fd_1, var->fd_2);
	error += pipex_access_error(var->path_cmd1, var->path_cmd2,
			argv[2], argv[3]);
	if (error > 0)
		return (1);
	pipe(var->pipe);
	var->child = fork();
	if (var->child == -1)
	{
		write (2, "fork error\n", 11);
		return (1);
	}
	if (var->child == 0)
		pipex_child_process(var, envp);
	else
	{
		waitpid(var->child, NULL, 0);
		pipex_parent_process(var, envp);
	}
	free(var);
}
