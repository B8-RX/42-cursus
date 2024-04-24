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

#include "./lib/push_swap.h"

int	main(int argc, char **argv)
{

	t_stack	*stack_a;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (!ft_handle_args(&stack_a, argc, argv))
		return (ft_handle_error(stack_a));
	if (!ft_prepare_sort_stack(&stack_a))
		return (ft_handle_error(stack_a));
	if (stack_a)
		ft_free_stack(stack_a);
	return (0);
}

t_stack	*ft_handle_args(t_stack **stack_a, int argc, char **argv)
{
	char	**args;
	
	args = NULL;
	if (argc == 2)
		args = ft_split(argv[1], 32);
	else
		args = argv + 1;
	if (!ft_populate_stack(stack_a, argc, args))
		return (NULL);
	return (*stack_a);
}

int	ft_populate_stack(t_stack **stack_a, int argc, char **args)
{
	size_t	i;

	i = 0;
	if (!args)
		return (0);
	while (args && args[i])
	{
		if (ft_is_digit(args[i])
			|| !ft_push_lst(stack_a, ft_init_lst(ft_atoi_2(args[i]), 'A')))
		{
			if (argc == 2)
				ft_free_array_str(args);
			return (0);
		}
		i++;
	}
	if (argc == 2)
		ft_free_array_str(args);
	return (1);
}
