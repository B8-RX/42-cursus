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
	if (stack_a)
		ft_sort_stack(&stack_a);
	// else
	// 	return (ft_print_error());
	// ft_sa(stack_a);
	if (stack_a)
	{
		// ft_print_values_lst(stack_a);
		ft_free_stack(stack_a);
	}
	return (0);
}

t_stack	*ft_handle_args(t_stack **stack, int argc, char **argv)
{
	char	**args;
	size_t	i;

	args = NULL;
	if (argc == 2)
		args = ft_split(argv[1], 32);
	else
		args = argv + 1;
	i = 0;
	while (args && args[i])
	{
		if (!ft_is_digit(args[i]))
		{
			if (argc == 2)
				ft_free_array_str(args);	
			return (NULL);
		}
		if (!ft_add_lst_back(stack, ft_atoi(args[i])))
			break;
		i++;
	}
	if (argc == 2 && args)
		ft_free_array_str(args);
	return (*stack);
}

t_stack	*ft_get_lst_by_index(t_stack *stack, size_t index)
{
	t_stack	*lst;

	lst = stack;
	if (!stack)
		return (NULL);
	while (lst -> index != index)
		lst = lst -> next;
	return (lst);
}

t_stack	**ft_add_lst_back(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack *last;

	new = malloc (sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> value = value;
	if (!*stack)
	{
		new -> next = new;
		new -> previous = new;
		new -> index = 0;
		*stack = new;
	}
	else
	{
		new -> index = (*stack) -> previous -> index;
		last = (*stack) -> previous;	
		last -> next = new;
		new -> previous = last;
		new -> next = *stack;
		(*stack) -> previous = new;
	}
	return (stack);
}

t_stack	**ft_add_lst_front(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc (sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> value = value;
	new -> index = 0;
	new -> next = new;
	new -> previous = new;
	if (*stack)
	{
		(*stack) -> previous = new;
		new -> next = *stack;
		ft_update_stack_index(*stack);
		last = (*stack) -> previous;
		new -> previous = last;
		last -> next = new;
	}
	*stack = new;
	return (stack);
}

void	ft_update_stack_index(t_stack *stack)
{
	t_stack	*curr;
	size_t	i;

	i = 1;
	curr = stack;
	curr -> index = i;
	while (++i <= curr -> index)
	{
		printf("curr index: %ld\n", i);
		curr = curr -> next;
		curr -> index = i;
	}
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*curr;
	size_t	last_index;
	size_t	i;

	last_index = stack -> previous -> index;
	curr = stack;
	i = 0;
	while (i++ < last_index)
	{
		printf("///////////////////////===>\n");
		tmp = curr;
		printf("FREE stack -> index: |%ld|\n", tmp -> index); 
		printf("FREE stack -> value: |%d|\n", tmp -> value); 
		curr = curr -> next;
		free(tmp);
	}
	if (curr)
		{
		printf("///////////////////////===>\n");
		printf("+FREE stack -> index: |%ld|\n", curr -> index); 
		printf("+FREE stack -> value: |%d|\n", curr -> value); 
		printf("///////////////////////===>\n");
		free(curr);	
	}
}


/*

TODO


 # verifier le nombre d'argument (argc)
	ok- si le nombre d'argument == 1 ===> return (0)


 # traiter les arguments ====> ft_handle_args().
	ok- si le nombre d'arguments == 2  ===> ft_handle_second_args()
	ok- split les arguments  ====> ft_split_args()
	ok- transformer les nombres en format char* en int  ====> ft_atoi()
	ok- assigner chaque arguments dans la liste circulaire (stack a) ==> ft_add_lst_back() ou ft_add_lst_front()
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
