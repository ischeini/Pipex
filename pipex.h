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

void	ft_last_command_process(char *argv, char **envp, int o, int i);

void	ft_execute(char *argv, char **envp);

void	ft_error(char *str);

char	*ft_find_path(char *cmd, char **envp);

char	*ft_basename_command(char *path);

int		ft_command_process(char **commands, char **envp, int num, int in);

int		ft_execute_command(char *commands, char *envp[], int *fd, int in);

int		ft_command_exist(char **argv, char *envp[], int size);

int		ft_open_file(char *argv, int i);

int		ft_close(int fd1, int fd2);

int		ft_wait_child(pid_t pid);

int		ft_fork(void);

#endif