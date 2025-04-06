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
	close(fd);
	return (fd);
}

int	main(int argc, char **args, char *envp[])
{
	int		pipefd1[2];
	int		pipefd2[2];
	int		fd;
	int		i;

	if (argc != 5)
	{
		errno = EINVAL;
		perror("Argc");
		return (1);
	}
	ft_create_pipe(&pipefd1);
	ft_create_pipe(&pipefd2);
	fd = ft_check(args, &pipefd2);
	if (fd == -1)
		return (1);
	i = 0;
	while (i < argc - fd - 3)
	{
		if (i % 2 == 0)
			ft_new_f_command(args[i + fd + 2], &pipefd1, &pipefd2, envp);
		else
			ft_new_c_command(args[i + fd + 2], &pipefd1, &pipefd2, envp);
		i++;
	}
	ft_write_result(argc, args, pipefd1, pipefd2);
	return (0);
}