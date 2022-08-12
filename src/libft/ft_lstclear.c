/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:02:08 by wding-ha          #+#    #+#             */
/*   Updated: 2021/05/24 22:45:12 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*hold;

	if (lst)
	{
		while (*lst)
		{
			hold = (*lst)-> next;
			ft_lstdelone(*lst, del);
			*lst = hold;
		}
	}
}
