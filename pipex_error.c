/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:25:23 by mfusil            #+#    #+#             */
/*   Updated: 2022/05/11 15:09:04 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex_error(int argc, int fd_1, int fd_2)
{
	if (argc != 5)
	{
		write (STDERR_FILENO, "number of arguments invalid\n", 28);
		return (1);
	}
	if (fd_1 < 0 || fd_2 < 0)
	{
		write (STDERR_FILENO, "invalid fd\n", 11);
		return (1);
	}
	return (0);
}

int	pipex_access_error(char *path1, char *path2, char *cmd1, char *cmd2)
{
	if (!(path1 || path2))
	{
		write (2, "invalid path\n", 13);
		return (1);
	}
	if (cmd1 && cmd2 == 0)
	{
		write (2, "invalid command\n", 16);
		return (1);
	}
	return (0);
}
