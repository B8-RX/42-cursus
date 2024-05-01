/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:51:57 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/27 17:51:59 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*second;
	t_stack	*first;

	if (!*stack_a)
		return;
	first = *stack_a;
	second = first -> next;
	last = first -> previous;	
	first -> next = second -> next;
	first -> previous = second;
	second -> next = first;
	second -> previous = last;
	last -> next = second;
	if (first -> next != first)
		first -> next -> previous = first;
	*stack_a = second;
	ft_update_stack_index(*stack_a, 1);
}

void	ft_sb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!*stack_b)
		return;
	first = *stack_b;
	second = first -> next;
	last = first -> previous;	
	first -> next = second -> next;
	first -> previous = second;
	second -> next = first;
	second -> previous = last;
	last -> next = second;
	if (first -> next != first)
		first -> next -> previous = first;
	*stack_b = second;
	ft_update_stack_index(*stack_b, 1);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !*stack_b)
		return;
	ft_sa(stack_a);
	ft_sb(stack_b);
}
