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

	stack_a = NULL;
	sorted_entries = NULL;
	if (argc == 1)
		return (0);
	ft_handle_args(argc, argv, &stack_a);
	// if (stack_a)
		// sorted_entries = ft_sort_input(&stack);
	// else
		// return ft_print_error();

	return (0);
}

t_stack	*ft_handle_args(int argc, char **argv, t_stack **stack_a)
{
	char	**tmp;
	int		i;

	tmp = NULL;
	if (argc == 2)
		tmp = ft_handle_second_arg(argv);
	i = 0;
	if (tmp)
	{
		while (tmp[i])
		{
			printf("word: |%s|\n", tmp[i]);
			free(tmp[i]);
			i++;
		}
		free(tmp);			
	}
	return (*stack_a);
}

char	**ft_handle_second_arg(char **argv)
{
	char	*args;

	args = argv[1];
	return (ft_split(args, ' '));
}

int	ft_count_words(char *arg)
{
	int		i;
	int		words;
	int		blank;
	
	i = -1;
	blank = 0;

	// if (!arg)
		// return ft_print_error();
	
	if (*arg && *arg == ' ')
		words = 0;
	else
		words = 1;
	while (arg[++i] != '\0')
	{
		while (arg[i + blank] == ' ')
			blank++;
		if (blank > 1)
			i+= blank - 1;
		if (blank && arg[i] && arg[i + 1] != '\0')
			words++;
		blank = 0;
	}
	return words;
}
/*

TODO


 OK
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
