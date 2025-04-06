/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:08:16 by ischeini          #+#    #+#             */
/*   Updated: 2025/04/06 16:31:04 by ischeini         ###   ########.fr       */
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
		paths++;
	}
	perror("Execute");
	exit(EXIT_FAILURE);
	return (NULL);
}

void	ft_pipe_exec(char *bin, int fd_in, int fd_out, char **env)
{
	char	**env_tmp;
	char	**args;
	char	**paths;

	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	env_tmp = env;
	while (*env_tmp)
	{
		if (ft_strncmp(*env_tmp, "PATH", 4) == 0)
			break ;
		env_tmp++;
	}
	paths = ft_split(*env_tmp + 5, ':');
	args = ft_split(bin, ' ');
	args[0] = ft_get_exec(args[0], paths);
	execve(args[0], args, env);
}

void	ft_new_f_command(char *cmd, int *p1, int *p2, char **env)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork");
		return (NULL);
	}
	if (pid == 0)
	{
		close(p2[0]);
		close(p1[1]);
		ft_pipe_exec(cmd, p1[0], p2[1], env);
	}
	ft_create_pipe(p1);
}

void	ft_new_c_command(char *cmd, int *p1, int *p2, char **env)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork");
		return (NULL);
	}
	if (pid == 0)
	{
		close(p1[0]);
		close(p2[1]);
		ft_pipe_exec(cmd, p2[0], p1[1], env);
	}
	ft_create_pipe(p2);
}

void	ft_create_pipe(int *pipex)
{
	close(pipex[0]);
	close(pipex[1]);
	pipe(pipex);
}