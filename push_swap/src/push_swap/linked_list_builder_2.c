/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_builder_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:07:22 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/27 18:07:23 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/push_swap.h"

t_stack	*ft_init_lst(int value, char stack_name)
{
	t_stack	*lst;

	lst = malloc (sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst -> stack_name = stack_name;
	lst -> index = 0;
	lst -> value = value;
	lst -> next = lst;
	lst -> previous = lst;
	return (lst);
}

void	ft_update_stack_index(t_stack *stack)
{
	t_stack	*curr;
	size_t	i;
	
	i = 0;
	curr = stack;
	if (!stack)
		return;
	do
	{
		curr -> index = i;
		curr = curr -> next;
		i++;
	} while (curr != stack);
}
