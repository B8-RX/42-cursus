/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:56:59 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/10 19:57:01 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hexa(unsigned long nb, int size, char format, char *base)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nb > base_len)
	{
		size = 1 + ft_print_hexa(nb / base_len, size, format, base);
		write(1, &base[nb % base_len], 1);	
	}
	else
	{
		if (format == 'p')
			size +=	write(1, "0x", 2);
		size += write(1, &base[nb], 1);
	}
	return (size);
}
