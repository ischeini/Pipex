/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:49:13 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/03 14:58:19 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_strrchr returns a CHAR * to the last ocurrance of 'c' inside 's'.	*/
/* - Return NULL in case no ocurrance is found.							*/
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;
	char	c_c;

	i = 0;
	c_c = (char) c;
	tmp = NULL;
	while (s[i])
	{
		if (s[i] == c_c)
			tmp = (char *) &s[i];
		i++;
	}
	if (s[i] == c_c)
		tmp = (char *) &s[i];
	return ((char *) tmp);
}
