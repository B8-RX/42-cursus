/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:03:42 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/23 00:30:26 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(str + i) = (unsigned char)c;
		i++;
	}
	return (str);
}
/*

int	main(void) {

	int array [] = { 54, 85, 20, 63, 21 };
	size_t size = sizeof( int ) * 5;
	int length;

	// Display the initial values
	for( length=0; length<5; length++) {
		printf( "%d ", array[ length ] );
	}
	printf( "\n" );

	// Reset the memory bloc
	ft_memset( array, 0, size );

	// Display the new values
	for( length=0; length<5; length++) {
		printf( "%d ", array[ length ] );
	}
	printf( "\n" );

	return (0);
}
*/
