/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:12:08 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/19 03:05:21 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && (n - 1))
	{
		s1++;
		s2++;
		n--;
	}
	if (*s1 != *s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}
/*
int	main(void)
{
	char s1[15];
	char s2[15];
	int ret;

	strcpy(s1, "abcdef");
	strcpy(s2, "ABCDEF");

	ret = ft_strncmp(s1, s2, 4);

	if (ret < 0)
	{
		printf("s1 is less than s2");
	}
	else if (ret > 0)
	{
		printf("s2 is less than s1");
	}
	else
	{
		printf("s1 is equal to s2");
	}

	return (0);
}*/
