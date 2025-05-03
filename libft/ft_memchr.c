/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:55:26 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/03 14:57:14 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_memchr searches for 'c' inside 's' for 'n' bytes.						*/
/* - Returns a VOID * to the first match or NULL, in case there's no match.	*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_c;
	unsigned char	c_c;
	size_t			i;

	i = 0;
	s_c = (unsigned char *) s;
	c_c = (unsigned char) c;
	while (i < n)
	{
		if (s_c[i] == c_c)
			return ((void *) &s_c[i]);
		i++;
	}
	return (NULL);
}
