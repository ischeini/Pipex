/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:49:39 by ischeini          #+#    #+#             */
/*   Updated: 2025/04/27 18:49:39 by ischeini         ###   ########.fr       */
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

static int	ft_time(char *argv, int time)
{
	char	**split;
	int		tmp_time;

	if (ft_strnstr(argv, "sleep", ft_strlen(argv)))
	{
		split = ft_split(argv, ' ');
		if (!split)
			ft_error("Split");
		tmp_time = ft_atoi(split[1]);
		if (tmp_time > time)
			return (tmp_time);
	}
	return (time);
}

static void	ft_sleep_command(char **argv, char *envp[])
{
	int		tmp_time;
	int		sleep;
	int		time;
	int		i;

	i = 0;
	time = 0;
	sleep = 0;
	while (argv[i])
	{
		tmp_time = ft_time(argv[i], time);
		if (tmp_time > time)
		{
			time = tmp_time;
			sleep = i;
		}
		i++;
	}
	if (ft_strnstr(argv[sleep], "sleep", ft_strlen(argv[sleep])))
		ft_execute(argv[sleep], envp);
}

static void	ft_check_sleep(char **argv, char *envp[], int j)
{
	pid_t	pid;

	pid = ft_fork();
	if (pid == 0)
		ft_sleep_command(&argv[j], envp);
	else
		wait(NULL);
}

int	ft_command_exist(char **argv, char *envp[], int size)
{
	char	**cmd;
	char	*path;
	int		i;
	int		j;

	i = 1;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		i = 2;
	j = i + 1;
	while (++i < size)
	{
		cmd = ft_split(argv[i], ' ');
		if (!cmd)
			ft_error("Split");
		path = ft_find_path(cmd[0], envp);
		ft_free_char_pp(cmd);
		if (!path)
			return (0);
		free(path);
	}
	ft_check_sleep(argv, envp, j);
	return (1);
}
