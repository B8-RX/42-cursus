/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 03:55:25 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/28 04:42:29 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return;
	t_list *last = *lst;
	if (!*lst)
	{	
		*lst = new;
		(**lst).next = NULL;
	}
	else
	{
		while (last -> next)
			last = last -> next;
		last -> next = new;
	}
}

