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

int	ft_is_digit(const char *str)
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

int	ft_count_spaces(const char *str)
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

int	ft_get_len_value(const char *value)
{
	int	j;

	j = 0;
	while (value[j] && value[j] != ' ')
		j++;
	return (j);
}


size_t	ft_get_stack_len(t_stack *stack)
{
	size_t	len;
	t_stack	*tmp;

	tmp = stack;
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

t_stack	*ft_prepare_sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		small_value;
	int		high_value;
	size_t	stack_len;
	size_t	i;

	stack_b = NULL;
	printf("FUNCTION SORT\n");
	stack_len = ft_get_stack_len(*stack_a);
	small_value = ft_get_sm_value(*stack_a);
	high_value = ft_get_bg_value(*stack_a);
	printf("\nSMALLEST VALUE: %d\nHIGHEST VALUE: %d\nTOTAL LENGTH: %zu\n",
		small_value,
		high_value,
		stack_len);
	i = 0;
	if (stack_len > 3)
		while (i++ < 3)
			ft_pb(stack_a, &stack_b);

	// TESTS :

	// ft_sa(stack_a);
	// ft_sb(&stack_b);
	// ft_ss(stack_a, &stack_b);
	// ft_ra(stack_a);
	// ft_rb(&stack_b);
	// ft_pa(stack_a, &stack_b);
	// ft_pb(stack_a, &stack_b);
	// ft_rr(stack_a, &stack_b);
	// ft_rra(stack_a);
	// ft_rrb(&stack_b);
	// ft_rrr(stack_a, &stack_b);
	if (stack_b)
	{
		ft_print_stacks(*stack_a, stack_b);
		ft_free_stack(stack_b);
	}
	return (*stack_a);
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
		ok	rra = (reverse rotate a) the last element of stack a become the first
		ok	rrb = (reverse rotate b) the last element of stack a become the first
		ok	rrr = trigger rra and rrb

*/

