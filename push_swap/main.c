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

	t_stack_a	*stack_a;
	int			*sorted_entries;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	ft_handle_args(argv, &stack_a);
	if (stack_a)
		sorted_entries = ft_sort_input(&stack_a);
	else
		return ft_print_error();

	return (0);
}

/*

TODO

 # creer une liste circulaire (stack a)
	* liste circulaire 1 membre type entier et deux membres type struct (previous, next)

 # verifier le nombre d'argument (argc)
	* si le nombre d'argument == 1 ===> return (0)

 # traiter les arguments ====> ft_handle_args().
	(en cas d'erreur de format, afficher un message d'erreur sur le stderror)
	- si le nombre d'arguments == 2  ===> ft_handle_second_args()
	- split les arguments  ====> ft_split_args()
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
