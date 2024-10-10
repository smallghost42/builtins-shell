/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trazanad <trazanad@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:31:33 by trazanad          #+#    #+#             */
/*   Updated: 2024/08/02 11:08:29 by trazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*next;

	if (lst && *lst)
	{
		tmp = *lst;
		while (tmp)
		{
			next = tmp -> next;
			ft_lstdelone(tmp, del);
			tmp = next;
		}
		*lst = 0;
	}
}
