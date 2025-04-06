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

static void	ft_read_pipe(char *limiter, int fd_in, int fd_out)
{
	char	*line;
	char	*tmp;

	while (1)
	{
		line = get_next_line(fd_in);
		if (!line)
			break ;
		tmp = ft_strtrim(line, "\n");
		if (ft_strncmp(tmp, limiter, ft_strlen(limiter) + 1) == 0)
		{
			free(tmp);
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd_out);
		free(tmp);
		free(line);
	}
}

static int	ft_check(char **av, int *p)
{
	int	fd_tmp;

	fd_tmp = open(av[1], O_RDWR);
	if (fd_tmp < 0)
	{
		perror("File open");
		return (-1);
	}
	if (ft_strncmp(av[1], "infile.txt", 11) == 0)
	{
		ft_read_pipe(av[2], fd_tmp, p[1]);
		close(fd_tmp);
		return (1);
	}
	else
	{
		p[0] = fd_tmp;
		return (0);
	}
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