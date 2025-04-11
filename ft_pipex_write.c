/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:07:54 by ischeini          #+#    #+#             */
/*   Updated: 2025/04/09 13:52:56 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_write(char *name, int fd_in)
{
	char	buff[1024];
	int		fd_out;
	int		b_read;

	if (fd_in < 0)
	{
		perror("Fd_in");
		return ;
	}
	fd_out = open(name, O_RDWR | O_CREAT | O_APPEND, 0777);
	if (fd_out < 0)
	{
		perror("Fd_out");
		return ;
	}
	while (1)
	{
		b_read = read(fd_in, buff, 1024);
		write(fd_out, &buff, b_read);
		if (b_read == -1)
		{
			perror("read");
			return ;
		}
	}
}

void	ft_write_result(int argc, char **args, int *pipefd)
{
	if ((argc % 2) == 0)
		ft_write(args[argc - 1], pipefd[0]);
	else
		ft_write(args[argc - 1], pipefd[0]);
}