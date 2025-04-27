/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:09:40 by ischeini          #+#    #+#             */
/*   Updated: 2025/04/18 13:09:40 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_last_command_process(char *argv, char **envp, int fdout, int in)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error("Fork");
	if (pid == 0)
	{
		dup2(in, STDIN_FILENO);
		close(in);
		dup2(fdout, STDOUT_FILENO);
		close(fdout);
		ft_execute(argv, envp);
		exit(0);
	}
	else
	{
		close(fdout);
		wait(NULL);
	}
}

static void ft_command_process(char **commands, char **envp, int num, int in)
{
	pid_t	pid;
	int		fd[2];
	int		i;

	i = -1;
	while (++i < num)
	{
		if (i < num - 1)
		{
			if (pipe(fd) == -1)
			ft_error("Pipe");
		}
		pid = fork();
		if (pid == -1)
			ft_error("Fork");
		if (pid == 0)
		{
			if (in != -1)
			{
				dup2(in, STDIN_FILENO);
				close(in);
			}
			if (i < num - 1)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
			}
			ft_execute(commands[i], envp);
			exit(0);
		}
		else
		{
			if (in != -1)
				close(in);
			if (i < num - 1)
			{
				close(fd[1]);
				in = fd[0];
			}
		}
	}
}

static int	ft_open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		ft_error("Open");
	return (file);
}

static void	ft_here_doc(char *limiter, char *here_doc, int argc)
{
	int		fd[2];
	int		fd_here_doc;
	char	*line;

	if (pipe(fd) == -1 || argc < 6)
		ft_error("here_doc");
	fd_here_doc = open(here_doc, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_here_doc == -1)
		ft_error("Open");
	while (1)
	{
		line = get_next_line(fd_here_doc);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

int	main(int argc, char **args, char *envp[])
{
	int	fdout;
	int	fdin;
	int	i;

	if (argc < 5)
		ft_error("Argc");
	if (!ft_command_exist(args, envp, (argc - 1)))
		ft_error("Command");
	if (ft_strncmp(args[1], "here_doc", 8) == 0)
	{
		i = 3;
		fdout = ft_open_file(args[argc - 1], 0);
		ft_here_doc(args[2], args[1], argc);
	}
	else
	{
		i = 2;
		fdout = ft_open_file(args[argc - 1], 1);
		fdin = ft_open_file(args[1], 2);

	}
	ft_command_process(&args[i], envp, (argc - i), fdin);
	ft_last_command_process(args[i], envp, fdout, fdin);
	return (0);
}
