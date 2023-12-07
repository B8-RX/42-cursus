/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:02:28 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/04 15:02:36 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{:
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		ft_print_char(*str);
		str++;
	}
	return (count);
}

int	ft_handle_format(char f, va_list args)
{
	if (f == 'c')
		return (ft_print_char(va_arg(args, int))); 
	if (f == 's')
		return (ft_print_str(va_arg(args, (char *)));
	if (f == 'd')
		return (ft_print_deci(va_arg(args, float)));
	if (f == 'p')
		return (ft_print_nbr_base(va_arg(args, (void *), 16));
	if (f == 'i')
		return (ft_print_nbr(va_arg(args, int), 10)); 
	if (f == 'u')
		return (ft_print_deci(va_arg(args, float)));
	if (f == 'x')
		return (ft_print_nbr_base(va_arg(args, int), 16));
	if (f == 'X')
		return (ft_print_nbr(va_arg(args,int),16));
	if (f == '%')
		return (write(1, &(*format), 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if(*format == '%')
		{	
			format++;
			count+= ft_handle_format(*format, args);
		}
		else
		{
			count+= write(1, &(*format), 1);
			format++;
		}
	}
	return (count);
}

int	main(void)
{
//	int		arg1;
	char	arg2[] = "test";
	int		count;

//	arg1 = 5;
	count = ft_printf("%c", 'z');
	ft_printf("result :%d\n", count);
	return (0);
}
