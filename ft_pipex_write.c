/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:07:54 by ischeini          #+#    #+#             */
/*   Updated: 2025/04/06 15:09:46 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pip_write(char *name, int fd_in, int hd)
{
	char	buff[1];
	int		fd_out;
	int		b_read;

	if (hd)
		fd_out = open(name, O_RDWR | O_CREAT | O_APPEND, 0777);
	else
	{
		if (access(name, F_OK) == 0)
			unlink(name);
		fd_out = open(name, O_WRONLY , 0777);
	}
	if (fd_out < 0)
	{
		
		pip_error("pip_write: fd_out error.");
	}
	if (fd_in < 0)
	{
		
		pip_error("pip_write: fd_in error.");
	}
	b_read = read(fd_in, &buff, sizeof(char));
	while (b_read > 0)
	{
		write(fd_out, &buff, 1);
		b_read = read(fd_in, &buff, sizeof(char));
	}
}

void	ft_write_result(int ac, char **av, int *op, int *ip)
{
	int	here_d;

	here_d = 0;
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		here_d = 1;
	if (((ac - here_d) % 2) == 0)
		pip_write(av[ac - 1], op[0], here_d);
	else
		pip_write(av[ac - 1], ip[0], here_d);
}