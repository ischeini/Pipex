/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:37:24 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/04 13:42:34 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_last_command_process(char *argv, char **envp, int out, int in)
{
	pid_t	pid;
	char	*path;

	path = ft_basename_command(argv);
	if (!ft_strncmp(path, "sleep", 5))
		ft_close(in, out);
	else
	{
		pid = ft_fork();
		if (pid == 0)
		{
			if (dup2(out, STDOUT_FILENO) == -1)
				ft_error("Dup2");
			if (dup2(in, STDIN_FILENO) == -1)
				ft_error("Dup2");
			ft_close(in, out);
			ft_execute(argv, envp);
		}
		else
		{
			waitpid(pid, NULL, 0);
			ft_close(in, out);
		}
	}
}

int	ft_command_process(char **commands, char **envp, int num, int in)
{
	char	*path;
	int		fd[2];
	int		i;

	i = 0;
	while (i < num)
	{
		if (i < num)
		{
			if (pipe(fd) == -1)
				ft_error("Pipe");
		}
		path = ft_basename_command(commands[i]);
		if (!ft_strncmp(path, "sleep", 5))
			close(fd[1]);
		else
			in = ft_execute_command(commands[i], envp, fd, in);
		i++;
	}
	return (in);
}

int	ft_execute_command(char *commands, char *envp[], int *fd, int in)
{
	pid_t	pid;

	pid = ft_fork();
	if (pid == 0)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_error("Dup2");
		if (dup2(in, STDIN_FILENO) == -1)
			ft_error("Dup2");
		ft_close(fd[0], fd[1]);
		close(in);
		ft_execute(commands, envp);
	}
	else
	{
		ft_close(in, fd[1]);
		return (fd[0]);
	}
	return (0);
}

void	ft_execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = -1;
	cmd = ft_split(argv, ' ');
	if (!cmd)
		ft_error("Split");
	path = NULL;
	while (i++ && cmd[i])
	{
		path = ft_find_path(cmd[i], envp);
		if (!path)
		{
			ft_free_char_pp(cmd);
			ft_error("Path");
		}
		if (path)
			break ;
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_free_char_pp(cmd);
		ft_error("Execve");
	}
}