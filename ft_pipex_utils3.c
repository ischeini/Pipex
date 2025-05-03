/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:37:24 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/03 17:38:49 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	ft_close(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
	return (1);
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
