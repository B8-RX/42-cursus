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

int	ft_position_in_neighbour(t_stack *stack, int value)
{
	int		i;
	size_t	len;

	i = 3;
	len = ft_get_stack_len(stack);
	while (--i && len >= 3 && (stack -> value) > value)
		stack = stack -> next;
	return (i);
}

t_stack	*ft_found_best_start(t_stack **stack_b, int value_a)
{
	t_stack *best_position;
	t_stack *curr;
  	size_t	curr_index;
	size_t	stack_len;
	
	curr_index = 1;
	stack_len = ft_get_stack_len(*stack_b);
	curr = *stack_b;

	while (curr -> next != *stack_b && curr -> value > value_a)
		curr = curr -> next;
	best_position = curr;
	ft_printf("\n60====stack len [%u]====\n", (unsigned int)stack_len);
	ft_printf("61====curr index [%u]====\n", (unsigned int)curr_index);
	ft_printf("62= found()===candidate value [%d]====\n", value_a);
	if (best_position -> value < value_a)
		ft_printf("63====best position, above value [%d] in index [%u]====\n", best_position -> value, (unsigned int)best_position -> index);
	else
		ft_printf("63====best position, under value [%d] in index [%u]====\n", best_position -> value, (unsigned int)best_position -> index);

	return (best_position);
}

// t_stack	*ft_found_best_start(t_stack **stack_b, int value_a)
// {
// 	t_stack *best_position;
//   	size_t	curr_index;
// 	size_t	stack_len;
// 	
// 	curr_index = 1;
// 	stack_len = ft_get_stack_len(*stack_b);
// 	best_position = *stack_b;
//
// 	while ((value_a) < (ft_get_lst_by_index(stack_b, curr_index) -> value) && curr_index < stack_len -1)
// 	{
// 		if ((curr_index * 2) < (stack_len))
// 			curr_index = curr_index * 2;
// 		else if ((curr_index + 1) < stack_len && (ft_get_lst_by_index(stack_b, curr_index) -> next -> value) > (value_a))
// 			curr_index++;
// 		if (ft_get_lst_by_index(stack_b, curr_index) -> previous -> value < value_a)
// 		{
// 			int tmp;
// 			tmp = (curr_index / 2);
// 			curr_index = (curr_index / tmp) + (tmp / 2);
// 		}
// 	}
// 	while (best_position -> index != curr_index && best_position -> next != *stack_b)
// 		best_position = best_position -> next;
	// ft_printf("\n60====stack len [%u]====\n", (unsigned int)stack_len);
	// ft_printf("\n61====curr index [%u]====\n", (unsigned int)curr_index);
	// ft_printf("\n62====candidate value [%d]====\n", value_a);
	// ft_printf("\n63====best position, above value [%d] in index [%u]====\n", best_position -> value, (unsigned int)best_position -> index);
// 	return (best_position);
// }
//
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

t_stack	*ft_get_lst_by_value(t_stack **stack, int value)
{
	t_stack	*lst;

	lst = *stack;
	if (!stack)
		return (NULL);
	while (lst -> next != *stack)
	{
		if (lst -> value == value)
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
	len = 0;
	do
	{
		len++;
		tmp = tmp -> next;
	} while (tmp != stack);
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
