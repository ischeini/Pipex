/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:49:52 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/03 14:55:10 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_pstrdup(const char **s)
{
	char	**str;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	count = ft_pstrlen(s);
	str = malloc((count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		str[i] = ft_strdup(s[i]);
		if (!str[i])
		{
			while (--i >= 0)
				free(str[i]);
			free(str);
			return (NULL);
		}
	}
	str[count] = NULL;
	return (str);
}
