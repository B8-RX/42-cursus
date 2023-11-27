/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:52:02 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/18 22:52:05 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int arg)
{
	if (arg >= 32 && arg <= 126)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	c;

// 	c = 1;
// 	while (c <= 127)
// 	{
// 		if (ft_isprint(c) != 0)
// 			printf("|%c| ", c);
// 		c++;
// 	}
// 	return (0);
// }