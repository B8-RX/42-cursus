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

#include "./lib/push_swap.h"

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
			return (1);
	}
	return (0);
}

int	ft_handle_error(t_stack *stack_a)
{
	if (stack_a)
		ft_free_stack(stack_a);
	write(2, "Error\n", 6);
	return (0);
}

int	ft_count_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi_2(const char *str)
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
	ft_printf("FUNCTION SORT\n");
	stack_len = ft_get_stack_len(*stack_a);
	small_value = ft_get_sm_value(*stack_a);
	high_value = ft_get_bg_value(*stack_a);
	ft_printf("\nSMALLEST VALUE: %d\nHIGHEST VALUE: %d\nTOTAL LENGTH: %u\n",
		small_value,
		high_value,
		(unsigned int)stack_len);
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
