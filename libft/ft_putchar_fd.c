/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:10:37 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/03 14:57:44 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_putchar_fd writes 'c' into the 'fd' passed as an argument. */
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
