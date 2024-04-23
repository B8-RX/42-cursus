/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:11:41 by ssghioua          #+#    #+#             */
/*   Updated: 2024/03/29 01:11:46 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{

	t_stack	*stack_a;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (!ft_handle_args(&stack_a, argc, argv))
		return (ft_print_error(), 0);
	if (!ft_prepare_sort_stack(&stack_a))
		return (ft_print_error(), 0);
	if (stack_a)
	{
		ft_free_stack(stack_a);
	}
	return (0);
}

t_stack	*ft_handle_args(t_stack **stack_a, int argc, char **argv)
{
	char	**args;
	t_stack	*new;
	size_t	i;

	args = NULL;
	new = NULL;
	if (argc == 2)
		args = ft_split(argv[1], 32);
	else
		args = argv + 1;
	i = 0;
	if (!args)
		return (NULL);
	while (args && args[i])
	{
		if (!ft_is_digit(args[i]))
		{
			if (argc == 2)
				ft_free_array_str(args);
			ft_free_stack(*stack_a);
			return (NULL);
		}
		new = ft_init_lst(ft_atoi_2(args[i]), 'A');
		if (!new)
			break;
		if (!ft_push_lst(stack_a, new))
			break;
		i++;
	}
	if (argc == 2)
		ft_free_array_str(args);	
	return (*stack_a);
}
