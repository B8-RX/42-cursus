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

t_stack	*ft_prepare_sort_stack(t_stack **stack_a)
{
	t_stack			*stack_b;
	int				small_value;
	int				high_value;
	size_t			stack_len;
	size_t			i;
	static size_t	total_operations;

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
	total_operations = 0;
	if (stack_len > 3)
	{
		while (i++ < 3)
			ft_pb(stack_a, &stack_b);
		total_operations = 3;
	}
	ft_print_stacks(*stack_a, stack_b);
	i = 0;
	while (stack_len || !ft_is_sorted(stack_b))
	{
		ft_sort_stacks(stack_a, &stack_b, total_operations);
		if (stack_len)
		{
			ft_printf("loop: %u\n", (unsigned int)++i);
			if (ft_match_condition_sa(*stack_a))
			{
				if (ft_match_condition_sb(stack_b))
				{
					ft_ss(stack_a, &stack_b);					
					total_operations += 2;
					ft_printf("%10s\n" ,"=ss=");
				}
				else
				{
					ft_sa(stack_a);
					total_operations++;
					ft_printf("%10s\n" ,"=sa=");
				}
			}
			if (stack_a)
			{
				ft_pb(stack_a, &stack_b);
				total_operations++;
				ft_printf("%10s\n", "=pb=");
			}
			ft_print_stacks(*stack_a, stack_b);
			ft_printf("### TOTAL OPERATIONS: [%u]\n", (unsigned int)total_operations);
		}
		stack_len = ft_get_stack_len(*stack_a);
	}
	ft_printf("\t\t\t------------------------STACK B SORTED-------------------\n\n");
	if (stack_b)
	{
		while (stack_b)
		{
			ft_pa(stack_a, &stack_b);
			total_operations++;
			ft_printf("%10s\n", "=pa=");
			ft_print_stacks(*stack_a, stack_b);
		}
		ft_pa(stack_a, &stack_b);
	}
	ft_printf("TOTAL OPERATIONS: [%u]\n", (unsigned int)total_operations);
	return (*stack_a);
}

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

int	ft_match_condition_rrb(t_stack *stack_b)
{
	t_stack	*curr_b;
	int		match_condition;

	curr_b = stack_b;
	match_condition = 0;
	if (!stack_b)
		return (0);
	if (curr_b -> value < curr_b -> previous -> value || curr_b -> next -> value < curr_b -> previous -> value)
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
		&& (curr_a -> value) < (curr_a -> previous -> value)
		&& (curr_a -> next -> value) > (curr_a -> previous -> value))
		match_condition = 1;
	return (match_condition);
}

int	ft_match_condition_rra(t_stack *stack_a)
{
	t_stack	*curr_a;
	int		match_condition;

	curr_a = stack_a;
	match_condition = 0;
	if (!stack_a)
		return (0);
	if (curr_a -> previous -> value != ft_get_bg_value(stack_a) && curr_a -> previous -> value > curr_a -> value
		&& curr_a -> previous -> value > curr_a -> next -> value)
		match_condition = 1;
	return (match_condition);
}

int	ft_match_condition_sa(t_stack *stack_a)
{
	int	match_condition;

	match_condition = 0;
	if (!stack_a)
		return (0);
	if ((stack_a -> value < (stack_a -> next -> value)
		&& (stack_a -> next -> value) < (stack_a -> previous -> value)))
		match_condition = 1;
	return (match_condition);
}

int	ft_match_condition_sb(t_stack *stack_b)
{
	int	match_condition;

	match_condition = 0;
	if (!stack_b)
		return (0);
	if ((stack_b -> value) < (stack_b -> next -> value) && (stack_b -> value) > (stack_b -> next -> next -> value))
		match_condition = 1;
	return (match_condition);
}

size_t	ft_sort_stacks(t_stack **stack_a, t_stack **stack_b, size_t total_operations)
{
	t_stack		*curr_b;
	t_stack		*curr_a;
	size_t		stack_len_a;
	size_t		i;
	int			j;

	stack_len_a = ft_get_stack_len(*stack_a);
	curr_b = *stack_b;
	curr_a = *stack_a;
	i = 0;
	ft_printf("\n\\===============START SORTING STACK==============>\n");
	while (!ft_is_sorted(curr_b))
	{
		if (ft_match_condition_rb(curr_b)) 
		{
			if (ft_match_condition_ra(curr_a))
			{				
				ft_rr(&curr_a, &curr_b);
				total_operations += 2;
				ft_printf("/////////////////\n");
				ft_printf("sub loop: %u\n", (unsigned int)++i);
				ft_printf("%10s", "=rr=");
			}
			else
			{
				ft_rb(&curr_b);
				total_operations++;
				ft_printf("/////////////////\n");
				ft_printf("sub loop: %u\n", (unsigned int)++i);
				ft_printf("%10s", "=rb=");
			}
			ft_print_stacks(curr_a, curr_b);
		}
		else if (ft_match_condition_rrb(curr_b))
		{
			if (ft_match_condition_rra(curr_a))
			{
				ft_rrr(&curr_a, &curr_b);
				total_operations += 2;
				ft_printf("/////////////////\n");
				ft_printf("sub loop: %u\n", (unsigned int)++i);
				ft_printf("%10s", "=rrr=");
			}
			else
			{
				ft_rrb(&curr_b);
				total_operations++;
				ft_printf("/////////////////\n");
				ft_printf("sub loop: %u\n", (unsigned int)++i);
				ft_printf("%10s", "=rrb=");
			}
			ft_print_stacks(curr_a, curr_b);
		}
		else if (ft_match_condition_sb(curr_b))
		{
			if (ft_match_condition_sa(curr_a))
			{
				ft_ss(&curr_a, &curr_b);
				total_operations += 2;
				ft_printf("/////////////////\n");
				ft_printf("sub loop: %u\n", (unsigned int)++i);
				ft_printf("%10s" ,"=ss=");
			}
			else
			{
				ft_sb(&curr_b);
				total_operations++;
				ft_printf("/////////////////\n");
				ft_printf("sub loop: %u\n", (unsigned int)++i);
				ft_printf("%10s" ,"=sb=");
			}		
			ft_print_stacks(curr_a, curr_b);
		}
		else
		{
			j = 0;
			while ((curr_b -> value) < (curr_b -> next -> value))
			{
				ft_sb(&curr_b);
				ft_rb(&curr_b);
				total_operations += 2;
				ft_printf("sub sub loop: %u\n", (unsigned int)++j);
				ft_printf("%10s" ,"=sb=\n");
				ft_printf("%10s" ,"=rb=");
				ft_print_stacks(curr_a, curr_b);
			}
		}
	}
	*stack_b = curr_b;
	*stack_a = curr_a;
	ft_printf("<===============END SORTING STACK================/\n\n");
	return (total_operations);
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
