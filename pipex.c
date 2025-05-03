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

static void	ft_child_process(char **argv, char **envp, int *fd)
{
	int		filein;

	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("Dup2");
	ft_close(fd[0], fd[1]);
	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		ft_error("Open child");
	if (dup2(filein, STDIN_FILENO) == -1)
		ft_error("Dup2");
	close(filein);
	ft_execute(argv[2], envp);
	exit(0);
}

static void	ft_parent_process(char **argv, char **envp, int *fd)
{
	pid_t	pid;
	char	*path;
	int		fileout;

	path = ft_basename_command(argv[3]);
	if (!ft_strncmp(path, "sleep", 5))
		return ;
	pid = fork();
	if (pid == 0)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_error("Dup2");
		ft_close(fd[0], fd[1]);
		fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fileout == -1)
			ft_error("Open parent");
		if (dup2(fileout, STDOUT_FILENO) == -1)
			ft_error("Dup2");
		close(fileout);
		ft_execute(argv[3], envp);
		exit(0);
	}
	else
		waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char *envp[])
{
	char	*path;
	pid_t	pid;
	int		fd[2];

	if (argc != 5 || !ft_command_exist(argv, envp, (argc - 1)))
		ft_error("Command");
	if (pipe(fd) == -1)
		ft_error("Pipe");
	path = ft_basename_command(argv[2]);
	if (!ft_strncmp(path, "sleep", 5))
		ft_parent_process(argv, envp, fd);
	else
	{
		pid = ft_fork();
		if (pid == 0)
			ft_child_process(argv, envp, fd);
		else
		{
			ft_wait_child(pid);
			ft_parent_process(argv, envp, fd);
		}
	}
	ft_close(fd[0], fd[1]);
	return (0);
}
