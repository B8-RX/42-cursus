/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:03:08 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/19 01:02:01 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;

	if (!src)
		return (NULL);
	new = (char *)malloc((ft_strlen(src) / sizeof(char)) + 1);
	if (new == NULL)
		return (new);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
int	main(void)
{
	const char	*str = "I can handle it.";
	char		*copy;

	copy = ft_strdup(str);
	while (*copy)
	{
		printf("%c", *copy);
		copy++;
	}
	return (0);
}
*/
