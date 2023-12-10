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


size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str, int size)
{
	while (*str != '\0')
	{
		size += ft_print_char(*str);
		str++;
	} 
	return (size);
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
			size += write(1, "-", 1);
			return (ft_print_nbr(-nb, size, format));
		}
	}
	if (nb > 9)
	{
		size = 1 + ft_print_nbr(nb / 10, size, format);
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
		{
			write(1, "0x", 2);
			size += 2;
		}
		write(1, &base[nb], 1);
		size++;
	}
	return (size);
}

int	ft_handle_format(char f, va_list args)
{
	int	len;

	len = 0;
	if (f == 'c')
		return (ft_print_char(va_arg(args, int))); 
	if (f == 's')
		return (ft_print_str((char *)va_arg(args, void *), len));
	if (f == 'd')
		return (ft_print_nbr(va_arg(args, int), len, f));
	if (f == 'u')
		return (ft_print_nbr(va_arg(args, unsigned int), len, f));
	if (f == 'i')
		return (ft_print_nbr(va_arg(args, int), len, f)); 
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
	return (count);
}

int	main(void)
{
	int	count_ft_printf = 0;
	int	count_printf = 0;
	
//------------------------------test char--------------------------------//

	// char	c = 'z';	
	// count_ft_printf = ft_printf("%c\n", c);
	// printf("result ft_printf:%d\n", count_ft_printf); 

	//---- test with original printf function------//
	
	// count_printf = printf("%c\n", c);
	// printf("result printf :%d\n", count_printf);


//------------------------------test string--------------------------------//
	
	// char	str[] = "test 1 2 3 abracadabra";
	// count_ft_printf = ft_printf("%s\n", str); // test string
	// printf("result ft_printf:%d\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("%s\n", str);
	// printf("result printf :%d\n", count_printf);



//------------------------------test INT_MIN--------------------------------//
	
	// int		int_min = -2147483648;
	// count_ft_printf = ft_printf("%d\n", int_min); // test INT_MIN
	// printf("result ft_printf:%d\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("%d\n", int_min);
	// printf("result printf :%d\n", count_printf);

//------------------------------test INT_MAX--------------------------------//
	
	// int		int_max = 2147483647;
	// count_ft_printf = ft_printf("%d\n", int_max); // test INT_MAX
	// printf("result ft_printf:%d\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("%d\n", int_max);
	// printf("result printf :%d\n", count_printf);

//------------------------------test positive num--------------------------------//
	
	// int		nbr_positive = 42;
	// count_ft_printf = ft_printf("%d\n", nbr_positive); // test positive num
	// printf("result ft_printf:%d\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("%d\n", nbr_positive);
	// printf("result printf :%d\n", count_printf);

//------------------------------test negative num--------------------------------//
	
	int		nbr_negative = -421154562;
	count_ft_printf = ft_printf("%X\n", nbr_negative); // test negative num
	printf("result ft_printf:%d\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	count_printf = printf("%X\n", nbr_negative);
	printf("result printf :%d\n", count_printf);

//------------------------------test unsigned int--------------------------------//
	
	// int		nbr_unsigned = 42;
	// count = ft_printf("%u\n", nbr_unsigned); // test unsigned int
	// printf("result ft_printf:%d\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("%p\n", ptr);
	// printf("result printf :%d\n", count_printf);

//------------------------------test hexa lower--------------------------------//
	// count = ft_printf("%x\n", nbr_positive); // test hexa lower case
	// printf("result ft_printf:%d\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("%p\n", ptr);
	// printf("result printf :%d\n", count_printf);

//------------------------------test hexa upper--------------------------------//
	// count = ft_printf("%X\n", nbr_positive); // test hexa upper case
	// printf("result ft_printf:%d\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("%p\n", ptr);
	// printf("result printf :%d\n", count_printf);

//------------------------------test pointer--------------------------------//

	// int		*ptr = &nbr_positive;
	// count_ft_printf = ft_printf("%p\n", ptr); // test pointer	
	// printf("result ft_printf:%d\n", count_ft_printf); 
	
	//---- test with original printf function------//
	
	// count_printf = printf("%p\n", ptr);
	// printf("result printf :%d\n", count_printf);

	
	//--------------------------------- test return value of ft_printf function--------------------------------//
	
	
	//--------------------------------- test with original printf function--------------------------------//

	// count_printf = printf("%p\n", ptr);
	// printf("result printf :%d\n", count_printf);
	
	return (0);
}
