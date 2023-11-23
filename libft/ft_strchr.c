/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:45:58 by ssghioua          #+#    #+#             */
/*   Updated: 2023/11/23 02:39:51 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
/*
int	main(void)
{
//	int	test = 't' + 256;
//	printf("result d: %d\n", test );
//	printf("result  c: %c\n", test );
	const char	str[] = "https://www.tutorialspoint.com";
	const char	ch = '.';
	char		*ret;
	char		*ret2;

	ret = ft_strchr(str, ch);
	ret2 = strchr(str, ch);
	printf("String after |%c| is ==> |%s|\n", ch, ret);
	printf("Original String after |%c| is ==> |%s|\n", ch, ret2);
	return (0);
}
*/
