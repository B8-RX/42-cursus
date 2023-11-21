/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:58:50 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/18 22:56:35 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*
int	main(void) {

	char * input = "Diego De La Vega";
	int	i;

	i = 0;
	while (input[i])
	{
		printf( "%c", ft_tolower(input[i]));
		i++;
	}
	return (0);
}
*/
