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

#include "./lib/push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	size_t	i;
	size_t	last_index;
	t_stack	*curr_lst;

	ft_printf("FUNCTION PRINT VALUES\n");
	i = 0;
	last_index = stack -> previous -> index;
	curr_lst = stack;
	ft_printf("STACK NAME:%c\n", stack -> stack_name);
	while (i++ <= last_index)
	{
		ft_printf("=================================================\n");
		ft_printf("curr_lst index: %u\n", (unsigned int)curr_lst -> index);
		ft_printf("curr_lst value: %d\n", curr_lst -> value);
		ft_printf("///////////////////////===>\n");
		ft_printf("previous index: %u\n", (unsigned int)curr_lst -> previous -> index);
		ft_printf("previous value: %d\n", curr_lst -> previous -> value);
		ft_printf("///////////////////////===>\n");
		ft_printf("next index: %u\n", (unsigned int)curr_lst -> next -> index);
		ft_printf("next value: %d\n", curr_lst -> next -> value);
		curr_lst = curr_lst -> next;
	}
	ft_printf("=================================================\n");
	ft_printf("FUNCTION PRINT VALUES //////\n");
}

void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int		len_stack_a;
	int		len_stack_b;
	int		diff_len;
	char	larger_stack_name;
	int		larger_stack;

	len_stack_a = ft_get_stack_len(stack_a);
	len_stack_b = ft_get_stack_len(stack_b);
	diff_len = 0;
	if (len_stack_a >= len_stack_b)
	{
		larger_stack_name = 'A'; 
		larger_stack = len_stack_a;
		diff_len = len_stack_a - len_stack_b;
	}
	else
	{
		larger_stack_name = 'B';
		larger_stack = len_stack_b;
		diff_len = len_stack_b - len_stack_a;
	}
	ft_printf("\n");
	while (larger_stack > 0)
	{
		if (diff_len)
		{
			if (larger_stack_name == 'A')
			{
				ft_printf("|%-7d", stack_a -> value);
				ft_printf("%7c|\n", ' ');
				stack_a = stack_a -> next;
			}
			else
			{
				ft_printf("|%-7c", ' ');
				ft_printf("%7d|\n", stack_b -> value);
				stack_b = stack_b -> next;
			}
			diff_len--;
		}
		else 
		{
			ft_printf("|%-7d", stack_a -> value);
			ft_printf("%7d|\n", stack_b -> value);
			stack_a = stack_a -> next;
			stack_b = stack_b -> next;
		}
		larger_stack--;
}
	ft_printf("%-9s", "###");
	ft_printf("%7s\n", "###");
	ft_printf("%-8s", "A");
	ft_printf("%8s \n", "B");
	ft_printf("%-9s", "###");
	ft_printf("%7s\n", "###");
	ft_printf("\n");
}


void	ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*first_lst;
	t_stack *curr_lst;
	
	ft_printf("FUNCTION FREE STACK\n");
	first_lst = stack;
	if (stack)
	{
		ft_printf("STACK NAME:%c\n", stack -> stack_name);
		curr_lst = first_lst;
		while (curr_lst -> next != first_lst)
		{
			// ft_printf("///////////////////////===>\n");
			tmp = curr_lst;
			// ft_printf("FREE stack -> index: |%ld|\n", tmp -> index); 
			// ft_printf("FREE stack -> value: |%d|\n", tmp -> value); 
			curr_lst = curr_lst -> next;
			free(tmp);
			tmp = NULL;
		}
		// ft_printf("///////////////////////===>\n");
		// ft_printf("+FREE stack -> index: |%ld|\n", curr_lst -> index); 
		// ft_printf("+FREE stack -> value: |%d|\n", curr_lst -> value); 
		ft_printf("///////////////////////===>\n");
		free(curr_lst);	
		curr_lst = NULL;
	}
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

