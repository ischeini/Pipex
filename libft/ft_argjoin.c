/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:58:17 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/03 14:56:11 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_argjoin(char **argv)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (argv[++i])
		size += ft_strlen(argv[i]);
	size += i;
	str = ft_calloc(size + 1, sizeof(char));
	i = 0;
	while (argv[++i])
	{
		ft_strlcat(str, argv[i], size);
		ft_strlcat(str, " ", size);
	}
	return (str);
}
