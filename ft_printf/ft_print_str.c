/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:57:29 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/10 19:57:31 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str, int size)
{
	if (!str)
		return (ft_print_str("(null)", size));
	while (*str != '\0')
	{
		size += ft_print_char(*str);
		str++;
	}
	return (size);
}
