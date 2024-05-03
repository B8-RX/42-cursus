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

t_stack	*ft_prepare_sort_stack(t_stack **stack_a)
{
	t_stack			*stack_b;
	int				small_value;
	int				high_value;
	size_t			stack_len;
	size_t			i;
	static size_t	total_operations;
	size_t			total_values;

	stack_b = NULL;
	stack_len = ft_get_stack_len(*stack_a);
	total_values = stack_len;
	small_value = ft_get_sm_value(*stack_a);
	high_value = ft_get_bg_value(*stack_a);
	ft_printf("\nSMALLEST VALUE: %d\nHIGHEST VALUE: %d\nTOTAL LENGTH: %u\n",
		small_value,
		high_value,
		(unsigned int)stack_len);
	i = 0;
	total_operations = 0;
	if (stack_len > 3 && !ft_is_sorted(*stack_a))
	{
		while (i++ < 3)
			ft_pb(stack_a, &stack_b);
		total_operations += (i - 1) ;
	}
	ft_print_all_stacks(*stack_a, stack_b);
	i = 0;
	t_stack	*best_position_pb;
	while ((stack_len || !ft_is_sorted(stack_b)))
	{
		total_operations += ft_sort_stacks(stack_a, &stack_b, total_operations);
		if (stack_len)
		{
		ft_printf("###########################loop: [%u]##############################\n", (unsigned int)++i);
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
				ft_printf("\n69= prepare()===candidate value [%d]====\n", (*stack_a)-> value);
				best_position_pb = stack_b;
				if (!ft_position_in_neighbour(stack_b, (*stack_a) -> value))
					best_position_pb = ft_found_best_start(&stack_b, (*stack_a)-> value);
				ft_pb(stack_a, &best_position_pb);
				stack_b = ft_get_lst_by_index(&stack_b, 0);
				ft_printf("\n75= prepare()===stack_b head value [%d]====\n", stack_b-> value);
				ft_print_stack(stack_b);
				total_operations++;
				ft_printf("%10s\n", "=pb=");
			}
			ft_print_all_stacks(*stack_a, stack_b);
			ft_printf(" --leak-check=full### TOTAL OPERATIONS: [%u]\n", (unsigned int)total_operations);
		}
		stack_len = ft_get_stack_len(*stack_a);
	}
	ft_printf("\t\t\t------------------------STACK B SORTED-------------------\n\n");
	if (stack_b)
	{
		
		while (ft_get_stack_len(stack_b))
		{
			ft_pa(stack_a, &stack_b);
			total_operations++;
		}
		// ft_print_stack(*stack_a);
	}
	ft_print_all_stacks(*stack_a, stack_b);
	ft_printf("### TOTAL VALUES: [%u]\n", (unsigned int)total_values);
	ft_printf("TOTAL OPERATIONS: [%u]\n", (unsigned int)total_operations);
	return (*stack_a);
}


size_t	ft_sort_stacks(t_stack **stack_a, t_stack **stack_b, size_t total_operations)
{
	t_stack		*curr_b;
	t_stack		*curr_a;
	size_t		stack_len_a;
	size_t		i;
	size_t		j;

	stack_len_a = ft_get_stack_len(*stack_a);
	curr_b = *stack_b;
	curr_a = *stack_a;
	i = 0;
	j = 0;
	ft_printf("\n\\===============START SORTING STACK==============>\n");
	while (!ft_is_sorted(curr_b))
	{
		ft_printf("==SORT STACK ==== \n");
		if (ft_match_condition_rb(curr_b)) 
		{
			if (ft_match_condition_ra(curr_a))
			{				
				ft_printf("\\\\sub loop: %u//\n", (unsigned int)++i);
				ft_printf("%10s", "=rr=");
				ft_rr(&curr_a, &curr_b);
				total_operations += 2;
			}
			else
			{
				ft_printf("\\\\sub loop: %u//\n", (unsigned int)++i);
				ft_printf("%10s", "=rb=");
				ft_rb(&curr_b);
				total_operations++;
			}
			ft_print_all_stacks(curr_a, curr_b);
		}
		else if (ft_match_condition_rrb(curr_b))
		{
			if (ft_match_condition_rra(curr_a))
			{
				ft_printf("\\\\sub loop: %u//\n", (unsigned int)++i);
				ft_printf("%10s", "=rrr=");
				ft_rrr(&curr_a, &curr_b);
				total_operations += 2;
			}
			else
			{
				ft_printf("\\\\sub loop: %u//\n", (unsigned int)++i);
				ft_printf("%10s", "=rrb=");
				ft_rrb(&curr_b);
				total_operations++;
			}
			ft_print_all_stacks(curr_a, curr_b);
		}
		else if (ft_match_condition_sb(curr_b))
		{
			if (ft_match_condition_sa(curr_a))
			{
				ft_printf("\\\\sub loop: %u//\n", (unsigned int)++i);
				ft_printf("%10s" ,"=ss=");
				ft_ss(&curr_a, &curr_b);
				total_operations += 2;
			}
			else
			{
				ft_sb(&curr_b);
				total_operations++;
				ft_printf("\\\\sub loop: %u//\n", (unsigned int)++i);
				ft_printf("%10s" ,"=sb=");
			}		
			ft_print_all_stacks(curr_a, curr_b);
		}
		// else
		// {
		// 	while ((curr_b -> value) < (curr_b -> next -> value))
		// 	{
		// 		ft_printf("~~~~~~~~~~~~~~~~~~\n");
		// 		ft_printf("~sub sub loop [%u]~\n",(unsigned int)++j);
		// 		ft_printf("~~~~~~~~~~~~~~~~~~\n");
		// 		ft_sb(&curr_b);
		// 		ft_printf("%10s" ,"=sb=\n");
		// 		ft_print_all_stacks(curr_a, curr_b);
		// 		if ((curr_b -> next -> value) < (curr_b -> next -> next -> value))
		// 		{
		// 			ft_rb(&curr_b);
		// 			ft_printf("%10s" ,"=rb=");
		// 			ft_print_all_stacks(curr_a, curr_b);
		// 		}
		// 		total_operations += 2;
		// 		ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		// 		ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
		// 	}
		// 	j = 0;
		// }
	}
	*stack_b = curr_b;
	*stack_a = curr_a;
	ft_printf("<===============END SORTING STACK================/\n\n");
	return (i + j);
}
