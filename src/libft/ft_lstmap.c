/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:11:11 by wding-ha          #+#    #+#             */
/*   Updated: 2021/05/25 22:21:32 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*hold;
	t_list	*elem;

	if (!lst && !del)
		return (NULL);
	hold = NULL;
	while (lst != NULL)
	{
		elem = ft_lstnew(f(lst->content));
		if (!elem)
		{
			ft_lstclear(&hold, del);
			free(hold);
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&hold, elem);
		lst = lst->next;
	}
	return (hold);
}
