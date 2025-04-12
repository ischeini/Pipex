/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:07:54 by ischeini          #+#    #+#             */
/*   Updated: 2025/04/12 11:40:08 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_write(char *name, int fd_in)
{
	char	buff[1024];
	int		fd_out;
	int		b_read;

	fd_out = open(name, O_RDWR | O_CREAT | O_APPEND, 0777);
	if (fd_out < 0)
	{
		perror("Fd_out");
		return ;
	}
	while (1)
	{
		b_read = read(fd_in, buff, 1024);
		if (write(fd_out, &buff, b_read) != b_read)
		{
			perror("writw");
			return ;
		}
		if (b_read == 0)
			break ;
	}
}

void	ft_write_result(int argc, char **args, int *pipefd)
{
	ft_write(args[argc - 1], pipefd[0]);
}