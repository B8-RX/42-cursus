/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
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
	int		*sorted_entries;

	sorted_entries = NULL;
	if (!ft_init_stack(&stack_a))
		return (0);
	if (argc == 1)
		return (0);
	stack_a = ft_handle_args(argc, argv, &stack_a);
	// if (stack_a)
		// sorted_entries = ft_sort_input(&stack);
	// else
		// return ft_print_error();
	ft_free_stack(stack_a);
	return (0);
}

t_stack	*ft_init_stack(t_stack **stack)
{
	*stack = malloc (sizeof(t_stack));
	if (!*stack)
		return (NULL);
	(*stack) -> next = NULL;
	return (*stack);
}

t_stack	*ft_handle_args(int argc, char **argv, t_stack **stack)
{
	char	**args;
	int		i;

	args = NULL;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	i = -1;
	while (args && args[++i])
	{
		printf("word: |%s|\n", args[i]);
		// stack = ft_add_back_lst(stack, i);	
		if (argc == 2 && args)
			free(args[i]);
	}
	if (argc == 2 && args)
		free(args);
	// ft_print_values_lst(stack);
	return (*stack);
}

t_stack	**ft_add_back_lst(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack *curr;

	curr = *stack;
	new = malloc (sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> value = value + 15;
	new -> index = value;
	while (curr -> next)
		curr = curr -> next;
	curr = new;
	curr -> next = NULL;
	return (stack);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack -> next)
	{
		tmp = stack;
		printf("FREE LINK tmp-> value: |%d|\n", tmp -> value); 
		stack = stack -> next;
		free(tmp);
	}
	free(stack);	
}


/*

TODO


 # verifier le nombre d'argument (argc)
	ok* si le nombre d'argument == 1 ===> return (0)


 # traiter les arguments ====> ft_handle_args().
	(en cas d'erreur de format, afficher un message d'erreur sur le stderror)
	ok- si le nombre d'arguments == 2  ===> ft_handle_second_args()
	ok- split les arguments  ====> ft_split_args()
	- transformer les nombres en format char* en int  ====> ft_atoi()
	- verifier qu'il n'y a pas de doublons  ===> ft_check_if_duplicate_nbr()
	- assigner chaque arguments dans la liste circulaire (stack a) ==> ft_put_entries_in_stack()
 
 # trier les arguments par ordre croissant  ====> ft_sort_input()
	-
	-
	-
	-
	-
 
*/
