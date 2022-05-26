/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:25:23 by mfusil            #+#    #+#             */
/*   Updated: 2022/05/26 17:37:04 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex_error(int fd_1, int fd_2)
{
	if (fd_1 < 0 || fd_2 < 0)
	{
		write (STDERR_FILENO, "invalid fd\n", 11);
		return (1);
	}
	return (0);
}

int	pipex_access_error(char *path1, char *path2)
{
	if (!path1 || !path2)
	{
		write (2, "invalid cmd\n", 13);
		return (1);
	}
	return (0);
}
