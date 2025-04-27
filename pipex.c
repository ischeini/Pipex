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



static int	ft_wait_child(pid_t pid)
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

static void	ft_child_process(char **argv, char **envp, int *fd)
{
	int		filein;

	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		ft_error("Open");
	dup2(filein, STDIN_FILENO);
	close(filein);
	ft_execute(argv[2], envp);
	exit(0)
}

static void	ft_parent_process(char **argv, char **envp, int *fd)
{
	pid_t	pid;
	int		fileout;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fileout == -1)
			ft_error("Open");
		dup2(fileout, STDOUT_FILENO);
		close(fileout);
		ft_execute(argv[3], envp);
		exit(0)
	}
	else
		wait(NULL);
}

int	main(int argc, char **argv, char *envp[])
{
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
		ft_error("Argc");
	if (!ft_command_exist(argv, envp, (argc - 1)))
		ft_error("Command");
	if (pipe(fd) == -1)
		ft_error("Pipe");
	pid = fork();
	if (pid == -1)
		ft_error("Fork");
	if (pid == 0)
		ft_child_process(argv, envp, fd);
	else
	{
		ft_wait_child(pid);
		ft_parent_process(argv, envp, fd);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}
