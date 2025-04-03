/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:32:51 by sscheini          #+#    #+#             */
/*   Updated: 2025/01/17 12:46:48 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_memmove moves 'n' bytes from 'src' into 'dest', returning 'dest'. */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;
	size_t			i;

	i = -1;
	if (!dest || !src)
		return (dest);
	src_tmp = (unsigned char *) src;
	dst_tmp = (unsigned char *) dest;
	if (dst_tmp > src_tmp)
	{
		while (n > 0)
		{
			n--;
			dst_tmp[n] = src_tmp[n];
		}
	}
	else
	{
		while (++i < n)
			dst_tmp[i] = src_tmp[i];
	}
	return (dest);
}
