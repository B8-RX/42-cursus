/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:00:24 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/18 22:49:15 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*res;
	unsigned char	*source;
	int				i;

	i = 0;
	res = (unsigned char *)dest;
	source = (unsigned char *)src;
	while (n > 0)
	{
		res[i] = source[i];
		i++;
		n--;
	}
	return (res);
}

/*
int	main(void) {

	int array [] = { 54, 85, 20, 63, 21 };
	int * copy = NULL;
	int length = sizeof( int ) * 5;

	// Memory allocation and copy
	copy = (int *) malloc( length );
	ft_memcpy( copy, array, length );

	// Display the copied values
	for( length=0; length<5; length++ ) {
		printf( "%d ", copy[ length ] );
	}
	printf( "\n" );

	free( copy );

	return (EXIT_SUCCESS);
}
*/
