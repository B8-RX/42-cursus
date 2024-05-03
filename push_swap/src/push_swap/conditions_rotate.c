/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:27:39 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/27 18:27:40 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/push_swap.h"

int	ft_match_condition_rb(t_stack *stack_b)
{
	t_stack	*curr_b;
	int		match_condition;

	curr_b = stack_b;
	match_condition = 0;
	if (!stack_b)
		return (0);
	if (((curr_b -> next -> value) > (curr_b -> previous -> value)
			&& (curr_b -> previous -> value) > (curr_b -> value))
			|| ((curr_b -> value) < (curr_b -> next -> value)
				&& (curr_b -> next -> value) < (curr_b -> previous -> value)))
		match_condition = 1;
	return (match_condition);
}

int	ft_match_condition_ra(t_stack *stack_a)
{
	t_stack	*curr_a;
	int		match_condition;

	curr_a = stack_a;
	match_condition = 0;
	if (!stack_a)
		return (0);
	if ((curr_a -> value) < (curr_a -> next -> value)
		&& (curr_a -> value) > (curr_a -> previous -> value)
		&& (curr_a -> next -> value) < (curr_a -> previous -> value))
		match_condition = 1;
	return (match_condition);
}

int	ft_match_condition_rrb(t_stack *stack_b)
{
	t_stack	*curr_b;
	int		match_condition;

	curr_b = stack_b;
	match_condition = 0;
	if (!stack_b || (curr_b && ft_get_stack_len(curr_b) < 3))
		return (0);
	if ((curr_b -> value) < (curr_b -> previous -> value)
		|| (curr_b -> next -> value) < (curr_b -> previous -> value))
		match_condition = 1;
	// ft_printf("==RRB ==== \n");
	return (match_condition);
}

int	ft_match_condition_rra(t_stack *stack_a)
{
	t_stack	*curr_a;
	int		match_condition;

	curr_a = stack_a;
	match_condition = 0;
	if (!stack_a || ft_get_stack_len(curr_a) < 3)
		return (0);
	if ((curr_a -> previous -> value) != ft_get_bg_value(stack_a)
		&& (curr_a -> value) > (curr_a -> previous -> value) 
		&& (curr_a -> next -> value) > (curr_a -> previous -> value))
		match_condition = 1;
	return (match_condition);
}


