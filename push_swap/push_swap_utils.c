/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 01:51:39 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/04 01:51:42 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

char	*ft_print_error(void)
{
	write(2, "Error\n", 6);
	return (NULL);
}

int	ft_count_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		parity;
	int		i;

	i = 0;
	parity = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			parity = -1;
		i++;
	}	
	res = (str[i] - '0');
	i++;
	while (str[i])
	{
		if (res > ((2147483647 - (str[i] - '0')) / 10))
		{
			if (parity == 1)
				return (2147483647);
			return (-2147483648);
		}	
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * parity); 
}

int	ft_get_len_value(char *value)
{
	int	j;

	j = 0;
	while (value[j] && value[j] != ' ')
		j++;
	return (j);
}

void	ft_print_values_lst(t_stack *stack)
{
	t_stack	*curr;
	size_t	i;

	printf("FUNCTION PRINT VALUES\n");
	curr = stack;
	if (!curr)
		return;
	i = 0;
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

t_stack	*ft_sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;
	t_stack	*tmp;
	int		small_value;
	int		high_value;
	size_t	total_length;
	size_t	current_index;

	stack_b = NULL;
	printf("FUNCTION SORT\n");
	tmp = *stack_a;
	total_length = 1;
	small_value = tmp -> value;
	high_value = tmp -> value;
	while ((tmp -> index) < ((*stack_a) -> previous -> index))
	{
		total_length++;
		tmp = tmp -> next;
	}
	tmp = *stack_a;
	current_index = 0;
	while (current_index < total_length)
	{
		if (small_value > tmp -> next -> value)
			small_value = tmp -> next -> value;
		if (high_value < tmp -> next -> value)
			high_value = tmp -> next -> value;
		tmp = tmp -> next;
		current_index++;
	}
	printf("\nSMALLEST VALUE: %d\nHIGHEST VALUE: %d\nTOTAL LENGTH: %zu\n",
		small_value,
		high_value,
		total_length);
	ft_pb(stack_a, &stack_b);
	ft_pb(stack_a, &stack_b);
	// ft_sa(stack_a);
	// ft_sb(&stack_b);
	// ft_ss(stack_a, &stack_b);
	// ft_pb(stack_a, &stack_b);
	// ft_ra(stack_a);
	// ft_rb(&stack_b);
	// ft_pa(stack_a, &stack_b);
	ft_rr(stack_a, &stack_b);
	ft_pop_lst(stack_a);
	ft_free_stack(stack_b);
	return (*stack_a);
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

void	ft_sa(t_stack **stack_a)
{
	t_stack	*prev;
	t_stack	*second;
	t_stack	*first;

	first = *stack_a;
	second = *stack_a;
	if (first -> next != first)
	{
		prev = first -> previous;
		second = first -> next;
		prev -> next = second;
		second -> previous = prev;
		first -> next = second -> next;
		first -> previous = second;
		second -> next = first;
	}
	*stack_a = second;
	ft_update_stack_index(*stack_a);
}

void	ft_sb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*prev;

	first = *stack_b;
	second = *stack_b;
	if (first -> next != first)
	{
		prev = first -> previous;
		second = first -> next;
		prev -> next = second;
		second -> previous = prev;
		first -> next = second -> next;
		first -> previous = second;
		second -> next = first;
	}
	*stack_b = second;
	ft_update_stack_index(*stack_b);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void	ft_ra(t_stack **stack_a)
{
	int	value;

	value = (*stack_a) -> value;
	ft_shift_lst(stack_a);
	ft_push_lst(stack_a, ft_init_lst(value));
	ft_update_stack_index(*stack_a);
}

void	ft_rb(t_stack **stack_b)
{
	int	value;

	value = (*stack_b) -> value;
	ft_shift_lst(stack_b);
	ft_push_lst(stack_b, ft_init_lst(value));
	ft_update_stack_index(*stack_b);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}

// void	ft_rra(t_stack **stack_a)
// {
// 	int	value;
//
// 	value = *stack_a -> previous;
// 	ft_pop_lst(stack_a);
// }

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
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	int	value;

	value = (*stack_a) -> value;
	ft_unshift_lst(stack_b, ft_init_lst(value));
	ft_shift_lst(stack_a);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	int	value;

	value = (*stack_b) -> value;
	ft_unshift_lst(stack_a, ft_init_lst(value));
	ft_shift_lst(stack_b);
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

/* 
	TODO :
		-CREATE THE SORTING FUNCTIONS:
			*sa, sb, ss
			*pa, pb
			*ra, rb, rr
			*rra, rrb, rrr

		ok	sa = (swap a) swipe the two first elements of stack a.
		ok	sb = (swap b) // // // of stack b.
		ok	ss = trigger sa and sb
		ok	pa = (push a) push the first elem from stack b to stack a
		ok	pb = (push b) // // // from stack a to stack b
		ok	ra = (rotate a) the first element of stack a become the last
		ok	rb = (rotate b) the first element of stack b become the last
		ok	rr = trigger ra and rb
			rra = (reverse rotate a) the last element of stack a become the first
			rrb = (reverse rotate b) the last element of stack a become the first
			rrr = trigger rra and rrb

*/

