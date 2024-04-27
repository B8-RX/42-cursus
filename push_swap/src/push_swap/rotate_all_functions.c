/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_all_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:21:37 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/27 18:21:39 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/push_swap.h"

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !*stack_b)
		return;
	ft_ra(stack_a);
	ft_rb(stack_b);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	value_a;
	int	value_b;

	if (!*stack_a || !*stack_b)
		return;
	value_a = (*stack_a) -> previous -> value;
	value_b = (*stack_b) -> previous -> value;
	ft_pop_lst(stack_a);
	ft_pop_lst(stack_b);
	ft_unshift_lst(stack_a, ft_init_lst(value_a, 'A'));
	ft_unshift_lst(stack_b, ft_init_lst(value_b, 'B'));
}
