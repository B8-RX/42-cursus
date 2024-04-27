/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:40:21 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/27 18:40:25 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/push_swap.h"

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

int	ft_handle_error(t_stack *stack_a)
{
	if (stack_a)
		ft_free_linked_list(stack_a);
	write(2, "Error\n", 6);
	return (0);
}
