/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:34:14 by mfusil            #+#    #+#             */
/*   Updated: 2022/05/12 14:08:20 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_child_process(t_format *var, char **envp)
{
	dup2(var->fd_1, 0);
	dup2(var->pipe[1], 1);
	close(var->fd_1);
	close(var->pipe[0]);
	execve(var->path_cmd1, var->cmd1_args, envp);
}

void	pipex_parent_process(t_format *var, char **envp)
{
	dup2(var->fd_2, 1);
	dup2(var->pipe[0], 0);
	close(var->pipe[1]);
	close(var->fd_2);
	execve(var->path_cmd2, var->cmd2_args, envp);
}
