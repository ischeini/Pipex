/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:47:41 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/03 14:58:31 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_nbrlen counts the amount of digits of a SIZE_T variable.				*/
/* For function recicling purposes, accepts a SIZE_T base_len as argument.	*/
static int	ft_nbrlen(size_t n, size_t base_len)
{
	int	count;

	count = 1;
	while (n >= base_len)
	{
		n /= base_len;
		count++;
	}
	return (count);
}

/* Ft_utoa returns a CHAR * that includes the SIZE_T n argument as text.	*/
/* For function recicling purposes, it accepts a CHAR * base as argument.	*/
char	*ft_utoa_base(size_t n, const char *base)
{
	size_t	base_len;
	size_t	i;
	char	*str;

	base_len = ft_strlen(base);
	i = ft_nbrlen(n, base_len);
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (n >= base_len)
	{
		str[--i] = base[n % base_len];
		n /= base_len;
	}
	str[--i] = base[n % base_len];
	return (str);
}
