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

	curr = stack;
	if (!curr)
		return;
	i = 0;
	printf("=================================================\n");
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
}

void	ft_sort_stack(t_stack **stack_a)
{
	// t_stack	*stack_b;
	t_stack	*tmp;
	int		small_value;
	int		high_value;
	size_t	total_length;
	size_t	current_index;

	// stack_b = malloc (sizeof(t_stack));
	// if (!stack_b)
	// 	return (NULL);
	printf("TEST SORT: %d\n", (*stack_a) -> value);
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
		// if (tmp -> index == (*stack_a) -> previous -> index)
		// 	current_index = 0;
	}
	printf("\n\nSMALLEST VALUE: %d\n", small_value);
	printf("HIGHEST VALUE: %d\n", high_value);
	printf("TOTAL LENGTH: %zu|\n", total_length);
}

/* 
	TODO :
		-CREATE THE SORTING FUNCTIONS:
			*sa, sb, ss
			*pa, pb
			*ra, rb, rr
			*rra, rrb, rrr

			sa = (swap a) swipe the two first elements of stack a.
			sb = (swap b) // // // of stack b.
			ss = trigger sa and sb
			pa = (push a) from stack a to stack b
			pb = (push b) from stack b to stack a
			ra = (rotate a) the first element of stack a become the last
			rb = (rotate b) the first element of stack b become the last
			rr = trigger ra and rb
			rra = (reverse rotate a) the last element of stack a become the first
			rrb = (reverse rotate b) the last element of stack a become the first
			rrr = trigger rra and rrb

*/

void	ft_sa(t_stack *stack_a)
{
	t_stack	*first_elem;
	int		tmp_value;

	first_elem = stack_a;
	tmp_value = first_elem -> value;
	first_elem -> value = first_elem -> next -> value;
	first_elem -> next -> value = tmp_value;
}

void	ft_sb(t_stack *stack_b)
{
	t_stack	*first_elem;
	int		tmp_value;

	first_elem = stack_b;
	tmp_value = first_elem -> value;
	first_elem -> value = first_elem -> next -> value;
	first_elem -> next -> value = tmp_value;
}
//
// void	ft_pb(t_stack *stack_a, t_stack *stack_b)
// {
// 	size_t	last_index;
//
// 	last_index = ft_get_last_index(stack_b);
// 	ft_add_lst_front(&stack_b, stack_a -> value, last_index);
// }
//
// size_t	ft_get_last_index(t_stack *stack)
// {
// 	size_t	i;
//
// 	i = 0;
// 	while ()
// 	{
//
// 	}
// 	return (i);
// }
