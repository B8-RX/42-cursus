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
	// t_stack	*sorted_entries;
	//
	// sorted_entries = NULL;
	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (!ft_handle_args(&stack_a, argc, argv))
		return (ft_print_error(), 0);
	if (!ft_sort_stack(&stack_a))
		return (ft_print_error(), 0);
	if (stack_a)
	{
		// ft_print_values_lst(stack_a);
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
		new = ft_init_lst(ft_atoi(args[i]), 'A');
		if (!new)
			break;
		if (!ft_push_lst(stack_a, new))
			break;
		// if (!ft_unshift_lst(stack_a, new))
			// break;
		i++;
	}
	if (argc == 2)
		ft_free_array_str(args);	
	return (*stack_a);
}



/*

TODO


 # verifier le nombre d'argument (argc)
	ok- si le nombre d'argument == 1 ===> return (0)


 # traiter les arguments ====> ft_handle_args().
	ok- si le nombre d'arguments == 2  ===> ft_handle_second_args()
	ok- split les arguments  ====> ft_split_args()
	ok- transformer les nombres en format char* en int  ====> ft_atoi()
	ok- assigner chaque arguments dans la liste circulaire (stack a) ==> ft_push_lst() ou ft_unshift_lst()
	ok- (en cas d'erreur de format, afficher un message d'erreur sur le stderror)
	- verifier qu'il n'y a pas de doublons  ===> ft_check_if_duplicate_nbr()
 
 # creer les fonctions de trie : 
	-sa, sb, ss, ra, rb, rr, pa, pb, rra, rrb, rrr 
	-
	-
	-
	-
	-
 
*/
