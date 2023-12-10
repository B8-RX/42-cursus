/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:57:43 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/10 19:57:44 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handle_format(char f, va_list args)
{
	int	len;

	len = 0;
	if (f == 'c')
		return (ft_print_char(va_arg(args, int))); 
	if (f == 's')
		return (ft_print_str((char *)va_arg(args, void *), len));
	if (f == 'd')
		return (ft_print_nbr(va_arg(args, int), len));
	if (f == 'u')
		return (ft_print_nbr(va_arg(args, unsigned int), len));
	if (f == 'i')
		return (ft_print_nbr(va_arg(args, int), len)); 
	if (f == 'p')
		return (ft_print_hexa(va_arg(args, unsigned long), len, f, "0123456789abcdef"));
	if (f == 'x')
		return (ft_print_hexa(va_arg(args, unsigned int), len, f, "0123456789abcdef"));
	if (f == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), len, f, "0123456789ABCDEF"));
	if (f == '%')
		return (write(1, "%", 1));
	return (0);
}
