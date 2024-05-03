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
	ft_shift_lst(stack_b);
	ft_unshift_lst(stack_a, ft_init_lst(value, 'A'));
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	int	value;

	if (!*stack_a)
		return;
	value = (*stack_a) -> value;
	ft_shift_lst(stack_a);
	if (*stack_b)
	{
		ft_printf("==36 pb()==value stack_a [%d]\n", value);
		ft_printf("==37 pb()==value stack_b [%d]\n", (*stack_b) -> value);
	}
	if (ft_get_stack_len(*stack_b) > 3 && (*stack_b) -> next -> value > value)
	{
		ft_printf("==41 pb()== match push tail \n");
		ft_push_lst_tail(stack_b, ft_init_lst(value, 'B'));
	}
	else
		ft_unshift_lst(stack_b, ft_init_lst(value, 'B'));
}

