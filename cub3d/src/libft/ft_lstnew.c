/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:27:28 by wding-ha          #+#    #+#             */
/*   Updated: 2022/05/28 13:31:36 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*hold;

	hold = malloc(sizeof(t_list));
	if (!hold)
		return (NULL);
	hold->content = content;
	hold->next = NULL;
	return (hold);
}
