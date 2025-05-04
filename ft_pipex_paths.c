/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:08:16 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/04 13:26:18 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_basename_command(char *path)
{
	char	*base;
	char	*p;

	base = path;
	p = path;
	while (*p != '\0')
	{
		if (*p == '/')
			base = p + 1;
		p++;
	}
	return (base);
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
		if (!part_path)
			return (NULL);
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (!path)
			return (NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
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

char	*ft_find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	i = ft_path_exist(envp);
	if (i == -1 || (!cmd || cmd[0] == '\0'))
		return (NULL);
	if ((cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
		&& access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	path = ft_find_command(paths, cmd);
	ft_free_char_pp(paths);
	return (path);
}

