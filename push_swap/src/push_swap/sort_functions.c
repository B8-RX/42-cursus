/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:57:55 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/21 16:57:56 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	t_stack	*prev;
	t_stack	*second;
	t_stack	*first;

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
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void	ft_ra(t_stack **stack_a)
{
	int	value;

	value = (*stack_a) -> value;
	ft_shift_lst(stack_a);
	ft_push_lst(stack_a, ft_init_lst(value, 'A'));
	ft_update_stack_index(*stack_a);
}

void	ft_rb(t_stack **stack_b)
{
	int	value;

	value = (*stack_b) -> value;
	ft_shift_lst(stack_b);
	ft_push_lst(stack_b, ft_init_lst(value, 'B'));
	ft_update_stack_index(*stack_b);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}

void	ft_rra(t_stack **stack_a)
{
	int	value;

	value = (*stack_a) -> previous -> value;
	ft_pop_lst(stack_a);
	ft_unshift_lst(stack_a, ft_init_lst(value, 'A'));
}

void	ft_rrb(t_stack **stack_b)
{
	int	value;

	value = (*stack_b) -> previous -> value;
	ft_pop_lst(stack_b);
	ft_unshift_lst(stack_b, ft_init_lst(value, 'B'));
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	value_a;
	int	value_b;

	value_a = (*stack_a) -> previous -> value;
	value_b = (*stack_b) -> previous -> value;
	ft_pop_lst(stack_a);
	ft_pop_lst(stack_b);
	ft_unshift_lst(stack_a, ft_init_lst(value_a, 'A'));
	ft_unshift_lst(stack_b, ft_init_lst(value_b, 'B'));
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	int	value;

	value = (*stack_a) -> value;
	ft_unshift_lst(stack_b, ft_init_lst(value, 'B'));
	ft_shift_lst(stack_a);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	int	value;

	value = (*stack_b) -> value;
	ft_unshift_lst(stack_a, ft_init_lst(value, 'A'));
	ft_shift_lst(stack_b);
}

