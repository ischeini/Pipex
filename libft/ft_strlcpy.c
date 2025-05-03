/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:26:08 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/03 14:58:08 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_strlcpy copies 'size' bytes form 'src' into 'dst'. 		  */
/* - If 'size' >= src_len + 1, it copies all of 'src' into 'dst'. */
/* - Else, it truncates the copy after size - 1 bytes.			  */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size >= src_len + 1)
		ft_memmove(dst, src, src_len + 1);
	else if (size != 0)
	{
		ft_memmove(dst, src, size - 1);
		dst[size - 1] = 0;
	}
	return (src_len);
}
