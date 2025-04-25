/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:08:16 by ischeini          #+#    #+#             */
/*   Updated: 2025/04/25 18:36:32 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	if (!errno)
		errno = EINVAL;
	perror(str);
	exit(errno);
}

static char	*ft_find_command(char **paths, char *cmd)
{
	char	*part_path;
	char	*path;
	int		i;

	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, X_OK) == 0)
		{
			ft_free_char_pp(paths);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_char_pp(paths);
	return (NULL);
}

static int	ft_path_exist(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	i = ft_path_exist(envp);
	if (i == -1)
		return (NULL);
	if ((cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
		&& access(cmd, X_OK) == 0)
		return (cmd);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	path = ft_find_command(paths, cmd);
	return (path);
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
