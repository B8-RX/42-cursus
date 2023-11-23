/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:00:33 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/23 00:08:21 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char n = 's';
// 	printf("test 1===> %d\n", ft_isdigit(n));
// 	printf("test 2 ===> %d", isdigit(n));
// 	return (0);
// }
