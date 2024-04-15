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

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		parity;
	int		i;

	i = 0;
	parity = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			parity = -1;
		i++;
	}	
	res = (str[i] - '0');
	i++;
	while (str[i])
	{
		if (res > ((2147483647 - (str[i] - '0')) / 10))
		{
			if (parity == 1)
				return (2147483647);
			return (-2147483648);
		}	
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * parity); 
}

int	ft_get_len_value(char *value)
{
	int	j;

	j = 0;
	while (value[j] && value[j] != ' ')
		j++;
	return (j);
}

void	ft_print_values_lst(t_stack *stack)
{
	t_stack	*curr;
	int		i;
	
	curr = stack;
	if (!curr)
		return;
	i = 0;
	while (i++ <= (curr -> index))
	{
		printf("=================================================\n");
		printf("curr value: %d\n", curr -> value);
		printf("curr index: %d\n", curr -> index);
		printf("///////////////////////===>\n");
		printf("previous value: %d\n", curr -> previous -> value);
		printf("previous index: %d\n", curr -> previous -> index);
		printf("///////////////////////===>\n");
		printf("next value: %d\n", curr -> next -> value);
		printf("next index: %d\n", curr -> next -> index);
		curr = curr -> next;
	}
	printf("===================PRINT VALUES=======================\n");

}
