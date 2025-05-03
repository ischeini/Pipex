/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:37:24 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/03 18:58:00 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_last_command_process(char *argv, char **envp, int o, int i)
{
	pid_t	pid;
	char	*path;

	path = ft_basename_command(argv);
	if (!ft_strncmp(path, "sleep", 5))
		ft_close(i, o);
	else
	{
		pid = ft_fork();
		if (pid == 0)
		{
			if ((dup2(o, STDOUT_FILENO) == -1) && (dup2(i, STDIN_FILENO) == 0))
				ft_error("Dup2");
			ft_close(i, o);
			ft_execute(argv, envp);
			exit(0);
		}
		else
		{
			waitpid(pid, NULL, 0);
			ft_close(i, o);
		}
	}
}

int	ft_command_process(char **commands, char **envp, int num, int in)
{
	char	*path;
	int		fd[2];
	int		i;

	i = -1;
	while (++i < num)
	{
		if (i < num)
		{
			if (pipe(fd) == -1)
				ft_error("Pipe");
		}
		path = ft_basename_command(commands[i]);
		if (!ft_strncmp(path, "sleep", 5))
			continue ;
		else
			in = ft_execute_command(commands[i], envp, fd, in);
	}
	return (in);
}

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error("Pid");
	return (pid);
}

int	ft_wait_child(pid_t pid)
{
	int	status;
	int	exit_status;

	status = 0;
	waitpid(pid, &status, WNOHANG);
	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		if (exit_status != 0)
			ft_error("Inside child");
	}
	return (0);
}

int	ft_execute_command(char *commands, char *envp[], int *fd, int i)
{
	pid_t	pid;

	pid = ft_fork();
	if (pid == 0)
	{
		if ((dup2(fd[1], STDOUT_FILENO) == -1) && (dup2(i, STDIN_FILENO) == 0))
			ft_error("Dup2");
		ft_close(fd[0], fd[1]);
		close(i);
		ft_execute(commands, envp);
		exit(0);
	}
	else
	{
		ft_wait_child(pid);
		ft_close(i, fd[1]);
		i = fd[0];
	}
	return (i);
}
