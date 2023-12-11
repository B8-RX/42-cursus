/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:49:42 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/11 19:49:49 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_unsigned(unsigned int nb, int size)
{
	char	num;
	
	if (nb > 9)
	{
		size = 1 + ft_print_unsigned(nb /10, size);
		num = nb % 10 + '0';
		write(1, &num, 1);
	}
	else 
	{
		num = nb + '0';
		size += write(1, &num, 1);
	}
	return (size);
}
