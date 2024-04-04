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

#include "./push_swap.h"

int	ft_is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

char	*ft_print_error(void)
{
	write(2, "Error\n", 6);
	return (NULL);
}

int	ft_count_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

int	ft_count_num_len(char *arg)
{
	int	j;

	j = 0;
		while (arg[j] && arg[j] != ' ')
		{
			if (!ft_is_digit(arg[j]))
				return (0);
			j++;
		}
	return (j);
}

char	**ft_split(char *str, char separator)
{	

	char	**array_args;  
	int		total_words;
	int		i;
	int		j;
	int		array_index;
	int		args_index;

	total_words = ft_count_words(str);
	array_args = malloc(total_words * sizeof(char*) + sizeof(void*));
	if (!array_args)
		return (NULL);
	array_args[total_words] = NULL;
	i = 0;
	array_index = 0;
	while (str[i] != '\0' && total_words > 0)
	{
		
		while (str[i] == separator)
			i+= ft_count_spaces(str + i);
		j = ft_count_num_len(str + i);
		if (!j)
			return (ft_print_error(), NULL);
		array_args[array_index] = malloc (j + 1);
		if (!array_args[array_index])
		{
			printf("ERROR MALLOC\n");
			j = 0;
			while (array_args[j])
			{
				free(array_args[j]);
				j++;
			}
			free(array_args);
			return (NULL);
		}
		args_index = 0;
		while ( str[i] && str[i] != separator)
		{
			array_args[array_index][args_index] = str[i];
			i++;
			args_index++;
		}
		array_args[array_index][args_index] = '\0';
		array_index++;
		total_words--;
	}
	return (array_args);
}
