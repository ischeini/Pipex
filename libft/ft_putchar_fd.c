/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:10:37 by sscheini          #+#    #+#             */
/*   Updated: 2024/11/22 05:26:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_putchar_fd writes 'c' into the 'fd' passed as an argument. */
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
