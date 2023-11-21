/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:29:14 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/18 22:54:03 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// int	main(void)
// {
// 	char str1[20] = "WayToLearnX";
// 	char str2[20] = {'W', 'W', 'W', 'W', 'a', 'y', 't', 'o', 'L', 'e', 'a', 'r',
// 		'n', 'X', '\0'};
// 	printf("Longueur de str1 = %lu \n", ft_strlen(str1));
// 	printf("Longueur de str2 = %lu \n", ft_strlen(str2));
// 	return (0);
// }
