/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:26:36 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/27 18:26:37 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/push_swap.h"

int	ft_match_condition_sa(t_stack *stack_a)
{
	int	match_condition;

	match_condition = 0;
	if (!stack_a)
		return (0);
	if ((stack_a -> value) > (stack_a -> next -> value)
		&& (stack_a -> next -> value) < (stack_a -> previous -> value))
		match_condition = 1;
	return (match_condition);
}

int	ft_match_condition_sb(t_stack *stack_b)
{
	int	match_condition;

	match_condition = 0;
	if (!stack_b)
		return (0);
	if ((stack_b -> value) < (stack_b -> next -> value) && (stack_b -> value) > (stack_b -> next -> next -> value))
		match_condition = 1;
	return (match_condition);
}
