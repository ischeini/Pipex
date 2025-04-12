/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:17:50 by ischeini          #+#    #+#             */
/*   Updated: 2025/04/03 11:17:50 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_check(char **args, int *pipefd)
{
	char	*line;
	int		fd;

	fd = open(args[1], O_RDWR);
	if (fd < 0)
	{
		perror("File open");
		return (-1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_putstr_fd(line, pipefd[1]);
		free(line);
	}
	ft_putstr_fd("\0", pipefd[1]);
	close(fd);
	close(pipefd[1]);
	return (fd);
}

int	main(int argc, char **args, char *envp[])
{
	int		pipefd[2];
	int		fd;
	int		i;

	if (argc != 5)
	{
		errno = EINVAL;
		perror("Argc");
		return (1);
	}
	i = 0;
	while (i < argc - 3)
	{
		if (1 > 0)
		{
			if (ft_create_pipe(pipefd) == -1)
				return (1);
		}
		if (i == 0)
		{
			fd = ft_check(args, pipefd);
			if (fd == -1)
				return (1);
		}
		else
			close (pipefd[1]);
		ft_new_command(args, pipefd, envp, i + 2);
		close(pipefd[0]);
		i++;
	}
	ft_write_result(argc, args, pipefd);
	return (0);
}