/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:19:38 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/18 22:50:35 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*res;

	res = s;
	while (n)
	{
		*res = 0;
		n--;
		res++;
	}
}

/*
int	main(void)
{
	char	arr[] = "12345";
	int		i;

	i = -1;
	while (++i < 5)
		printf("%c", arr[i]);
	printf("\n");
	i = -1;
	ft_bzero(arr, 3);
	while (++i < 5)
		printf("%c", arr[i]);
	return (0);
}
*/
