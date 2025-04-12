/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:17:54 by ischeini          #+#    #+#             */
/*   Updated: 2025/04/03 11:17:54 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <errno.h>
# include <sys/wait.h>

void	ft_new_command(char **args, int *p1, char **env, int i);

void	ft_pipe_exec(char *bin, int fd, int fileno, char **env);

void	ft_write_result(int argc, char **args, int *pipefd);

char	*ft_get_exec(char *cmd, char **paths);

int		ft_pid_error(pid_t pid, int p_fd, int c_fd);

int		ft_create_pipe(int *pipex);

int		ft_errors(char *str);

# endif