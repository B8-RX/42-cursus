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

	if (argc == 2)
		ft_handle_second_arg(argv);
	

	return (*stack_a);
}

int	ft_is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (-1);
}

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
}

char	**ft_handle_second_arg(char **argv)
{
	char	**array_args;  
	char	*arg;
	int		total_words;
	int		i;
	int		j;
	int		array_index;
	int		args_index;

	arg = argv[1];
	total_words = ft_count_words(arg);
	array_args = malloc(total_words * sizeof(char*) + 1);
	if (!array_args)
		return (NULL);
	i = 0;
	array_index = 0;
	args_index = 0;
	while (arg[i] != '\0' && total_words > 0)
	{
		while (arg[i] == ' ')
			i++;
		j = 0;
		while (arg[i + j] != '\0')
		{
			if (ft_is_digit(arg[i + j]) == -1 && arg[i + j] != ' ')
			{
				ft_print_error();
				return (NULL);
			}
			j++;
		}
		array_args[array_index] = malloc (j + 1);
		if (!array_args[array_index])
		{
			j = 0;
			while (array_args[j])
				free(array_args[j++]);
			free(array_args);
		}
		while ( arg[i] && arg[i] != ' ')
		{
			array_args[array_index][args_index] = arg[i];
			i++;
			args_index++;
		}
		printf("word: %s\n", array_args[array_index]);
		array_index++;
		total_words--;
	}
	return (array_args);
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
