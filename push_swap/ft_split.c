/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 01:26:18 by ssghioua          #+#    #+#             */
/*   Updated: 2024/04/05 01:26:20 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

char	**ft_split(char *str, char splitter)
{

	char	**parent_array;  
	int		i;
	int		child;

	if (ft_count_words(str, splitter) == -1)
		return (ft_print_error(), NULL);
	parent_array = malloc(ft_count_words(str, splitter) * sizeof(char*) + sizeof(void*));
	if (!parent_array)
		return (NULL);
	i = 0;
	child = 0;
	while (str[i] != '\0')
	{	
		i+= ft_count_spaces(str + i);
		if (ft_count_value_len(str + i))
			parent_array[child] = malloc (ft_count_value_len(str + i) + 1);
		if (!parent_array[child])
			return (ft_free_parent_array(parent_array));
		i += ft_push_value(parent_array[child], str + i, splitter);
		child++;
	}
	parent_array[child] = NULL;
	return (parent_array);
}

int	ft_push_value(char *parent_array, char *value, char splitter)
{
	int	child;
	int	i;

	i = 0;
	child = 0;
	while ( value[i] && value[i] != splitter)
	{
		parent_array[child] = value[i];
		i++;
		child++;
	}
	parent_array[child] = '\0';
	return (i);
}

void	*ft_free_parent_array(char **parent_array)
{

	int	i;

	printf("FREE PARENT ARRAY\n");
	i = 0;
	while (parent_array[i])
	{
		free(parent_array[i]);
		i++;
	}
	free(parent_array);
	return (NULL);
}

int	ft_count_words(char *str, char splitter)
{
	int		i;
	int		words;
	
	i = 0;
	words = 0;
	if (!str || (*str != splitter && !ft_is_digit(*str)))    
		return (-1);
	while (str[i] != '\0')
	{
		while (str[i] == splitter)
			i++;
		if (ft_is_digit(str[i]))
		{
			while (ft_is_digit(str[i]))
				i++;
			words++;
		}	
		if (str[i] != '\0' && !ft_is_digit(str[i]) && str[i] != splitter)
			return (-1);
	}
	return words;
}
