/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:19:15 by ischeini          #+#    #+#             */
/*   Updated: 2025/04/03 11:19:15 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pid_error(pid_t pid, int f_fd, int c_fd)
{
	if (pid < 0)
	{
		close(f_fd);
		close(c_fd);
		return (0);
	}
	return (1);
}

int	ft_errors(char *str)
{
	write(2, strerror(errno), strlen(strerror(errno)));
	write(2, ": ", 2);
	write(2, str, strlen(str));
	write(2, "\n", 1);
	return (1);
}
