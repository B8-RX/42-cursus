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
{
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

int	ft_print_nbr(int nb, int size, char format)
{

	char	num;
	
	if (format != 'u')
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return (11);
		}
		if (nb < 0)
		{
			write(1, "-", 1);
			size++;
			ft_print_nbr(-nb, size, format);	
		}
	}
	if (nb > 9)
	{
		size++;
		ft_print_nbr(nb / 10, size, format);
		num = nb % 10 + '0';
		write(1, &num, 1);
	}
	else
	{
		num = nb + '0';
		write(1, &num, 1);
	}
	return (size);
}

int	ft_handle_format(char f, va_list args)
{
	if (f == 'c')
		return (ft_print_char(va_arg(args, int))); 
	if (f == 's')
		return (ft_print_str((char *)va_arg(args, void *)));
	if (f == 'd')
		return (ft_print_nbr(va_arg(args, int), 0, f));
	if (f == 'u')
		return (ft_print_nbr(va_arg(args, unsigned int), 0, f));
	if (f == 'i')
		return (ft_print_nbr(va_arg(args, int), 0, f)); 
	// if (f == 'p')
	// 	return (ft_print_nbr_base(va_arg(args, (void *), 16));
	// if (f == 'x')
	// 	return (ft_print_nbr_base(va_arg(args, int), 16));
	// if (f == 'X')
	// 	return (ft_print_nbr(va_arg(args,int),16));
	// if (f == '%')
	// 	return (write(1, &(*format), 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if(format[i] == '%')
		{	
			count+= ft_handle_format(format[i + 1], args);
			i += 2;
		}
		else
		{
			count+= write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	printf("printf: count => %d\n", count);
	return (count);
}

int	main(void)
{
	int	count;
	// char	c = 'z';	
	// char	str[] = "test";
	// int		int_min = -2147483648;
	// int		int_max = 2147483647;
	// int		nbr_positive = 42;
	int		nbr_negative = -42;
	// int		nbr_unsigned = 42;

	count = 0;
//	arg1 = 5;
	// count = ft_printf("%c\n", c);// test char
	// count = ft_printf("%s\n", str); // test string
	// count = ft_printf("%d\n", nbr_positive); // test positive num
	count = ft_printf("%i\n", nbr_negative); // test negative num
	// count = ft_printf("%u\n", nbr_unsigned); // test unsigned int
	printf("result :%d\n", count);
	return (0);
}
