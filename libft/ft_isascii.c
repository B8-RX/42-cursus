/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:51:32 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/18 22:51:38 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int ch;

// 	ch = 0x7d;
// 	if (ft_isascii(ch))
// 		printf("The character is |%c|\n", ch);
// 	else
// 		printf("Cannot be represented by an ASCII character\n");
// 	return (0);
// }
