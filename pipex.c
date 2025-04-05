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

static int	ft_exec_child(char **command_tmp)
{
	if (execvp(command_tmp[0], command_tmp) == -1)
	{
		perror("Execvp");
		return (-1);
	}
	return (0);
}

static pid_t	ft_check_child(char *input, char *command)
{
	char	**command_tmp;
	int		input_fd;

	input_fd = open(input, O_RDONLY);
	if (input_fd < 0)
	{
		perror("Imput");
		return (-1);
	}
	if (dup2(input_fd, STDIN_FILENO) == -1)
	{
		perror("Dup2");
		close(input_fd);
		return (-1);
	}
	close(input_fd);
	command_tmp = malloc(2 * sizeof(char *));
	if (!command_tmp)
	{
		perror("Command");
		return (-1);
	}
	command_tmp[0] = command;
	command_tmp[1] = NULL;
	return (ft_exec_child(command_tmp));
}

static pid_t	ft_open(char **args, int *pipefd)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
	{
		perror("Error fork");
		return (-1);
	}
	if (pid == 0)
	{
		if (ft_check_child(args[1], args[2]) == -1)
			return (-1);
	}
	close(pipefd[1]);
	waitpid(pid, &status, 0);
	return (0);
}

int	main(int argc, char **args)
{
	pid_t	pid;
	int		*pipefd;

	if (argc != 5)
	{
		errno = EINVAL;
		return (ft_errors("Number of arguments\n"));
	}
	pipefd = malloc(2 * sizeof(int));
	if (!pipefd)
		return (ft_errors("Malloc"));
	if (pipe(pipefd) == -1)
	{
		perror("Pipe");
		return (1);
	}
	pid = ft_open(args, pipefd);
	free(pipefd);
	if (pid == -1)
		return (1);
	return (0);
}