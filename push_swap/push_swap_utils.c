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

int	ft_get_len_value(char *value)
{
	int	j;

	j = 0;
	while (value[j] && value[j] != ' ')
		j++;
	return (j);
}

void	ft_print_values_lst(t_stack **stack)
{
	t_stack	*curr;

	curr = *stack;
	if (!curr)
		return;
	if (curr -> next == NULL)
	{
		printf("value: %d\n", curr -> value);
		printf("index: %d\n", curr -> index);
	}
	while (curr -> next)
	{
		printf("value: %d\n", curr -> value);
		printf("index: %d\n", curr -> index);
		curr = curr -> next;
	}
}

t_stack	*ft_get_last_lst(t_stack *stack)
{
	t_stack	*curr_stack;

	curr_stack = stack;
	if (curr_stack -> next != NULL)
		while (curr_stack -> next)
			curr_stack = curr_stack -> next;
	return (curr_stack);
}


