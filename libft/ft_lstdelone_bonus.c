/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:54:33 by ischeini          #+#    #+#             */
/*   Updated: 2025/05/03 14:57:00 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ft_lstdelone free 'lst.content' with 'del' function. Then it frees lst. */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst->content != NULL)
		del(lst->content);
	free(lst);
}
