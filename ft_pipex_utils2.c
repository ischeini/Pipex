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

int	ft_command_exist(char **argv, char *envp[], int size)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 1;
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
	return (1);
}