/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:20:38 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/18 22:52:59 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && *(unsigned char *)(pointer1
		+ i) == *(unsigned char *)(pointer2 + i))
		i++;
	if (i < size)
		return (*(unsigned char *)(pointer1 + i) - *(unsigned char *)(pointer2
				+ i));
	return (0);
}
/*
int	main(void) {

	int array1 [] = { 54, 85, 20, 63, 21 };
	int array2 [] = { 54, 85, 19, 63, 21 };
	size_t size = sizeof( int ) * 5;

	assert( memcmp( array1, array2, size) == ft_memcmp( array1, array2, size) );
	assert( memcmp( array1, array1, size) == ft_memcmp( array1, array1, size) );
	assert( memcmp( array2, array1, size) == ft_memcmp( array2, array1, size) );

	printf( "test ok:");

	return (0);
}
*/
