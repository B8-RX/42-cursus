/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:27:40 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/18 22:49:52 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*res;
	size_t			i;

	i = 0;
	source = (unsigned char *)src;
	res = (unsigned char *)dest;
	if (res > source)
		while (n-- > 0)
			res[n] = source[n];
	else
	{
		while (i < n)
		{
			res[i] = source[i];
			i++;
		}
	}
	return (res);
}
/*
#define ELEMENT_COUNT 10

int	main(void) {

	// On crée une zone de mémoire de 10 entiers et contenant
	// que neuf valeurs. La dixième est non utilisée (0).
	int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };

	// On affiche le contenu de la collection
	for( int i=0; i<ELEMENT_COUNT; i++ ) {
		printf( "%d ", data[i] );
	}
	puts( "" );  // Un retour à la ligne

	// On décale les éléménts dans la collection ...
	void * source = (void *) data;
	void * destination = (void *) ( data + 1 );
	size_t size = ELEMENT_COUNT * sizeof( int );
	ft_memmove( destination, source, size );

	// ... pour y insérer une nouvelle valeur en tête
	data[0] = 10;

	// On affiche le contenu de la collection
	for( int i=0; i<ELEMENT_COUNT; i++ ) {
		printf( "%d ", data[i] );
	}
	puts( "" );  // Un retour à la ligne

	return (EXIT_SUCCESS);
}
*/
