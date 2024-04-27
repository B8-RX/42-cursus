/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:57:33 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/27 17:57:35 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/push_swap.h"

void	ft_rb(t_stack **stack_b)
{
	int	value;

	if (!*stack_b)
		return;
	value = (*stack_b) -> value;
	ft_shift_lst(stack_b);
	ft_push_lst(stack_b, ft_init_lst(value, 'B'));
	ft_update_stack_index(*stack_b);
}

void	ft_rrb(t_stack **stack_b)
{
	int	value;

	if (!*stack_b)
		return;
	value = (*stack_b) -> previous -> value;
	ft_pop_lst(stack_b);
	ft_unshift_lst(stack_b, ft_init_lst(value, 'B'));
}

void	ft_ra(t_stack **stack_a)
{
	int	value;

	if (!*stack_a)
		return;
	value = (*stack_a) -> value;
	ft_shift_lst(stack_a);
	ft_push_lst(stack_a, ft_init_lst(value, 'A'));
	ft_update_stack_index(*stack_a);
}

void	ft_rra(t_stack **stack_a)
{
	int	value;
	
	if (!*stack_a)
		return;
	value = (*stack_a) -> previous -> value;
	ft_pop_lst(stack_a);
	ft_unshift_lst(stack_a, ft_init_lst(value, 'A'));
}


