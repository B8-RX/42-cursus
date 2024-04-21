/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:07:40 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/21 17:07:41 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_print_values_lst(t_stack *stack)
{
	t_stack	*curr;
	size_t	i;

	printf("FUNCTION PRINT VALUES\n");
	curr = stack;
	if (!curr)
		return;
	i = 0;
	printf("STACK NAME:%c\n", stack -> stack_name);
	while (i++ <= (stack -> previous -> index))
	{
		printf("=================================================\n");
		printf("curr index: %ld\n", curr -> index);
		printf("curr value: %d\n", curr -> value);
		printf("///////////////////////===>\n");
		printf("previous index: %ld\n", curr -> previous -> index);
		printf("previous value: %d\n", curr -> previous -> value);
		printf("///////////////////////===>\n");
		printf("next index: %ld\n", curr -> next -> index);
		printf("next value: %d\n", curr -> next -> value);
		curr = curr -> next;
	}
	printf("=================================================\n");
	printf("FUNCTION PRINT VALUES //////\n");
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*curr;
	
	printf("FUNCTION FREE STACK\n");
	printf("STACK NAME:%c\n", stack -> stack_name);
	curr = stack;
	if (stack)
	{
		while (curr -> next != stack)
		{
			printf("///////////////////////===>\n");
			tmp = curr;
			printf("FREE stack -> index: |%ld|\n", tmp -> index); 
			printf("FREE stack -> value: |%d|\n", tmp -> value); 
			curr = curr -> next;
			free(tmp);
			tmp = NULL;
		}
		printf("///////////////////////===>\n");
		printf("+FREE stack -> index: |%ld|\n", curr -> index); 
		printf("+FREE stack -> value: |%d|\n", curr -> value); 
		printf("///////////////////////===>\n");
	}
	free(curr);	
	curr = NULL;
}

t_stack	*ft_get_lst_by_index(t_stack *stack, size_t index)
{
	t_stack	*lst;

	lst = stack;
	if (!stack)
		return (NULL);
	while (lst -> index != index)
		lst = lst -> next;
	return (lst);
}

