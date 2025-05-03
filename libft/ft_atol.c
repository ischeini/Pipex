/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:38:46 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/03 14:56:08 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_atoi returns an INT with the first number found on a CHAR *.	*/
long	ft_atol(const char *nptr, long *n)
{
	long	sign;
	int		i;

	sign = 1;
	i = 0;
	*n = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i]))
	{
		sign = ft_issign(nptr[i]);
		i++;
	}
	if (!ft_isdigit(nptr[i]))
		return (0);
	while (ft_isdigit(nptr[i]))
	{
		*n = *n * 10 + (nptr[i] - '0');
		i++;
	}
	*n *= sign;
	if (nptr[i] != '\0')
		return (0);
	return (1);
}
