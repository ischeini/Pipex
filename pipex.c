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

int	main(int argc, char **argv, char *envp[])
{
	int	fdout;
	int	fdin;

	if (argc != 5 || !ft_command_exist(argv, envp, (argc - 1)))
		ft_error("Command");
	fdout = ft_open_file(argv[4], 1);
	fdin = ft_open_file(argv[1], 2);
	fdin = ft_command_process(&argv[2], envp, 1, fdin);
	ft_last_command_process(argv[3], envp, fdout, fdin);
	return (0);
}
