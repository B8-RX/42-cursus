/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 02:31:22 by ssghioua          #+#    #+#             */
/*   Updated: 2023/12/16 02:31:24 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	new = ft_calloc(sizeof(char), (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	return (new);
}

void	*ft_calloc(size_t nb, size_t n)
{
	void	*new;
	size_t	i;
	size_t	total;

	if (n && nb > (size_t)(-1) / n)
		return (NULL);
	total = nb * n;
	new = malloc(total);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < total)
	{
		((unsigned char *)new)[i] = 0;
		i++;
	}
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*new;
	size_t			len_s1;
	size_t			len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, len_s1 + 1);
	ft_strlcat(new, s2, len_s1 + len_s2 + 1);
	return (new);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	if (!dst || !src)
		return (0);
	len_src = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (i < (size) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;

	if (!dst && size == 0)
		return (0);
	len_dst = ft_strlen(dst);
	if (size && len_dst < size - 1)
	{
		i = 0;
		while ((len_dst + i < size - 1) && src[i])
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		dst[len_dst + i] = '\0';
	}
	if (len_dst >= size)
		return (size + ft_strlen(src));
	else
		return (len_dst + ft_strlen(src));
}
