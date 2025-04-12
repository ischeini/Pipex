/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:08:16 by ischeini          #+#    #+#             */
/*   Updated: 2025/04/12 12:06:52 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_exec(char *cmd, char **paths)
{
	char	*path;

	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		paths++;
	}
	perror("Execute");
	exit(EXIT_FAILURE);
	return (NULL);
}

void	ft_pipe_exec(char *bin, int fd, int fileno, char **env)
{
	char	**env_tmp;
	char	**args;
	char	**paths;

	if (dup2(fd, fileno) == -1)
	{
		perror("Dup2");
		return ;
	}
	close(fd);
	env_tmp = env;
	while (*env_tmp)
	{
		if (ft_strncmp(*env_tmp, "PATH=", 5) == 0)
			break ;
		env_tmp++;
	}
	paths = ft_split(*env_tmp + 5, ':');
	args = ft_split(bin, ' ');
	args[0] = ft_get_exec(args[0], paths);
	execve(args[0], args, env);
	ft_free_char_pp(paths);
	ft_free_char_pp(args);
}

int	ft_create_pipe(int *pipex)
{
	pipe(pipex);
	if (pipe(pipex) < 0)
	{
		perror("Pipe");
		return (-1);
	}
	return (0);
}

void	ft_new_command(char **args, int *p1, char **env, int i)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork");
		return ;
	}
	if (pid == 0)
	{
		if (i > 2)
			ft_pipe_exec(args[i + 2], p1[0], STDIN_FILENO, env);
		if (i < 2 - 1)
			ft_pipe_exec(args[i + 2], p1[1], STDOUT_FILENO, env);
	}
	else
	{
		close(p1[1]);
		close(p1[0]);
		wait(NULL);
	}
}
