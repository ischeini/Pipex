/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscheini <sscheini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:43:36 by sscheini          #+#    #+#             */
/*   Updated: 2024/10/17 17:15:09 by sscheini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_calloc allocates 'nmemb'*'size' bytes of memory and sets them to '\0'. */
/* - Returns a VOID * created as a result.									 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	tmp = NULL;
	if (size == 0)
		return (malloc(0));
	if ((size == 0 && nmemb == 0) || nmemb > __SIZE_MAX__ / size)
		return (tmp);
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, nmemb * size);
	return (tmp);
}
