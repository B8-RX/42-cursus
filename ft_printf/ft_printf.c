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

#include "libftprintf.h"

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
		if(format[i] == '%' && format[i + 1])
		{	
			if (ft_strchr("csdiupxX%",format[i + 1]))
			{	
				count+= ft_handle_format(format[i + 1], args);
				i += 2;
			}
			else
				return (count+= write(1, &format[i], 1));
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
