/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:40:37 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/18 23:11:56 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char *));
	if (new == NULL)
		return (new);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}
/*
int	main(void)
{
	char	str1[10];
	char	str2[10];

	if (!*str1)
	{
		printf("Enter your first sentence:\n");
		fgets(str1, 10, stdin);
		if (str1[ft_strlen(str1) - 1] == '\n')
			str1[ft_strlen(str1) - 1] = '\0';
		printf("str1 = :%s\n", str1);
	}
	if (*str1 && !*str2)
	{
		printf("Enter your second sentence:\n");
		fgets(str2, 10, stdin);
		if (str2[ft_strlen(str2) - 1] == '\n')
			str2[ft_strlen(str2) - 1] = '\0';
		printf("str2 = :%s\n", str2);
	}
	if (*str1 && *str2)
		printf("result: |%s|\n", ft_strjoin(str1, str2));
	return (0);
}
*/
