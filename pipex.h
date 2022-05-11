/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:02:09 by mfusil            #+#    #+#             */
/*   Updated: 2022/05/11 10:56:18 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct format
{
	pid_t	child;
	int		pipe[2];
	int		fd_1;
	int		fd_2;
	char	**access_cmd1;
	char	**access_cmd2;
	char	**cmd1_args;
	char	**cmd2_args;
	char	*path_cmd1;
	char	*path_cmd2;
}	t_format;

int			pipex_error(int argc, int fd_1, int fd_2);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
void		pipex_parent_process(t_format *var, char **envp);
void		pipex_child_process(t_format *var, char **envp);
int			pipex_error(int argc, int fd_1, int fd_2);
int			pipex_access_error(char *path1, char *path2,
				char *cmd1, char *cmd2);
char		*pipex_true_access(char *cmd, char **path);
char		**pipex_access(char **envp);
t_format	*pipex_init_var(char **argv, char **envp);

#endif
