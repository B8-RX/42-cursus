/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:51:39 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/19 04:14:37 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*res;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	res = (unsigned char *)s;
	while (i < n)
	{
		if (res[i] == (unsigned char)c)
		{
			return (res + i);
		}
		i++;
	}
	return (NULL);
}
/*

int	main(void) {

	char data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	const unsigned int size = 10;

	// On recherche une valeur inhéxistante :
	void * found = ft_memchr( data, 57, size );
	printf( "57 is %s\n", ( found != NULL ? "found" : "not found" ) );

	// On recherche une valeur existante :
	found = ft_memchr( data, 10, size );
	printf( "10 is %s\n", ( found != NULL ? "found" : "not found" ) );
	if ( found != NULL ) {
		printf( "La valeur à la position calculée est %d\n",
			*((char *) found) );
	}

	return (EXIT_SUCCESS);
}
*/
