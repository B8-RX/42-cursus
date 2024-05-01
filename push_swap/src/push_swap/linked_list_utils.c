/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:07:40 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/21 17:07:41 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/push_swap.h"

void	ft_free_linked_list(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*first_lst;
	t_stack *curr_lst;
	
	ft_printf("FUNCTION FREE STACK\n");
	first_lst = stack;
	if (stack)
	{
		curr_lst = first_lst;
		while (curr_lst -> next != first_lst)
		{
			tmp = curr_lst;
			curr_lst = curr_lst -> next;
			free(tmp);
			tmp = NULL;
		}
		free(curr_lst);	
		curr_lst = NULL;
	}
}

t_stack	*ft_found_best_start(t_stack **stack_b, int value_a)
{
	t_stack *best_position;
  	size_t	curr_index;
	size_t	stack_len;
	
	curr_index = 0;
	stack_len = ft_get_stack_len(*stack_b);
	best_position = *stack_b;
	if (value_a > ft_get_lst_by_index(stack_b, curr_index) -> value)
		return (best_position);
	curr_index++;
	while ((value_a) < (ft_get_lst_by_index(stack_b, curr_index) -> value) && curr_index < stack_len)
	{
		if (curr_index * 2 < stack_len)
			curr_index = curr_index * 2;
		else if (curr_index + 1 < stack_len)
			curr_index++;
		else
			break;
	}
	while (best_position -> index != curr_index && best_position -> next != *stack_b)
	{
		// ft_printf("59====loop value %d====\n", best_position -> value);
		// ft_printf("60====loop index %u====\n", (unsigned int)best_position -> index);
		// ft_printf("61====loop curr_index %u====\n", (unsigned int) curr_index);
		best_position = best_position -> next;
	}
	ft_printf("\n64====best position value%d====\n", best_position -> value);
	ft_printf("65==== index %u====\n", (unsigned int)best_position -> index);
	return (best_position);
}

t_stack	*ft_get_lst_by_index(t_stack **stack, size_t index)
{
	t_stack	*lst;

	lst = *stack;
	if (!stack)
		return (NULL);
	while (lst -> next != *stack)
	{
		if (lst -> index == index)
			break;
		lst = lst -> next;
	}
	return (lst);
}

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (!stack)
		return (1);
	while (tmp -> next != stack)
	{
		if (tmp -> value < tmp -> next -> value)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}

size_t	ft_get_stack_len(t_stack *stack)
{
	size_t	len;
	t_stack	*tmp;

	tmp = stack;
	if (!stack)
		return (0);
	len = 1;
	while (tmp -> next != stack)
	{
		len++;
		tmp = tmp -> next;
	}
	return (len);
}

int	ft_get_sm_value(t_stack *stack)
{
	t_stack	*tmp;
	int		small_val;

	tmp = stack;
	small_val = tmp -> value;
	while (tmp -> next != stack)
	{
		if (small_val > tmp -> next -> value)
			small_val = tmp -> next -> value;
		tmp = tmp -> next;
	}
	return (small_val);
}

int	ft_get_bg_value(t_stack *stack)
{
	t_stack	*tmp;
	int		high_val;

	tmp = stack;
	high_val = tmp -> value;
	while (tmp -> next != stack)
	{
		if (high_val < tmp -> next -> value)
			high_val = tmp -> next -> value;
		tmp = tmp -> next;
	}
	return (high_val);
}
