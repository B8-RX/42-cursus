/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:57:55 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/21 16:57:56 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	int	value;

	if (!*stack_b)
		return;
	value = (*stack_b) -> value;
	ft_unshift_lst(stack_a, ft_init_lst(value, 'A'));
	ft_shift_lst(stack_b);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	int	value;

	if (!*stack_a)
		return;
	value = (*stack_a) -> value;
	ft_unshift_lst(stack_b, ft_init_lst(value, 'B'));
	ft_shift_lst(stack_a);
}
