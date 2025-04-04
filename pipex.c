/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:17:50 by ischeini          #+#    #+#             */
/*   Updated: 2025/04/03 11:17:50 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static pid_t	ft_pipex(pid_t pid, int f_fd, int c_fd)
{
	if (pid == 0)
	{
		dup2(f_fd, STDIN_FILENO);
		dup2(c_fd, STDOUT_FILENO);
		close(f_fd);
		close(c_fd);

		exit(EXIT_SUCCESS);
	}
	close(f_fd);
	close(c_fd);
	return (pid);
}

static pid_t	ft_open(char **args)
{
	pid_t	pid;
	int		f_fd;
	int		c_fd;

	f_fd = open(args[1], O_RDONLY);
	if (f_fd < 0 )
	{
		perror("file");
		return (-1);
	}
	c_fd = open(args[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (c_fd < 0)
	{
		close(f_fd);
		perror("file");
		return (-1);
	}
	pid = fork();
	if (!ft_pid_error(pid, f_fd, c_fd))
	{
		close(c_fd);
		close(f_fd);
		return (-1);
	}
	return (pid);
}

int	main(int argc, char **args)
{
	pid_t	pid;
	int		*pipefd;

	if (argc != 5)
	{
		errno = EINVAL;
		return (ft_errors("Number of arguments"));
	}
	pipefd = malloc(2 * sizeof(int));
	if (!pipefd)
		return (ft_errors("Malloc"));
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid = ft_open(args);
	if (pid < 0)
		return (1);
	free(pipefd);
	waitpid()
}