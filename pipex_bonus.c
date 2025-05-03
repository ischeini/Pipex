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

static void	ft_last_command_process(char *argv, char **envp, int o, int i)
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

static int	ft_command_process(char **commands, char **envp, int num, int in)
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

static int	ft_here_doc(char *limiter, int argc)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1 || argc < 6)
		ft_error("here_doc");
	while (1)
	{
		line = get_next_line(0);
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
	return (fd[0]);
}

int	main(int argc, char **args, char *envp[])
{
	int	fdout;
	int	fdin;
	int	i;

	if (argc <= 4)
		ft_error("Argc");
	if (!ft_command_exist(args, envp, (argc - 1)))
		ft_error("Command");
	if (ft_strncmp(args[1], "here_doc", 8) == 0)
	{
		i = 3;
		fdout = ft_open_file(args[argc - 1], 0);
		fdin = ft_here_doc(args[2], argc);
	}
	else
	{
		i = 2;
		fdout = ft_open_file(args[argc - 1], 1);
		fdin = ft_open_file(args[1], 2);
	}
	fdin = ft_command_process(&args[i], envp, (argc - i - 2), fdin);
	ft_last_command_process(args[argc - 2], envp, fdout, fdin);
	return (0);
}
