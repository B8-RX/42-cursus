/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:57:35 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/19 01:32:06 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (!dst || !src)
		return (0);
	if (size && i < size - 1)
	{
		while (src[j] && (i + j < size - 1))
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	if (i >= size)
		i = size;
	return (i + ft_strlen(src));
}
/*
int	main(void)
{
	const char	str[] = "test";
	char		buff2[] = "test";
	int			i;

	printf("result: %zu\n", ft_strlcat(buff2, str, 8));
	i = 0;
	while(buff2[i])
	{
		printf("%c", buff2[i]);
		i++;
	}
	return (0);
}
*/
