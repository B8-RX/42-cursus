/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_builder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:01:36 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/21 17:01:37 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/push_swap.h"

t_stack	*ft_push_lst(t_stack **stack, t_stack *new)
{
	t_stack *last;

	if (!new)
		return (NULL);
	if (!*stack)
		*stack = new;
	else
	{
		last = (*stack) -> previous;	
		last -> next = new;
		new -> previous = last;
		new -> next = *stack;
		(*stack) -> previous = new;
		ft_update_stack_index(*stack, 1);
	}
	return (*stack);
}

void	ft_pop_lst(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*last;
	t_stack	*prev;

	curr = *stack;
	while (curr -> next != *stack)
		curr = curr -> next;
	last = curr;
	prev = last -> previous;
	(*stack) -> previous = prev;
	prev -> next = *stack;
	free(last);
	last = NULL;
}

t_stack	*ft_unshift_lst(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return (NULL);
	if (*stack)
	{
		last = (*stack) -> previous;
		last -> next = new;
		(*stack) -> previous = new;
		new -> next = *stack;
		new -> previous = last;
		ft_update_stack_index(new, 1);
	}
	*stack = new;
	return (*stack);
}

void	ft_shift_lst(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*curr;

	curr = NULL;
	if ((*stack) -> next != *stack)
	{
		prev = (*stack) -> previous;
		curr = (*stack) -> next;
		curr -> previous = prev;
		prev -> next = curr;
	}
	free(*stack);
	*stack = curr;	
	ft_update_stack_index(*stack, 1);
}
