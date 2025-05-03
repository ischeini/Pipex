/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:54:48 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/03 14:57:18 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_memcpy copies 'n' bytes from 'src' into 'dest', returning 'dest'. */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!src || !dest)
		return (dest);
	ft_memmove(dest, src, n);
	return (dest);
}
