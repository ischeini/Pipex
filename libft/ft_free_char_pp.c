/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_pp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:25:04 by ischeini          #+#    #+#             */
/*   Updated: 2025/03/29 12:02:41 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_char(char **to_free)
{
	int	i;

	i = 0;
	if (to_free)
	{
		while (to_free[i])
		{
			free(to_free[i]);
			i++;
		}
		free(to_free);
	}
	return (0);
}
