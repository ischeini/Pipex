/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:24:31 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/03 14:57:59 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_strdup creates and returns a CHAR * that includes 's'. */
char	*ft_strdup(const char *s)
{
	char	*str;
	int		str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	str = malloc(str_len + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, str_len + 1);
	ft_memcpy(str, s, str_len);
	return (str);
}
