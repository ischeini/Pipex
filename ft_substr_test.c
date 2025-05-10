/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:55:32 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/11 00:55:32 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main()
{
	char	*str = "Hola mundo";
	char	*tmp;
	int		start = 5;
	int		i = 0;

	printf("%s\n", str);
	tmp = str + start;
	printf("%s\n", tmp);
}