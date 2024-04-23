/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:01:36 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/21 17:01:37 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack	*ft_init_lst(int value, char stack_name)
{
	t_stack	*lst;

	lst = malloc (sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst -> stack_name = stack_name;
	lst -> index = 0;
	lst -> value = value;
	lst -> next = lst;
	lst -> previous = lst;
	return (lst);
}

t_stack	*ft_push_lst(t_stack **stack, t_stack *new)
{
	t_stack *last;

	if (!new)
		return (NULL);
	if (!*stack)
		*stack = new;
	else
	{
		new -> index = ((*stack) -> previous -> index) + 1;
		last = (*stack) -> previous;	
		last -> next = new;
		new -> previous = last;
		new -> next = *stack;
		(*stack) -> previous = new;
	}
	return (*stack);
}

void	ft_pop_lst(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*last;
	t_stack	*prev;

	curr = *stack;
	while (curr -> next != *stack)
		curr = curr -> next;
	last = curr;
	prev = last -> previous;
	(*stack) -> previous = prev;
	prev -> next = *stack;
	free(last);
	last = NULL;
}

t_stack	*ft_unshift_lst(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return (NULL);
	if (*stack)
	{
		last = (*stack) -> previous;
		last -> next = new;
		(*stack) -> previous = new;
		new -> next = *stack;
		new -> previous = last;
		ft_update_stack_index(new);
	}
	*stack = new;
	return (*stack);
}

void	ft_shift_lst(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*next;

	next = NULL;
	if ((*stack) -> next != *stack)
	{
		prev = (*stack) -> previous;
		next = (*stack) -> next;
		next -> previous = prev;
		prev -> next = next;
	}
	free(*stack);
	*stack = next;	
	ft_update_stack_index(*stack);
}

void	ft_update_stack_index(t_stack *stack)
{
	t_stack	*curr;
	size_t	i;
	
	i = 0;
	curr = stack;
	if (!stack)
		return;
	do
	{
		curr -> index = i;
		curr = curr -> next;
		i++;
	} while (curr != stack);
}

