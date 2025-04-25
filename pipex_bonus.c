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

static void	ft_command_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error("Pipe");
	pid = fork();
	if (pid == -1)
		ft_error("Fork");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_execute(argv, envp);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
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

static void	ft_here_doc(char *limiter, int here_doc, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1 || argc < 6)
		ft_error("Here_doc");
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		line = get_next_line(here_doc);
		while (line)
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter - 1)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
			line = get_next_line(here_doc);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

int	main(int argc, char **args, char *envp[])
{
	int	fdout;
	int	fdin;
	int	i;

	if (argc < 5)
		ft_error("Open");
	if (ft_strncmp(args[1], "here_doc", 8) == 0)
	{
		i = 3;
		fdout = ft_open_file(args[argc - 1], 0);
		ft_here_doc(args[2], fdout, argc);
	}
	else
	{
		i = 2;
		fdout = ft_open_file(args[argc - 1], 1);
		fdin = ft_open_file(args[1], 2);
		dup2(fdin, STDIN_FILENO);
	}
	while (i < (argc - 1))
		ft_command_process(args[i++], envp);
	return (0);
}
