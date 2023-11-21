/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:29:42 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/21 23:57:13 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_s2;

	len_s2 = (size_t)ft_strlen(s2);
	if (!len_s2)
		return ((char *)s1);
	i = 0;
	j = 0;
	if ((int)len < 0)
		len = ft_strlen(s1);

	while (s1[i] && len && i <= len - 1)
	{
//		printf("a\n");
		while (s1[i + j] == s2[j] && s2[j] != '\0')
		{
//			printf("%zu\n", j);
			j++;
		}
//		printf("len s2 :%zu\n", len_s2);
		if (j == len_s2)
		{
//			printf("c\n");
			return ((char *)(s1 + i));
		}
		j = 0;
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
//	char	str1[] = "Foo Bar Baz";
//	char	str2[] = "Bar";
	char haystack[30] = "abcd";
//	char needle[10] = "aabc";


	printf("result: %s\n", ft_strnstr(haystack, "a", 1));
	return (0);
}
*/
