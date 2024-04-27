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
	t_stack	*prev;
	t_stack	*second;
	t_stack	*first;

	if (!*stack_a)
		return;
	first = *stack_a;
	second = *stack_a;
	if (first -> next != first)
	{
		prev = first -> previous;
		second = first -> next;
		prev -> next = second;
		second -> previous = prev;
		first -> next = second -> next;
		first -> previous = second;
		second -> next = first;
	}
	*stack_a = second;
	ft_update_stack_index(*stack_a);
}

void	ft_sb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*prev;

	if (!*stack_b)
		return;
	first = *stack_b;
	second = *stack_b;
	if (first -> next != first)
	{
		prev = first -> previous;
		second = first -> next;
		prev -> next = second;
		second -> previous = prev;
		first -> next = second -> next;
		first -> previous = second;
		second -> next = first;
	}
	*stack_b = second;
	ft_update_stack_index(*stack_b);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !*stack_b)
		return;
	ft_sa(stack_a);
	ft_sb(stack_b);
}
