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
