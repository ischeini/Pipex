/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:08:16 by ischeini          #+#    #+#             */
/*   Updated: 2025/04/22 10:35:56 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	if(!errno)
		errno = EINVAL;
	perror(str);
	exit(EXIT_FAILURE);
}

char	*ft_find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			ft_free_char_pp(paths);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_char_pp(paths);
	return (0);
}

void	ft_execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;
	
	i = 0;
	cmd = ft_split(argv, ' ');
	if (!cmd)
		ft_error("Split");
	while (cmd[i])
	{
		path = ft_find_path(cmd[i], envp);
		if (path)
			break ;
		i++;
	}
	if (!path)
	{
		ft_free_char_pp(cmd);
		ft_error("Path");
	}
	if (execve(path, cmd, envp) == -1)
		ft_error("Execve");
}
