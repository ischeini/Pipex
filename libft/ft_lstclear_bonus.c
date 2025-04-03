/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:03:17 by sscheini          #+#    #+#             */
/*   Updated: 2025/01/12 15:02:14 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_lstclear frees every node included on the T_LIST ** using 'del'. */
/* - Finally, it frees itself.										   */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = lst[0]->next;
		ft_lstdelone(*lst, del);
		lst[0] = tmp;
	}
	lst[0] = NULL;
}
