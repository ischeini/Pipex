/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:17:54 by ischeini          #+#    #+#             */
/*   Updated: 2025/04/03 11:17:54 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <errno.h>
# include <sys/wait.h>

void	ft_parent_process(char **argv, char **envp, int *fd);

void	ft_child_process(char **argv, char **envp, int *fd);

void	ft_execute(char *argv, char **envp);

char	*ft_find_path(char *cmd, char **envp);

# endif