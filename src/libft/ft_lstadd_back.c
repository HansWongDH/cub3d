/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:35:54 by wding-ha          #+#    #+#             */
/*   Updated: 2021/05/23 22:13:58 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*next;

	if (lst && new)
	{
		if (*lst)
		{
			next = ft_lstlast(*lst);
			next->next = new;
		}
		else
			*lst = new;
	}
}
