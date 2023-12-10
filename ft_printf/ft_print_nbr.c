/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:57:14 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/10 19:57:16 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr(int nb, int size)
{
	char	num;

	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		size += write(1, "-", 1);
		return (ft_print_nbr(-nb, size));
	}
	if (nb > 9)
	{
		size = 1 + ft_print_nbr(nb / 10, size);
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
